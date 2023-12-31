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
CMAKE_SOURCE_DIR = /home/kanken/code/AHRS_core/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kanken/code/AHRS_core/src/build

# Include any dependencies generated for this target.
include processing/zbar/CMakeFiles/zbarLib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include processing/zbar/CMakeFiles/zbarLib.dir/compiler_depend.make

# Include the progress variables for this target.
include processing/zbar/CMakeFiles/zbarLib.dir/progress.make

# Include the compile flags for this target's objects.
include processing/zbar/CMakeFiles/zbarLib.dir/flags.make

processing/zbar/CMakeFiles/zbarLib.dir/zbar.cpp.o: processing/zbar/CMakeFiles/zbarLib.dir/flags.make
processing/zbar/CMakeFiles/zbarLib.dir/zbar.cpp.o: ../processing/zbar/zbar.cpp
processing/zbar/CMakeFiles/zbarLib.dir/zbar.cpp.o: processing/zbar/CMakeFiles/zbarLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanken/code/AHRS_core/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object processing/zbar/CMakeFiles/zbarLib.dir/zbar.cpp.o"
	cd /home/kanken/code/AHRS_core/src/build/processing/zbar && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT processing/zbar/CMakeFiles/zbarLib.dir/zbar.cpp.o -MF CMakeFiles/zbarLib.dir/zbar.cpp.o.d -o CMakeFiles/zbarLib.dir/zbar.cpp.o -c /home/kanken/code/AHRS_core/src/processing/zbar/zbar.cpp

processing/zbar/CMakeFiles/zbarLib.dir/zbar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zbarLib.dir/zbar.cpp.i"
	cd /home/kanken/code/AHRS_core/src/build/processing/zbar && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanken/code/AHRS_core/src/processing/zbar/zbar.cpp > CMakeFiles/zbarLib.dir/zbar.cpp.i

processing/zbar/CMakeFiles/zbarLib.dir/zbar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zbarLib.dir/zbar.cpp.s"
	cd /home/kanken/code/AHRS_core/src/build/processing/zbar && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanken/code/AHRS_core/src/processing/zbar/zbar.cpp -o CMakeFiles/zbarLib.dir/zbar.cpp.s

# Object files for target zbarLib
zbarLib_OBJECTS = \
"CMakeFiles/zbarLib.dir/zbar.cpp.o"

# External object files for target zbarLib
zbarLib_EXTERNAL_OBJECTS =

processing/zbar/libzbarLib.a: processing/zbar/CMakeFiles/zbarLib.dir/zbar.cpp.o
processing/zbar/libzbarLib.a: processing/zbar/CMakeFiles/zbarLib.dir/build.make
processing/zbar/libzbarLib.a: processing/zbar/CMakeFiles/zbarLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kanken/code/AHRS_core/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libzbarLib.a"
	cd /home/kanken/code/AHRS_core/src/build/processing/zbar && $(CMAKE_COMMAND) -P CMakeFiles/zbarLib.dir/cmake_clean_target.cmake
	cd /home/kanken/code/AHRS_core/src/build/processing/zbar && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zbarLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
processing/zbar/CMakeFiles/zbarLib.dir/build: processing/zbar/libzbarLib.a
.PHONY : processing/zbar/CMakeFiles/zbarLib.dir/build

processing/zbar/CMakeFiles/zbarLib.dir/clean:
	cd /home/kanken/code/AHRS_core/src/build/processing/zbar && $(CMAKE_COMMAND) -P CMakeFiles/zbarLib.dir/cmake_clean.cmake
.PHONY : processing/zbar/CMakeFiles/zbarLib.dir/clean

processing/zbar/CMakeFiles/zbarLib.dir/depend:
	cd /home/kanken/code/AHRS_core/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kanken/code/AHRS_core/src /home/kanken/code/AHRS_core/src/processing/zbar /home/kanken/code/AHRS_core/src/build /home/kanken/code/AHRS_core/src/build/processing/zbar /home/kanken/code/AHRS_core/src/build/processing/zbar/CMakeFiles/zbarLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : processing/zbar/CMakeFiles/zbarLib.dir/depend

