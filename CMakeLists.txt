cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME perspective_camera_open_gl)

project(perspective_camera_open_gl)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} src/main.cpp src/Constants.h)

include_directories( ${OPENGL_INCLUDE_DIRS} )

if(!WIN32)
include_directories( ${GLUT_INCLUDE_DIRS} )
endif (!WIN32)

find_package(OpenGL REQUIRED)

if(!WIN32)

find_package(GLUT REQUIRED)

endif (!WIN32)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

target_link_libraries( ${PROJECT_NAME} ${OPENGL_LIBRARIES} )