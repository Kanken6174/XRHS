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
include model/perfcheckers/CMakeFiles/perfcheckers.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include model/perfcheckers/CMakeFiles/perfcheckers.dir/compiler_depend.make

# Include the progress variables for this target.
include model/perfcheckers/CMakeFiles/perfcheckers.dir/progress.make

# Include the compile flags for this target's objects.
include model/perfcheckers/CMakeFiles/perfcheckers.dir/flags.make

model/perfcheckers/CMakeFiles/perfcheckers.dir/framerate.cpp.o: model/perfcheckers/CMakeFiles/perfcheckers.dir/flags.make
model/perfcheckers/CMakeFiles/perfcheckers.dir/framerate.cpp.o: ../model/perfcheckers/framerate.cpp
model/perfcheckers/CMakeFiles/perfcheckers.dir/framerate.cpp.o: model/perfcheckers/CMakeFiles/perfcheckers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanken/code/AHRS_core/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object model/perfcheckers/CMakeFiles/perfcheckers.dir/framerate.cpp.o"
	cd /home/kanken/code/AHRS_core/src/build/model/perfcheckers && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT model/perfcheckers/CMakeFiles/perfcheckers.dir/framerate.cpp.o -MF CMakeFiles/perfcheckers.dir/framerate.cpp.o.d -o CMakeFiles/perfcheckers.dir/framerate.cpp.o -c /home/kanken/code/AHRS_core/src/model/perfcheckers/framerate.cpp

model/perfcheckers/CMakeFiles/perfcheckers.dir/framerate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/perfcheckers.dir/framerate.cpp.i"
	cd /home/kanken/code/AHRS_core/src/build/model/perfcheckers && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanken/code/AHRS_core/src/model/perfcheckers/framerate.cpp > CMakeFiles/perfcheckers.dir/framerate.cpp.i

model/perfcheckers/CMakeFiles/perfcheckers.dir/framerate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/perfcheckers.dir/framerate.cpp.s"
	cd /home/kanken/code/AHRS_core/src/build/model/perfcheckers && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanken/code/AHRS_core/src/model/perfcheckers/framerate.cpp -o CMakeFiles/perfcheckers.dir/framerate.cpp.s

# Object files for target perfcheckers
perfcheckers_OBJECTS = \
"CMakeFiles/perfcheckers.dir/framerate.cpp.o"

# External object files for target perfcheckers
perfcheckers_EXTERNAL_OBJECTS =

model/perfcheckers/libperfcheckers.a: model/perfcheckers/CMakeFiles/perfcheckers.dir/framerate.cpp.o
model/perfcheckers/libperfcheckers.a: model/perfcheckers/CMakeFiles/perfcheckers.dir/build.make
model/perfcheckers/libperfcheckers.a: model/perfcheckers/CMakeFiles/perfcheckers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kanken/code/AHRS_core/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libperfcheckers.a"
	cd /home/kanken/code/AHRS_core/src/build/model/perfcheckers && $(CMAKE_COMMAND) -P CMakeFiles/perfcheckers.dir/cmake_clean_target.cmake
	cd /home/kanken/code/AHRS_core/src/build/model/perfcheckers && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/perfcheckers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
model/perfcheckers/CMakeFiles/perfcheckers.dir/build: model/perfcheckers/libperfcheckers.a
.PHONY : model/perfcheckers/CMakeFiles/perfcheckers.dir/build

model/perfcheckers/CMakeFiles/perfcheckers.dir/clean:
	cd /home/kanken/code/AHRS_core/src/build/model/perfcheckers && $(CMAKE_COMMAND) -P CMakeFiles/perfcheckers.dir/cmake_clean.cmake
.PHONY : model/perfcheckers/CMakeFiles/perfcheckers.dir/clean

model/perfcheckers/CMakeFiles/perfcheckers.dir/depend:
	cd /home/kanken/code/AHRS_core/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kanken/code/AHRS_core/src /home/kanken/code/AHRS_core/src/model/perfcheckers /home/kanken/code/AHRS_core/src/build /home/kanken/code/AHRS_core/src/build/model/perfcheckers /home/kanken/code/AHRS_core/src/build/model/perfcheckers/CMakeFiles/perfcheckers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : model/perfcheckers/CMakeFiles/perfcheckers.dir/depend

