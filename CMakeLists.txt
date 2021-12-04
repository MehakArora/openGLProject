cmake_minimum_required(VERSION 3.20)
project(openGLProject)

set(CMAKE_CXX_STANDARD 14)
add_executable(openGLProject main.cpp
        common/shader.cpp
        common/shader.hpp
        common/controls.cpp
        common/controls.hpp
        common/texture.cpp
        common/texture.hpp
        common/objloader.cpp
        common/objloader.hpp
        common/vboindexer.cpp
        common/vboindexer.hpp
        include/common/renderscene.cpp
        include/common/renderscene.h
        )
add_definitions(-DGLEW_STATIC)

include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${PROJECT_SOURCE_DIR}/lib-mingw)
target_link_libraries(openGLProject glfw3 gdi32 glew32)

find_package(OpenGL REQUIRED )

#These 3 lines are just linking and making executables
target_link_libraries(openGLProject opengl32) #linking the libraries to the project file

set(glm_DIR "${PROJECT_SOURCE_DIR}/glm/cmake/glm")
#set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(glm REQUIRED)
target_link_libraries(openGLProject glm::glm)