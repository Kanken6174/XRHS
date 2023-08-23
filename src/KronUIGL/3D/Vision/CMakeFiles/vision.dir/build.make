# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/orangepi/code/XRHS/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/orangepi/code/XRHS/src

# Include any dependencies generated for this target.
include KronUIGL/3D/Vision/CMakeFiles/vision.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include KronUIGL/3D/Vision/CMakeFiles/vision.dir/compiler_depend.make

# Include the progress variables for this target.
include KronUIGL/3D/Vision/CMakeFiles/vision.dir/progress.make

# Include the compile flags for this target's objects.
include KronUIGL/3D/Vision/CMakeFiles/vision.dir/flags.make

KronUIGL/3D/Vision/CMakeFiles/vision.dir/camera.cpp.o: KronUIGL/3D/Vision/CMakeFiles/vision.dir/flags.make
KronUIGL/3D/Vision/CMakeFiles/vision.dir/camera.cpp.o: /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/3D/Vision/camera.cpp
KronUIGL/3D/Vision/CMakeFiles/vision.dir/camera.cpp.o: KronUIGL/3D/Vision/CMakeFiles/vision.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orangepi/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object KronUIGL/3D/Vision/CMakeFiles/vision.dir/camera.cpp.o"
	cd /home/orangepi/code/XRHS/src/KronUIGL/3D/Vision && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT KronUIGL/3D/Vision/CMakeFiles/vision.dir/camera.cpp.o -MF CMakeFiles/vision.dir/camera.cpp.o.d -o CMakeFiles/vision.dir/camera.cpp.o -c /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/3D/Vision/camera.cpp

KronUIGL/3D/Vision/CMakeFiles/vision.dir/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vision.dir/camera.cpp.i"
	cd /home/orangepi/code/XRHS/src/KronUIGL/3D/Vision && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/3D/Vision/camera.cpp > CMakeFiles/vision.dir/camera.cpp.i

KronUIGL/3D/Vision/CMakeFiles/vision.dir/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vision.dir/camera.cpp.s"
	cd /home/orangepi/code/XRHS/src/KronUIGL/3D/Vision && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/3D/Vision/camera.cpp -o CMakeFiles/vision.dir/camera.cpp.s

# Object files for target vision
vision_OBJECTS = \
"CMakeFiles/vision.dir/camera.cpp.o"

# External object files for target vision
vision_EXTERNAL_OBJECTS =

KronUIGL/3D/Vision/libvision.a: KronUIGL/3D/Vision/CMakeFiles/vision.dir/camera.cpp.o
KronUIGL/3D/Vision/libvision.a: KronUIGL/3D/Vision/CMakeFiles/vision.dir/build.make
KronUIGL/3D/Vision/libvision.a: KronUIGL/3D/Vision/CMakeFiles/vision.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/orangepi/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libvision.a"
	cd /home/orangepi/code/XRHS/src/KronUIGL/3D/Vision && $(CMAKE_COMMAND) -P CMakeFiles/vision.dir/cmake_clean_target.cmake
	cd /home/orangepi/code/XRHS/src/KronUIGL/3D/Vision && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vision.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
KronUIGL/3D/Vision/CMakeFiles/vision.dir/build: KronUIGL/3D/Vision/libvision.a
.PHONY : KronUIGL/3D/Vision/CMakeFiles/vision.dir/build

KronUIGL/3D/Vision/CMakeFiles/vision.dir/clean:
	cd /home/orangepi/code/XRHS/src/KronUIGL/3D/Vision && $(CMAKE_COMMAND) -P CMakeFiles/vision.dir/cmake_clean.cmake
.PHONY : KronUIGL/3D/Vision/CMakeFiles/vision.dir/clean

KronUIGL/3D/Vision/CMakeFiles/vision.dir/depend:
	cd /home/orangepi/code/XRHS/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/orangepi/code/XRHS/src /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/3D/Vision /home/orangepi/code/XRHS/src /home/orangepi/code/XRHS/src/KronUIGL/3D/Vision /home/orangepi/code/XRHS/src/KronUIGL/3D/Vision/CMakeFiles/vision.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : KronUIGL/3D/Vision/CMakeFiles/vision.dir/depend

