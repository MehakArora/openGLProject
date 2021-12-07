//
// Created by mehak on 12/6/2021.
//

#pragma once
#include <thread>
#include <atomic>

#ifndef OPENGLPROJECT_ECE_UAV_H
#define OPENGLPROJECT_ECE_UAV_H

//Euclidean Distance between two vectors
double distance(glm::vec3 p1, glm::vec3 p2);

//Direction vector form point 2 to point 1
glm::vec3 subtract(glm::vec3 p1, glm::vec3 p2);

class ECE_UAV
{
private:

    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    glm::vec3 directionVector; //points from uav to target
    glm::vec3 tangentVector; //a normal vector to the current direction vector
    int pos;
    double mass;
    bool circularMotion;
    double circularStart;
    std::thread thread;
    std::atomic<bool> startFlying;
    std::atomic<bool> allDone;

    //Function that finds the vector pointing from uav position to the center of the sphere and a random vector normal to this direction vector
    void updateVectors();

public:

    void printt()
    {
        std::cout << this->thread.get_id() <<std::endl;
    }
    //Constructor function
    ECE_UAV ();

    glm::vec3 getPosition();

    glm::vec3 getVelocity();

    void setPosition(glm::vec3 pos);

    void setVelocity(glm::vec3 vel);

    void setFlight();

    void setAllDone();

    bool getAllDone();

    bool getCircularStart();

    void setCircularTime(double time);

    //Sets the initial position of the uavs on the football field
    void initPos(int i);

    //Update position vector to simulate the motion of uavs
    void updatePosition(double delta, double distanceThreshold);

    //Checks if the uav has been in circular motion for 60 seconds
    bool flySixty(double time);

    //Starts the thread function
    void start();

};

//Function to exchange velocities and set uavs some distance apart after collision is detected
void doIfCollide(ECE_UAV &object1, ECE_UAV &object2);

//Function to detect elastic collision
int elasticCollision(ECE_UAV *uavs, int num);

//Function that the thread object runs
void threadFunction(ECE_UAV* pUAV);

#endif //OPENGLPROJECT_ECE_UAV_H

