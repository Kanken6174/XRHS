# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
include ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/depend.make

# Include the progress variables for this target.
include ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/progress.make

# Include the compile flags for this target's objects.
include ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/flags.make

ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/camEnum.cpp.o: ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/flags.make
ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/camEnum.cpp.o: /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/model/hardware/cameras/camEnum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orangepi/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/camEnum.cpp.o"
	cd /home/orangepi/code/XRHS/src/ARHS/model/hardware/cameras && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cameras.dir/camEnum.cpp.o -c /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/model/hardware/cameras/camEnum.cpp

ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/camEnum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cameras.dir/camEnum.cpp.i"
	cd /home/orangepi/code/XRHS/src/ARHS/model/hardware/cameras && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/model/hardware/cameras/camEnum.cpp > CMakeFiles/cameras.dir/camEnum.cpp.i

ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/camEnum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cameras.dir/camEnum.cpp.s"
	cd /home/orangepi/code/XRHS/src/ARHS/model/hardware/cameras && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/model/hardware/cameras/camEnum.cpp -o CMakeFiles/cameras.dir/camEnum.cpp.s

ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/cameraManager.cpp.o: ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/flags.make
ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/cameraManager.cpp.o: /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/model/hardware/cameras/cameraManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orangepi/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/cameraManager.cpp.o"
	cd /home/orangepi/code/XRHS/src/ARHS/model/hardware/cameras && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cameras.dir/cameraManager.cpp.o -c /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/model/hardware/cameras/cameraManager.cpp

ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/cameraManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cameras.dir/cameraManager.cpp.i"
	cd /home/orangepi/code/XRHS/src/ARHS/model/hardware/cameras && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/model/hardware/cameras/cameraManager.cpp > CMakeFiles/cameras.dir/cameraManager.cpp.i

ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/cameraManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cameras.dir/cameraManager.cpp.s"
	cd /home/orangepi/code/XRHS/src/ARHS/model/hardware/cameras && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/model/hardware/cameras/cameraManager.cpp -o CMakeFiles/cameras.dir/cameraManager.cpp.s

# Object files for target cameras
cameras_OBJECTS = \
"CMakeFiles/cameras.dir/camEnum.cpp.o" \
"CMakeFiles/cameras.dir/cameraManager.cpp.o"

# External object files for target cameras
cameras_EXTERNAL_OBJECTS =

ARHS/model/hardware/cameras/libcameras.a: ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/camEnum.cpp.o
ARHS/model/hardware/cameras/libcameras.a: ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/cameraManager.cpp.o
ARHS/model/hardware/cameras/libcameras.a: ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/build.make
ARHS/model/hardware/cameras/libcameras.a: ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/orangepi/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libcameras.a"
	cd /home/orangepi/code/XRHS/src/ARHS/model/hardware/cameras && $(CMAKE_COMMAND) -P CMakeFiles/cameras.dir/cmake_clean_target.cmake
	cd /home/orangepi/code/XRHS/src/ARHS/model/hardware/cameras && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cameras.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/build: ARHS/model/hardware/cameras/libcameras.a

.PHONY : ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/build

ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/clean:
	cd /home/orangepi/code/XRHS/src/ARHS/model/hardware/cameras && $(CMAKE_COMMAND) -P CMakeFiles/cameras.dir/cmake_clean.cmake
.PHONY : ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/clean

ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/depend:
	cd /home/orangepi/code/XRHS/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/orangepi/code/XRHS/src /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/model/hardware/cameras /home/orangepi/code/XRHS/src /home/orangepi/code/XRHS/src/ARHS/model/hardware/cameras /home/orangepi/code/XRHS/src/ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ARHS/model/hardware/cameras/CMakeFiles/cameras.dir/depend

