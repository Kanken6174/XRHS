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
include Freetype/CMakeFiles/TTM.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Freetype/CMakeFiles/TTM.dir/compiler_depend.make

# Include the progress variables for this target.
include Freetype/CMakeFiles/TTM.dir/progress.make

# Include the compile flags for this target's objects.
include Freetype/CMakeFiles/TTM.dir/flags.make

Freetype/CMakeFiles/TTM.dir/TrueTypeManager.cpp.o: Freetype/CMakeFiles/TTM.dir/flags.make
Freetype/CMakeFiles/TTM.dir/TrueTypeManager.cpp.o: Freetype/TrueTypeManager.cpp
Freetype/CMakeFiles/TTM.dir/TrueTypeManager.cpp.o: Freetype/CMakeFiles/TTM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanken/code/opengl-tests/KronUI/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Freetype/CMakeFiles/TTM.dir/TrueTypeManager.cpp.o"
	cd /home/kanken/code/opengl-tests/KronUI/src/Freetype && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Freetype/CMakeFiles/TTM.dir/TrueTypeManager.cpp.o -MF CMakeFiles/TTM.dir/TrueTypeManager.cpp.o.d -o CMakeFiles/TTM.dir/TrueTypeManager.cpp.o -c /home/kanken/code/opengl-tests/KronUI/src/Freetype/TrueTypeManager.cpp

Freetype/CMakeFiles/TTM.dir/TrueTypeManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TTM.dir/TrueTypeManager.cpp.i"
	cd /home/kanken/code/opengl-tests/KronUI/src/Freetype && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanken/code/opengl-tests/KronUI/src/Freetype/TrueTypeManager.cpp > CMakeFiles/TTM.dir/TrueTypeManager.cpp.i

Freetype/CMakeFiles/TTM.dir/TrueTypeManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TTM.dir/TrueTypeManager.cpp.s"
	cd /home/kanken/code/opengl-tests/KronUI/src/Freetype && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanken/code/opengl-tests/KronUI/src/Freetype/TrueTypeManager.cpp -o CMakeFiles/TTM.dir/TrueTypeManager.cpp.s

# Object files for target TTM
TTM_OBJECTS = \
"CMakeFiles/TTM.dir/TrueTypeManager.cpp.o"

# External object files for target TTM
TTM_EXTERNAL_OBJECTS =

Freetype/libTTM.a: Freetype/CMakeFiles/TTM.dir/TrueTypeManager.cpp.o
Freetype/libTTM.a: Freetype/CMakeFiles/TTM.dir/build.make
Freetype/libTTM.a: Freetype/CMakeFiles/TTM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kanken/code/opengl-tests/KronUI/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libTTM.a"
	cd /home/kanken/code/opengl-tests/KronUI/src/Freetype && $(CMAKE_COMMAND) -P CMakeFiles/TTM.dir/cmake_clean_target.cmake
	cd /home/kanken/code/opengl-tests/KronUI/src/Freetype && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TTM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Freetype/CMakeFiles/TTM.dir/build: Freetype/libTTM.a
.PHONY : Freetype/CMakeFiles/TTM.dir/build

Freetype/CMakeFiles/TTM.dir/clean:
	cd /home/kanken/code/opengl-tests/KronUI/src/Freetype && $(CMAKE_COMMAND) -P CMakeFiles/TTM.dir/cmake_clean.cmake
.PHONY : Freetype/CMakeFiles/TTM.dir/clean

Freetype/CMakeFiles/TTM.dir/depend:
	cd /home/kanken/code/opengl-tests/KronUI/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kanken/code/opengl-tests/KronUI/src /home/kanken/code/opengl-tests/KronUI/src/Freetype /home/kanken/code/opengl-tests/KronUI/src /home/kanken/code/opengl-tests/KronUI/src/Freetype /home/kanken/code/opengl-tests/KronUI/src/Freetype/CMakeFiles/TTM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Freetype/CMakeFiles/TTM.dir/depend

