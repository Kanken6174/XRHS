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
CMAKE_SOURCE_DIR = /home/kanken/code/opengl-tests/KronUI/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kanken/code/opengl-tests/KronUI/src

# Include any dependencies generated for this target.
include KronUIGL/3D/CMakeFiles/3D.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include KronUIGL/3D/CMakeFiles/3D.dir/compiler_depend.make

# Include the progress variables for this target.
include KronUIGL/3D/CMakeFiles/3D.dir/progress.make

# Include the compile flags for this target's objects.
include KronUIGL/3D/CMakeFiles/3D.dir/flags.make

# Object files for target 3D
3D_OBJECTS =

# External object files for target 3D
3D_EXTERNAL_OBJECTS =

KronUIGL/3D/lib3D.a: KronUIGL/3D/CMakeFiles/3D.dir/build.make
KronUIGL/3D/lib3D.a: KronUIGL/3D/CMakeFiles/3D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kanken/code/opengl-tests/KronUI/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX static library lib3D.a"
	cd /home/kanken/code/opengl-tests/KronUI/src/KronUIGL/3D && $(CMAKE_COMMAND) -P CMakeFiles/3D.dir/cmake_clean_target.cmake
	cd /home/kanken/code/opengl-tests/KronUI/src/KronUIGL/3D && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/3D.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
KronUIGL/3D/CMakeFiles/3D.dir/build: KronUIGL/3D/lib3D.a
.PHONY : KronUIGL/3D/CMakeFiles/3D.dir/build

KronUIGL/3D/CMakeFiles/3D.dir/clean:
	cd /home/kanken/code/opengl-tests/KronUI/src/KronUIGL/3D && $(CMAKE_COMMAND) -P CMakeFiles/3D.dir/cmake_clean.cmake
.PHONY : KronUIGL/3D/CMakeFiles/3D.dir/clean

KronUIGL/3D/CMakeFiles/3D.dir/depend:
	cd /home/kanken/code/opengl-tests/KronUI/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kanken/code/opengl-tests/KronUI/src /home/kanken/code/opengl-tests/KronUI/src/KronUIGL/3D /home/kanken/code/opengl-tests/KronUI/src /home/kanken/code/opengl-tests/KronUI/src/KronUIGL/3D /home/kanken/code/opengl-tests/KronUI/src/KronUIGL/3D/CMakeFiles/3D.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : KronUIGL/3D/CMakeFiles/3D.dir/depend

