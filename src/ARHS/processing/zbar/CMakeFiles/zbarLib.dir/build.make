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
include ARHS/processing/zbar/CMakeFiles/zbarLib.dir/depend.make

# Include the progress variables for this target.
include ARHS/processing/zbar/CMakeFiles/zbarLib.dir/progress.make

# Include the compile flags for this target's objects.
include ARHS/processing/zbar/CMakeFiles/zbarLib.dir/flags.make

ARHS/processing/zbar/CMakeFiles/zbarLib.dir/zbar.cpp.o: ARHS/processing/zbar/CMakeFiles/zbarLib.dir/flags.make
ARHS/processing/zbar/CMakeFiles/zbarLib.dir/zbar.cpp.o: /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/processing/zbar/zbar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orangepi/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ARHS/processing/zbar/CMakeFiles/zbarLib.dir/zbar.cpp.o"
	cd /home/orangepi/code/XRHS/src/ARHS/processing/zbar && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zbarLib.dir/zbar.cpp.o -c /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/processing/zbar/zbar.cpp

ARHS/processing/zbar/CMakeFiles/zbarLib.dir/zbar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zbarLib.dir/zbar.cpp.i"
	cd /home/orangepi/code/XRHS/src/ARHS/processing/zbar && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/processing/zbar/zbar.cpp > CMakeFiles/zbarLib.dir/zbar.cpp.i

ARHS/processing/zbar/CMakeFiles/zbarLib.dir/zbar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zbarLib.dir/zbar.cpp.s"
	cd /home/orangepi/code/XRHS/src/ARHS/processing/zbar && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/processing/zbar/zbar.cpp -o CMakeFiles/zbarLib.dir/zbar.cpp.s

# Object files for target zbarLib
zbarLib_OBJECTS = \
"CMakeFiles/zbarLib.dir/zbar.cpp.o"

# External object files for target zbarLib
zbarLib_EXTERNAL_OBJECTS =

ARHS/processing/zbar/libzbarLib.a: ARHS/processing/zbar/CMakeFiles/zbarLib.dir/zbar.cpp.o
ARHS/processing/zbar/libzbarLib.a: ARHS/processing/zbar/CMakeFiles/zbarLib.dir/build.make
ARHS/processing/zbar/libzbarLib.a: ARHS/processing/zbar/CMakeFiles/zbarLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/orangepi/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libzbarLib.a"
	cd /home/orangepi/code/XRHS/src/ARHS/processing/zbar && $(CMAKE_COMMAND) -P CMakeFiles/zbarLib.dir/cmake_clean_target.cmake
	cd /home/orangepi/code/XRHS/src/ARHS/processing/zbar && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zbarLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ARHS/processing/zbar/CMakeFiles/zbarLib.dir/build: ARHS/processing/zbar/libzbarLib.a

.PHONY : ARHS/processing/zbar/CMakeFiles/zbarLib.dir/build

ARHS/processing/zbar/CMakeFiles/zbarLib.dir/clean:
	cd /home/orangepi/code/XRHS/src/ARHS/processing/zbar && $(CMAKE_COMMAND) -P CMakeFiles/zbarLib.dir/cmake_clean.cmake
.PHONY : ARHS/processing/zbar/CMakeFiles/zbarLib.dir/clean

ARHS/processing/zbar/CMakeFiles/zbarLib.dir/depend:
	cd /home/orangepi/code/XRHS/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/orangepi/code/XRHS/src /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/processing/zbar /home/orangepi/code/XRHS/src /home/orangepi/code/XRHS/src/ARHS/processing/zbar /home/orangepi/code/XRHS/src/ARHS/processing/zbar/CMakeFiles/zbarLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ARHS/processing/zbar/CMakeFiles/zbarLib.dir/depend

