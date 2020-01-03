cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME perspective_camera_open_gl)

project(perspective_camera_open_gl)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} src/main.cpp src/Constants.h)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${SFML_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(SFML 2.5 COMPONENTS REQUIRED network audio graphics window system)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} sfml-graphics sfml-window sfml-audio sfml-network sfml-system sfml-network)