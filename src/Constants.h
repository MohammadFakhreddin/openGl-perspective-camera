//
// Created by mohammad.fakhreddin on 1/3/20.
//

#ifndef PERSPECTIVE_CAMERA_OPEN_GL_CONSTANTS_H
#define PERSPECTIVE_CAMERA_OPEN_GL_CONSTANTS_H

#endif //PERSPECTIVE_CAMERA_OPEN_GL_CONSTANTS_H


namespace Constants {
    namespace Window{
        static constexpr char appName[] = "Perspective camera";
        static constexpr int screenWidth = 800;
        static constexpr int screenHeight = 600;
    }
    namespace System{
        unsigned int RealScreenWidth = 0;
        unsigned int RealScreenHeight = 0;
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
        //define something for Windows (32-bit and 64-bit, this part is common)
   #ifdef _WIN64
      //define something for Windows (64-bit only)
   #else
      //define something for Windows (32-bit only)
   #endif
        #if !defined(__DESKTOP__)
        #define __DESKTOP__
        #endif
#elif __APPLE__
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
        // iOS Simulator
        // iOS device
        #if !defined(__MOBILE__)
        #define __MOBILE__
        #endif
        #if !defined(__IOS__)
        #define __IOS__
        #endif
#elif TARGET_OS_MAC
        // Other kinds of Mac OS
        #if !defined(__DESKTOP__)
        #define __DESKTOP__
        #endif
#else
#   error "Unknown Apple platform"
#endif
#elif __linux__
        // linux
        #if !defined(__DESKTOP__)
        #define __DESKTOP__
        #endif
#elif __unix__ // all unices not caught above
    // Unix
#elif defined(_POSIX_VERSION)
    // POSIX
#elif __ANDROID__
        #if !defined(__MOBILE__)
        #define __MOBILE__
        #endif
#else
#   error "Unknown compiler"
#endif
    }
}