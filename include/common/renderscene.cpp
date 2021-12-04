//
// Created by mehak on 12/4/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <vector>

// Include GLEW
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "renderscene.h"

glm::mat4 ProjectionMatrixf = glm::perspective(glm::radians(90.0f), 5.0f / 3.0f, 0.1f, 100.0f);
// Camera matrix
glm::mat4 ViewMatrixf       = glm::lookAt(
        glm::vec3(0,60,55), // Camera is at (4,3,3), in World Space
        glm::vec3(0,0,0), // and looks at the origin
        glm::vec3(0,-1,0)  // Head is up (set to 0,-1,0 to look upside-down)
);

void renderFootballField(const GLuint &programID, const GLuint &LightID, const GLuint &ViewMatrixID, const GLuint &MatrixID, const GLuint &ModelMatrixID, const GLuint &Texture,const GLuint &TextureID, const GLuint &vertexbuffer, const GLuint &normalbuffer, const GLuint &uvbuffer, const GLuint &elementbuffer, std::vector<unsigned short> indices)
{
    // Use our shader
    glUseProgram(programID);

    glm::vec3 lightPos = glm::vec3(0, 0, 31);
    glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);
    glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE,
                       &ViewMatrixf[0][0]); // This one doesn't change between objects, so this can be done once for all objects that use "programID"

    glm::mat4 ModelMatrix1 = glm::mat4(1.0);
    glm::vec3 myScale(0.3f, 0.3f, 0.3f);
    glm::mat4 myScalingMatrix = glm::scale(glm::mat4(1.0), myScale);

    //glm::vec3 myRotationAxis(1.0f, 0.0f, 0.0f);
    //glm::mat4 myRotationMatrix = glm::rotate(myScalingMatrix, 45.0f, myRotationAxis);

    glm::mat4 MVP1 = ProjectionMatrixf * ViewMatrixf * myScalingMatrix;

    // Send our transformation to the currently bound shader,
    // in the "MVP" uniform
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP1[0][0]);
    glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMatrix1[0][0]);


    // Bind our texture in Texture Unit 0
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, Texture);
    // Set our "myTextureSampler" sampler to use Texture Unit 0
    glUniform1i(TextureID, 0);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
            0,                  // attribute
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void *) 0            // array buffer offset
    );

    // 2nd attribute buffer : UVs
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glVertexAttribPointer(
            1,                                // attribute
            2,                                // size
            GL_FLOAT,                         // type
            GL_FALSE,                         // normalized?
            0,                                // stride
            (void *) 0                          // array buffer offset
    );

    // 3rd attribute buffer : normals
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
    glVertexAttribPointer(
            2,                                // attribute
            3,                                // size
            GL_FLOAT,                         // type
            GL_FALSE,                         // normalized?
            0,                                // stride
            (void *) 0                          // array buffer offset
    );

    // Index buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);

    glMaterialf(GL_FRONT_AND_BACK, GL_COLOR_INDEXES, (0, 255, 0));
    // Draw the triangles !
    glDrawElements(
            GL_TRIANGLES,      // mode
            indices.size(),    // count
            GL_UNSIGNED_SHORT,   // type
            (void *) 0           // element array buffer offset
    );

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);

}

void renderASuzie(glm::vec3 pos, const GLuint &programID, const GLuint &LightID, const GLuint &ViewMatrixID, const GLuint &MatrixID, const GLuint &ModelMatrixID, const GLuint &Texture,const GLuint &TextureID, const GLuint &vertexbuffer, const GLuint &normalbuffer, const GLuint &uvbuffer, const GLuint &elementbuffer, std::vector<unsigned short> indices)
{

    // Use our shader
    glUseProgram(programID);

    glm::vec3 lightPos = glm::vec3(0, 0, 31);
    glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);
    glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE,
                       &ViewMatrixf[0][0]); // This one doesn't change between objects, so this can be done once for all objects that use "programID"

    glm::mat4 ModelMatrix1 = glm::mat4(1.0);
    glm::mat4 myTranslationMatrix = glm::translate(ModelMatrix1, pos);
    glm::vec3 myScale(2.0f, 2.0f, 2.0f);
    glm::mat4 myScalingMatrix = glm::scale(myTranslationMatrix, myScale);

    //glm::vec3 myRotationAxis(1.0f, 0.0f, 0.0f);
    //glm::mat4 myRotationMatrix = glm::rotate(myScalingMatrix, 45.0f, myRotationAxis);
    glm::mat4 MVP1 = ProjectionMatrixf * ViewMatrixf * myScalingMatrix;

    // Send our transformation to the currently bound shader,
    // in the "MVP" uniform
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP1[0][0]);
    glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMatrix1[0][0]);


    // Bind our texture in Texture Unit 0
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, Texture);
    // Set our "myTextureSampler" sampler to use Texture Unit 0
    glUniform1i(TextureID, 0);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
            0,                  // attribute
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void *) 0            // array buffer offset
    );

    // 2nd attribute buffer : UVs
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glVertexAttribPointer(
            1,                                // attribute
            2,                                // size
            GL_FLOAT,                         // type
            GL_FALSE,                         // normalized?
            0,                                // stride
            (void *) 0                          // array buffer offset
    );

    // 3rd attribute buffer : normals
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
    glVertexAttribPointer(
            2,                                // attribute
            3,                                // size
            GL_FLOAT,                         // type
            GL_FALSE,                         // normalized?
            0,                                // stride
            (void *) 0                          // array buffer offset
    );

    // Index buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);


    // Draw the triangles !
    glDrawElements(
            GL_TRIANGLES,      // mode
            indices.size(),    // count
            GL_UNSIGNED_SHORT,   // type
            (void *) 0           // element array buffer offset
    );

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);

}

void drawSphere(glm::vec3 pos, const GLuint &programID, const GLuint &LightID, const GLuint &ViewMatrixID, const GLuint &MatrixID, const GLuint &ModelMatrixID, const GLuint &vertexbuffer, const GLuint &normalbuffer, const GLuint &uvbuffer, const GLuint &elementbuffer, std::vector<unsigned short> indices)
{

    // Use our shader
    glUseProgram(programID);

    glm::vec3 lightPos = glm::vec3(0, 0, 31);
    glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);
    glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE,
                       &ViewMatrixf[0][0]); // This one doesn't change between objects, so this can be done once for all objects that use "programID"

    glm::mat4 ModelMatrix1 = glm::mat4(1.0);
    glm::mat4 myTranslationMatrix = glm::translate(ModelMatrix1, pos);
    glm::vec3 myScale(2.0f, 2.0f, 2.0f);
    glm::mat4 myScalingMatrix = glm::scale(myTranslationMatrix, myScale);

    //glm::vec3 myRotationAxis(1.0f, 0.0f, 0.0f);
    //glm::mat4 myRotationMatrix = glm::rotate(myScalingMatrix, 45.0f, myRotationAxis);
    glm::mat4 MVP1 = ProjectionMatrixf * ViewMatrixf * myScalingMatrix;

    // Send our transformation to the currently bound shader,
    // in the "MVP" uniform
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP1[0][0]);
    glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMatrix1[0][0]);


    // Bind our texture in Texture Unit 0
    //glActiveTexture(GL_TEXTURE0);
    //glBindTexture(GL_TEXTURE_2D, Texture);
    // Set our "myTextureSampler" sampler to use Texture Unit 0
    //glUniform1i(TextureID, 0);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
            0,                  // attribute
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void *) 0            // array buffer offset
    );

    // 2nd attribute buffer : UVs
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glVertexAttribPointer(
            1,                                // attribute
            2,                                // size
            GL_FLOAT,                         // type
            GL_FALSE,                         // normalized?
            0,                                // stride
            (void *) 0                          // array buffer offset
    );

    // 3rd attribute buffer : normals
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
    glVertexAttribPointer(
            2,                                // attribute
            3,                                // size
            GL_FLOAT,                         // type
            GL_FALSE,                         // normalized?
            0,                                // stride
            (void *) 0                          // array buffer offset
    );

    // Index buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);


    // Draw the triangles !
    glDrawElements(
            GL_TRIANGLES,      // mode
            indices.size(),    // count
            GL_UNSIGNED_SHORT,   // type
            (void *) 0           // element array buffer offset
    );

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);

}
