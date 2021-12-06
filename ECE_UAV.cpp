//
// Created by mehak on 12/6/2021.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <thread>
#include <chrono>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "ECE_UAV.h"
#define PI 3.14159265

const double normalX = (22.8/23.5);
const double normalY = (24.4/22.4);
const double normaldist = 100;

//Euclidean Distance between two vectors
double distance(glm::vec3 p1, glm::vec3 p2)
{
    glm::vec3 d;
    d.x = std::abs(p1.x - p2.x);
    d.y = std::abs(p1.y - p2.y);
    d.z = std::abs(p1.z - p2.z);

    double dist = std::sqrt(std::pow(d.x, 2) + std::pow(d.y, 2) + std::pow(d.z, 2));

    return dist;
}

//Direction vector form point 2 to point 1
glm::vec3 subtract(glm::vec3 p1, glm::vec3 p2)
{
    glm::vec3 d;
    d.x = p1.x - p2.x;
    d.y = p1.y - p2.y;
    d.z = p1.z - p2.z;
    return d;
}

ECE_UAV::ECE_UAV() :thread()
{
    position = glm::vec3 (0.0f,0.0f,0.0f);
    velocity = glm::vec3 (0.0f,0.0f,0.0f);
    directionVector = glm::vec3 (0.0f,0.0f,0.0f);
    tangentVector = glm::vec3 (0.0f,0.0f,0.0f);
    mass = 1;
    acceleration = glm::vec3 (0.0f,0.0f,0.0f);
    pos = -1;
    circularMotion = false;
    startFlying = false;
}

/*
void ECE_UAV::start()
{
    this->thread = std::thread(&threadFunction, this);
}

void threadFunction(ECE_UAV &pUAV)
{
    pUAV.updatePosition(0.01, 10,1 );
    std::this_thread::sleep_for(std::chrono::milliseconds(30));
}
*/
bool ECE_UAV::getCircularStart()
{
    return this->circularMotion;
}

void ECE_UAV::setCircularTime(double time)
{
    this->circularStart = time;
}


void ECE_UAV::setFlight()
{
    this->startFlying = true;
}

glm::vec3 ECE_UAV::getPosition()
{
    return this->position;
}

glm::vec3 ECE_UAV::getVelocity()
{
    return this->velocity;
}

void ECE_UAV::setPosition(glm::vec3 pos)
{
    this->position = pos;
}

void ECE_UAV::setVelocity(glm::vec3 vel)
{
    this->velocity = vel;
}

void ECE_UAV::initPos(int i)
{
    glm::vec3 posSuzie;
    if(i < 5)
    {
        posSuzie = glm::vec3(45.72f - i*23.5f, 24.4f, 0.0f);
    }
    else if( i < 10)
    {
        posSuzie = glm::vec3(45.72f - (i-5)*23.5f, -24.4f, 0.0f);
    }
    else
    {
        posSuzie = glm::vec3(45.72f - (i-10)*23.5f, 0.0f, 0.0f);
    }

    this->position = posSuzie;
    this->pos = i;

    updateVectors();
}


void ECE_UAV::updateVectors()
{
    /// Function to find the direction vector - points from the uav to the center of the sphere
    /// and to find a random normal vector to the direction vector

    glm::vec3 posSuzie = this->position;
    glm::vec3 target = glm::vec3(0,0,50);
    glm::vec3 directionVector = subtract(target, posSuzie);
    double distFromTarget = distance(target, posSuzie);
    directionVector.x = directionVector.x / distFromTarget;
    directionVector.y = directionVector.y / distFromTarget;
    directionVector.z = directionVector.z / distFromTarget;

    this->directionVector = directionVector;


    std::srand(time(0)*this->pos);
    glm::vec3 v = glm::vec3(std::rand() % 11, std::rand() % 11 , std::rand() % 11 );
    glm::vec3 vv = subtract(v, posSuzie);
    double distFromV = distance(v, posSuzie);

    vv.x /= distFromV;
    vv.y /= distFromV;
    vv.z /= distFromV;

    //Take cross product with v
    glm::vec3 tangentVector;
    tangentVector.x = vv.y * directionVector.z - vv.z * directionVector.y;
    tangentVector.y = vv.z * directionVector.x - vv.x * directionVector.z;
    tangentVector.z = vv.x * directionVector.y - vv.y * directionVector.x;

    if (tangentVector.x == 0.0 && tangentVector.y == 0.0 && tangentVector.z == 0.0)
    {
        vv.x = vv.x + 1;
        tangentVector.x = vv.y * directionVector.z - vv.z * directionVector.y;
        tangentVector.y = vv.z * directionVector.x - vv.x * directionVector.z;
        tangentVector.z = vv.x * directionVector.y - vv.y * directionVector.x;
    }

    double tMag = distance(tangentVector, glm::vec3 (0.0f, 0.0f, 0.0f));
    this->tangentVector.x = tangentVector.x/tMag;
    this->tangentVector.y = tangentVector.y/tMag;
    this->tangentVector.z = tangentVector.z/tMag;
}


void ECE_UAV::updatePosition(double delta, double distanceThreshold, double currentTime)
{

    /// Function that updates positions of uavs while moving

    glm::vec3 curPos = this->position;
    glm::vec3 target = glm::vec3(0,0,50);
    double distFromTarget = distance(target, curPos);

    double fMax = 20.0;
    double k = 10;
    glm::vec3  force;
    glm::vec3 newVel;
    glm::vec3 newPos;

    if(this->startFlying)
    {

        if (distFromTarget >= distanceThreshold and not circularMotion)
        {

            double vMax = 2.0;

            double phi = std::atan2(std::sqrt(std::pow(directionVector.x, 2) + std::pow(directionVector.y, 2)),
                                    directionVector.z);
            //Let angle between x and y component be theta and angle between z and xy direction vector be phi
            force.x = this->directionVector.x * (fMax - 10 / cos(phi));
            force.y = this->directionVector.y * (fMax - 10 / cos(phi));
            force.z = this->directionVector.z * (fMax - 10 / cos(phi));
            //Get acceleration from force vector
            this->acceleration.x = force.x / this->mass;
            this->acceleration.y = force.y / this->mass;
            this->acceleration.z = force.z / this->mass;

            //Get New Velocity
            newVel = glm::vec3(this->velocity.x + this->acceleration.x * delta,
                               this->velocity.y + this->acceleration.y * delta,
                               this->velocity.z + this->acceleration.z * delta);

            double vMag = distance(newVel, glm::vec3(0.0f, 0.0f, 0.0f));

            if (vMag > vMax) {

                newVel.x = (newVel.x / vMag) * 2;
                newVel.y = (newVel.y / vMag) * 2;
                newVel.z = (newVel.z / vMag) * 2;

                this->acceleration = subtract(newVel, this->velocity);
                this->acceleration.x /= delta;
                this->acceleration.y /= delta;
                this->acceleration.z /= delta;
            }
            newPos = glm::vec3(
                    ((curPos.x / normalX) + this->velocity.x * delta + 0.5 * this->acceleration.x * delta * delta) *
                    normalX,
                    ((curPos.y / normalY) + this->velocity.y * delta + 0.5 * this->acceleration.y * delta * delta) *
                    normalY,
                    ((curPos.z) + this->velocity.z * delta + 0.5 * this->acceleration.z * delta * delta));
        }
        else
        {
            if (not circularMotion) {
                circularMotion = true;
                circularStart = currentTime;
                updateVectors();
                this->velocity.x = 10 * this->tangentVector.x;
                this->velocity.y = 10 * this->tangentVector.y;
                this->velocity.z = 10 * this->tangentVector.z;

            }

            glm::vec3 posSuzie = this->position;
            glm::vec3 target = glm::vec3(0, 0, 50);
            glm::vec3 directionVector = subtract(target, posSuzie);
            double distFromTarget = distance(target, posSuzie);
            directionVector.x = -1 * directionVector.x / distFromTarget;
            directionVector.y = -1 * directionVector.y / distFromTarget;
            directionVector.z = -1 * directionVector.z / distFromTarget;

            this->directionVector = directionVector;

            double vMax = 10.0;
            double vMin = 2.0;
            double fSpring = k * (10 - distFromTarget);

            //Get acceleration from force vector
            this->acceleration.x = fSpring * this->directionVector.x / this->mass;
            this->acceleration.y = fSpring * this->directionVector.y / this->mass;
            this->acceleration.z = fSpring * this->directionVector.z / this->mass;

            //Get New Velocity
            newVel = glm::vec3(this->velocity.x + this->acceleration.x * delta,
                               this->velocity.y + this->acceleration.y * delta,
                               this->velocity.z + this->acceleration.z * delta);

            double vMag = distance(newVel, glm::vec3(0.0f, 0.0f, 0.0f));

            this->tangentVector.x = this->velocity.x;
            this->tangentVector.x = this->velocity.x;
            this->tangentVector.x = this->velocity.x;

            if (vMag > vMax) {

                newVel.x = (newVel.x / vMag) * 10;
                newVel.y = (newVel.y / vMag) * 10;
                newVel.z = (newVel.z / vMag) * 10;

                this->acceleration = subtract(newVel, this->velocity);
                this->acceleration.x /= delta;
                this->acceleration.y /= delta;
                this->acceleration.z /= delta;
            } else if (vMag < vMin) {

                newVel.x = (newVel.x / vMag) * 2;
                newVel.y = (newVel.y / vMag) * 2;
                newVel.z = (newVel.z / vMag) * 2;

                this->acceleration = subtract(newVel, this->velocity);
                this->acceleration.x /= delta;
                this->acceleration.y /= delta;
                this->acceleration.z /= delta;
            }

            newPos = glm::vec3(
                    ((curPos.x / normalX) + this->velocity.x * delta + 0.5 * this->acceleration.x * delta * delta) *
                    normalX,
                    ((curPos.y / normalY) + this->velocity.y * delta + 0.5 * this->acceleration.y * delta * delta) *
                    normalY,
                    ((curPos.z) + this->velocity.z * delta + 0.5 * this->acceleration.z * delta * delta));

        }

        this->velocity = newVel;
        this->position.x = newPos.x;
        this->position.y = newPos.y;
        this->position.z = newPos.z;
    }
}

bool ECE_UAV::flySixty(double time)
{
    ///Checks if the uav has been in circular motion for 60 seconds
    if(circularMotion && (time - circularStart) >= 60)
        return true;
    else
        return false;
}



void doIfCollide(ECE_UAV &object1, ECE_UAV &object2)
{
    /// Set velocity to the other uav's velocity and move the uavs double their current distance apart
    glm::vec3 vel1 = object1.getVelocity();
    glm::vec3 vel2 = object2.getVelocity();
    object1.setVelocity(vel2);
    object2.setVelocity(vel1);

    glm::vec3 pos1 = object1.getPosition();
    glm::vec3 pos2 = object2.getPosition();
    double vmag1 = distance(vel1, glm::vec3(0,0,0));
    double vmag2 = distance(vel2, glm::vec3(0,0,0));
    double dist = distance(pos2, pos2)*2;

    glm::vec3 newPos1 = glm::vec3(pos1.x + (vel2.x/vmag2)*dist , pos1.y + (vel2.y/vmag2)*dist , pos1.z + (vel2.z/vmag2)*dist);
    glm::vec3 newPos2 = glm::vec3(pos2.x + (vel1.x/vmag1)*dist , pos2.y + (vel1.y/vmag1)*dist , pos2.z + (vel1.z/vmag1)*dist);


    object1.setPosition(newPos1);
    object2.setPosition(newPos2);
}


int elasticCollision(ECE_UAV *uavs, int num)
{

    /// Find the closest uav and check whther its 0.01 m apart

    glm::vec3 pos = uavs[num].getPosition();
    pos.x = pos.x / normalX;
    pos.y = pos.y / normalY;

    // then we find the cloeset uav, default is -1, meaning that closest uav is farther than threshold
    int closestUav = -1;

    // set default dist to infinity
    double dist = std::numeric_limits<double>::max();

    // use a for loop to traverse all uavs
    for (int i = 0; i < 15; i++)
    {
        if (i == num)
        {
            // skip itself
            continue;
        }

        // calculate distance
        glm::vec3 pos2 = uavs[i].getPosition();
        pos2.x = pos2.x / normalX;
        pos2.y = pos2.y / normalY;
        double tmpDist = distance(pos2, pos);
        if (tmpDist <= dist)
        {
            // if closer than the distance ever found so far and closer than the threshold
            // update the closest uav
            closestUav = i;
            dist = tmpDist;
        }
    }



    if (dist <= 0.01*normaldist)
    {
        std::cout<<"Distance : "<<dist<<std::endl;
        return closestUav;
    }
    else
    {
        return -1;
    }
}
