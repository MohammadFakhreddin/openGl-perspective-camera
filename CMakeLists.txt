cmake_minimum_required(VERSION 3.14)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "")
    message(" [INFO] VCPKG CMAKE_TOOLCHAIN_FILE = ${CMAKE_TOOLCHAIN_FILE}")
else()
    message(" [INFO] USING DEFAULT CMAKE")
endif()  

set(PROJECT_NAME perspective_camera_open_gl)

project(perspective_camera_open_gl)

set(CMAKE_CXX_STANDARD 14)

FILE(GLOB_RECURSE USER_HEADER "src/.h")
FILE(GLOB_RECURSE USER_CPP "src/*.cpp")

set(APP_SOURCE)
set(APP_HEADER)

list(APPEND APP_SOURCE
   ${USER_CPP}
)

list(
    APPEND APP_HEADER
   ${USER_HEADER}
)

add_executable(${PROJECT_NAME} ${APP_HEADER} ${APP_SOURCE})

#list(APPEND CMAKE_PREFIX_PATH "lib/")
#set(GLUT_INCLUDE_DIRS "lib/freeglut_x86-windws")
#set(GAINPUT_INCLUDE_DIRS "lib/gainput_x86-windows")

include_directories( ${OPENGL_INCLUDE_DIRS} )
#include_directories( ${GLUT_INCLUDE_DIRS} )
#include_directories( ${GAINPUT_INCLUDE_DIRS} )

find_package(OpenGL REQUIRED)
#find_package(GLUT REQUIRED)
#find_package(GainPut REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

target_link_libraries( ${PROJECT_NAME} ${OPENGL_LIBRARIES}  )

#${GLUT_LIBRARIES} ${GAINPUT_LIBRARIES}