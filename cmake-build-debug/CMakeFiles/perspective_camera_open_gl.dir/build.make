# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mohammad.fakhreddin/CLionProjects/perspective_camera_open_gl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mohammad.fakhreddin/CLionProjects/perspective_camera_open_gl/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/perspective_camera_open_gl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/perspective_camera_open_gl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/perspective_camera_open_gl.dir/flags.make

CMakeFiles/perspective_camera_open_gl.dir/src/main.cpp.o: CMakeFiles/perspective_camera_open_gl.dir/flags.make
CMakeFiles/perspective_camera_open_gl.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mohammad.fakhreddin/CLionProjects/perspective_camera_open_gl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/perspective_camera_open_gl.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/perspective_camera_open_gl.dir/src/main.cpp.o -c /Users/mohammad.fakhreddin/CLionProjects/perspective_camera_open_gl/src/main.cpp

CMakeFiles/perspective_camera_open_gl.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/perspective_camera_open_gl.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mohammad.fakhreddin/CLionProjects/perspective_camera_open_gl/src/main.cpp > CMakeFiles/perspective_camera_open_gl.dir/src/main.cpp.i

CMakeFiles/perspective_camera_open_gl.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/perspective_camera_open_gl.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mohammad.fakhreddin/CLionProjects/perspective_camera_open_gl/src/main.cpp -o CMakeFiles/perspective_camera_open_gl.dir/src/main.cpp.s

# Object files for target perspective_camera_open_gl
perspective_camera_open_gl_OBJECTS = \
"CMakeFiles/perspective_camera_open_gl.dir/src/main.cpp.o"

# External object files for target perspective_camera_open_gl
perspective_camera_open_gl_EXTERNAL_OBJECTS =

perspective_camera_open_gl: CMakeFiles/perspective_camera_open_gl.dir/src/main.cpp.o
perspective_camera_open_gl: CMakeFiles/perspective_camera_open_gl.dir/build.make
perspective_camera_open_gl: /usr/local/lib/libsfml-graphics.2.5.1.dylib
perspective_camera_open_gl: /usr/local/lib/libsfml-window.2.5.1.dylib
perspective_camera_open_gl: /usr/local/lib/libsfml-audio.2.5.1.dylib
perspective_camera_open_gl: /usr/local/lib/libsfml-network.2.5.1.dylib
perspective_camera_open_gl: /usr/local/lib/libsfml-system.2.5.1.dylib
perspective_camera_open_gl: CMakeFiles/perspective_camera_open_gl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mohammad.fakhreddin/CLionProjects/perspective_camera_open_gl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable perspective_camera_open_gl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/perspective_camera_open_gl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/perspective_camera_open_gl.dir/build: perspective_camera_open_gl

.PHONY : CMakeFiles/perspective_camera_open_gl.dir/build

CMakeFiles/perspective_camera_open_gl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/perspective_camera_open_gl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/perspective_camera_open_gl.dir/clean

CMakeFiles/perspective_camera_open_gl.dir/depend:
	cd /Users/mohammad.fakhreddin/CLionProjects/perspective_camera_open_gl/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mohammad.fakhreddin/CLionProjects/perspective_camera_open_gl /Users/mohammad.fakhreddin/CLionProjects/perspective_camera_open_gl /Users/mohammad.fakhreddin/CLionProjects/perspective_camera_open_gl/cmake-build-debug /Users/mohammad.fakhreddin/CLionProjects/perspective_camera_open_gl/cmake-build-debug /Users/mohammad.fakhreddin/CLionProjects/perspective_camera_open_gl/cmake-build-debug/CMakeFiles/perspective_camera_open_gl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/perspective_camera_open_gl.dir/depend

