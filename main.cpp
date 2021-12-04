// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <vector>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include <common/shader.hpp>
#include <common/texture.hpp>
#include <common/controls.hpp>
#include <common/objloader.hpp>
#include <common/vboindexer.hpp>
#include "common/renderscene.h"


int main( void )
{
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        getchar();
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    window = glfwCreateWindow( 1920, 1080, "Final Project", NULL, NULL);
    if( window == NULL ){
        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    // Hide the mouse and enable unlimited mouvement
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Set the mouse at the center of the screen
    glfwPollEvents();
    //glfwSetCursorPos(window, 1024/2, 768/2);

    // Black background
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    // Cull triangles which normal is not towards the camera
    glEnable(GL_CULL_FACE);

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    // Create and compile our GLSL program from the shaders
    GLuint programID = LoadShaders( "StandardShading.vertexshader", "StandardShading.fragmentshader" );

    // Get a handle for our "MVP" uniform
    GLuint MatrixID = glGetUniformLocation(programID, "MVP");
    GLuint ViewMatrixID = glGetUniformLocation(programID, "V");
    GLuint ModelMatrixID = glGetUniformLocation(programID, "M");

    // Load the textures
    GLuint Texture = loadBMP_custom("footballfield.bmp");
    GLuint textureSuzie = loadDDS("uvmap.DDS");

    // Get a handle for our "myTextureSampler" uniform
    GLuint TextureID  = glGetUniformLocation(programID, "myTextureSampler");

    //// Football Field ////

    // Read our .obj file
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;
    bool res = loadOBJ("footballfield.obj", vertices, uvs, normals);

    std::vector<unsigned short> indices;
    std::vector<glm::vec3> indexed_vertices;
    std::vector<glm::vec2> indexed_uvs;
    std::vector<glm::vec3> indexed_normals;
    indexVBO(vertices, uvs, normals, indices, indexed_vertices, indexed_uvs, indexed_normals);

    // Load it into a VBO
    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, indexed_vertices.size() * sizeof(glm::vec3), &indexed_vertices[0], GL_STATIC_DRAW);

    GLuint uvbuffer;
    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, indexed_uvs.size() * sizeof(glm::vec2), &indexed_uvs[0], GL_STATIC_DRAW);

    GLuint normalbuffer;
    glGenBuffers(1, &normalbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
    glBufferData(GL_ARRAY_BUFFER, indexed_normals.size() * sizeof(glm::vec3), &indexed_normals[0], GL_STATIC_DRAW);

    // Generate a buffer for the indices as well
    GLuint elementbuffer;
    glGenBuffers(1, &elementbuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned short), &indices[0] , GL_STATIC_DRAW);

    ////Suzie ////

    // Read our .obj file
    std::vector<glm::vec3> verticesSuzie;
    std::vector<glm::vec2> uvsSuzie;
    std::vector<glm::vec3> normalsSuzie;
    bool resSuzie = loadOBJ("suzanne.obj", verticesSuzie, uvsSuzie, normalsSuzie);

    std::vector<unsigned short> indicesSuzie;
    std::vector<glm::vec3> indexed_verticesSuzie;
    std::vector<glm::vec2> indexed_uvsSuzie;
    std::vector<glm::vec3> indexed_normalsSuzie;
    indexVBO(verticesSuzie, uvsSuzie, normalsSuzie, indicesSuzie, indexed_verticesSuzie, indexed_uvsSuzie, indexed_normalsSuzie);

    // Load it into a VBO
    GLuint vertexbufferSuzie;
    glGenBuffers(1, &vertexbufferSuzie);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferSuzie);
    glBufferData(GL_ARRAY_BUFFER, indexed_verticesSuzie.size() * sizeof(glm::vec3), &indexed_verticesSuzie[0], GL_STATIC_DRAW);

    GLuint uvbufferSuzie;
    glGenBuffers(1, &uvbufferSuzie);
    glBindBuffer(GL_ARRAY_BUFFER, uvbufferSuzie);
    glBufferData(GL_ARRAY_BUFFER, indexed_uvsSuzie.size() * sizeof(glm::vec2), &indexed_uvsSuzie[0], GL_STATIC_DRAW);

    GLuint normalbufferSuzie;
    glGenBuffers(1, &normalbufferSuzie);
    glBindBuffer(GL_ARRAY_BUFFER, normalbufferSuzie);
    glBufferData(GL_ARRAY_BUFFER, indexed_normalsSuzie.size() * sizeof(glm::vec3), &indexed_normalsSuzie[0], GL_STATIC_DRAW);

    // Generate a buffer for the indices as well
    GLuint elementbufferSuzie;
    glGenBuffers(1, &elementbufferSuzie);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbufferSuzie);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSuzie.size() * sizeof(unsigned short), &indicesSuzie[0] , GL_STATIC_DRAW);

    // Get a handle for our "LightPosition" uniform
    glUseProgram(programID);
    GLuint LightID = glGetUniformLocation(programID, "LightPosition_worldspace");

    //// Sphere ////

    // Create and compile our GLSL program from the shaders
    GLuint programIDSphere = LoadShaders( "StandardShading.vertexshader", "SingleColor.fragmentshader" );

    // Get a handle for our "MVP" uniform
    GLuint MatrixIDSphere = glGetUniformLocation(programIDSphere, "MVP");
    GLuint ViewMatrixIDSphere = glGetUniformLocation(programIDSphere, "V");
    GLuint ModelMatrixIDSphere = glGetUniformLocation(programIDSphere, "M");

    // Read our .obj file
    std::vector<glm::vec3> verticesSphere;
    std::vector<glm::vec2> uvsSphere;
    std::vector<glm::vec3> normalsSphere;
    bool resSphere = loadOBJ("webtrcc.obj", verticesSphere, uvsSphere, normalsSphere);

    std::vector<unsigned short> indicesSphere;
    std::vector<glm::vec3> indexed_verticesSphere;
    std::vector<glm::vec2> indexed_uvsSphere;
    std::vector<glm::vec3> indexed_normalsSphere;
    indexVBO(verticesSphere, uvsSphere, normalsSphere, indicesSphere, indexed_verticesSphere, indexed_uvsSphere, indexed_normalsSphere);

    // Load it into a VBO
    GLuint vertexbufferSphere;
    glGenBuffers(1, &vertexbufferSphere);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferSphere);
    glBufferData(GL_ARRAY_BUFFER, indexed_verticesSphere.size() * sizeof(glm::vec3), &indexed_verticesSphere[0], GL_STATIC_DRAW);

    GLuint uvbufferSphere;
    glGenBuffers(1, &uvbufferSphere);
    glBindBuffer(GL_ARRAY_BUFFER, uvbufferSphere);
    glBufferData(GL_ARRAY_BUFFER, indexed_uvsSphere.size() * sizeof(glm::vec2), &indexed_uvsSphere[0], GL_STATIC_DRAW);

    GLuint normalbufferSphere;
    glGenBuffers(1, &normalbufferSphere);
    glBindBuffer(GL_ARRAY_BUFFER, normalbufferSphere);
    glBufferData(GL_ARRAY_BUFFER, indexed_normalsSphere.size() * sizeof(glm::vec3), &indexed_normalsSphere[0], GL_STATIC_DRAW);

    // Generate a buffer for the indices as well
    GLuint elementbufferSphere;
    glGenBuffers(1, &elementbufferSphere);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbufferSphere);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSphere.size() * sizeof(unsigned short), &indicesSphere[0] , GL_STATIC_DRAW);

    glm::vec3 posSphere = glm::vec3(0.0f, 0.0f, 50.0f);

    // For speed computation
    double lastTime = glfwGetTime();
    int nbFrames = 0;


    do{

        // Measure speed
        double currentTime = glfwGetTime();
        nbFrames++;

        if(currentTime - lastTime >= 5){
            printf("Start Flying");
        }

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        // Compute the MVP matrix from keyboard and mouse input
        //computeMatricesFromInputs();
        //glm::mat4 ProjectionMatrix = getProjectionMatrix();
        //glm::mat4 ViewMatrix = getViewMatrix();

        renderFootballField(programID, LightID, ViewMatrixID, MatrixID, ModelMatrixID, Texture, TextureID, vertexbuffer, normalbuffer, uvbuffer, elementbuffer, indices);
        drawSphere(posSphere, programIDSphere, LightID, ViewMatrixIDSphere, MatrixIDSphere, ModelMatrixIDSphere, vertexbufferSphere, normalbufferSphere, uvbufferSphere, elementbufferSphere, indicesSphere);
        for (int i =0 ; i<15; i++)
        {
            if(i < 5)
            {
                glm::vec3 posSuzie = glm::vec3(39.0f - i*20.0f, 20.0f, 0.0f);
                renderASuzie(posSuzie, programID, LightID, ViewMatrixID, MatrixID, ModelMatrixID, textureSuzie, TextureID, vertexbufferSuzie, normalbufferSuzie, uvbufferSuzie, elementbufferSuzie, indicesSuzie);
            }
            else if( i < 10)
            {
                glm::vec3 posSuzie = glm::vec3(39.0f - (i-5)*20.0f, -20.0f, 0.0f);
                renderASuzie(posSuzie, programID, LightID, ViewMatrixID, MatrixID, ModelMatrixID, textureSuzie, TextureID, vertexbufferSuzie, normalbufferSuzie, uvbufferSuzie, elementbufferSuzie, indicesSuzie);
            }
            else
            {
                glm::vec3 posSuzie = glm::vec3(39.0f - (i-10)*20.0f, 0.0f, 0.0f);
                renderASuzie(posSuzie, programID, LightID, ViewMatrixID, MatrixID, ModelMatrixID, textureSuzie, TextureID, vertexbufferSuzie, normalbufferSuzie, uvbufferSuzie, elementbufferSuzie, indicesSuzie);
            }

        }


        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

    // Cleanup VBO and shader
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &uvbuffer);
    glDeleteBuffers(1, &normalbuffer);
    glDeleteBuffers(1, &elementbuffer);

    glDeleteBuffers(1, &vertexbufferSuzie);
    glDeleteBuffers(1, &uvbufferSuzie);
    glDeleteBuffers(1, &normalbufferSuzie);
    glDeleteBuffers(1, &elementbufferSuzie);

    glDeleteBuffers(1, &vertexbufferSphere);
    glDeleteBuffers(1, &uvbufferSphere);
    glDeleteBuffers(1, &normalbufferSphere);
    glDeleteBuffers(1, &elementbufferSphere);
    glDeleteProgram(programIDSphere);

    glDeleteProgram(programID);
    glDeleteTextures(1, &Texture);
    glDeleteTextures(1, &textureSuzie);
    glDeleteVertexArrays(1, &VertexArrayID);

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}

