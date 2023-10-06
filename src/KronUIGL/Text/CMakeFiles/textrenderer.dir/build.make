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
include KronUIGL/Text/CMakeFiles/textrenderer.dir/depend.make

# Include the progress variables for this target.
include KronUIGL/Text/CMakeFiles/textrenderer.dir/progress.make

# Include the compile flags for this target's objects.
include KronUIGL/Text/CMakeFiles/textrenderer.dir/flags.make

KronUIGL/Text/CMakeFiles/textrenderer.dir/TextRenderer.cpp.o: KronUIGL/Text/CMakeFiles/textrenderer.dir/flags.make
KronUIGL/Text/CMakeFiles/textrenderer.dir/TextRenderer.cpp.o: /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Text/TextRenderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orangepi/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object KronUIGL/Text/CMakeFiles/textrenderer.dir/TextRenderer.cpp.o"
	cd /home/orangepi/code/XRHS/src/KronUIGL/Text && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/textrenderer.dir/TextRenderer.cpp.o -c /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Text/TextRenderer.cpp

KronUIGL/Text/CMakeFiles/textrenderer.dir/TextRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/textrenderer.dir/TextRenderer.cpp.i"
	cd /home/orangepi/code/XRHS/src/KronUIGL/Text && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Text/TextRenderer.cpp > CMakeFiles/textrenderer.dir/TextRenderer.cpp.i

KronUIGL/Text/CMakeFiles/textrenderer.dir/TextRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/textrenderer.dir/TextRenderer.cpp.s"
	cd /home/orangepi/code/XRHS/src/KronUIGL/Text && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Text/TextRenderer.cpp -o CMakeFiles/textrenderer.dir/TextRenderer.cpp.s

# Object files for target textrenderer
textrenderer_OBJECTS = \
"CMakeFiles/textrenderer.dir/TextRenderer.cpp.o"

# External object files for target textrenderer
textrenderer_EXTERNAL_OBJECTS =

KronUIGL/Text/libtextrenderer.a: KronUIGL/Text/CMakeFiles/textrenderer.dir/TextRenderer.cpp.o
KronUIGL/Text/libtextrenderer.a: KronUIGL/Text/CMakeFiles/textrenderer.dir/build.make
KronUIGL/Text/libtextrenderer.a: KronUIGL/Text/CMakeFiles/textrenderer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/orangepi/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libtextrenderer.a"
	cd /home/orangepi/code/XRHS/src/KronUIGL/Text && $(CMAKE_COMMAND) -P CMakeFiles/textrenderer.dir/cmake_clean_target.cmake
	cd /home/orangepi/code/XRHS/src/KronUIGL/Text && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/textrenderer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
KronUIGL/Text/CMakeFiles/textrenderer.dir/build: KronUIGL/Text/libtextrenderer.a

.PHONY : KronUIGL/Text/CMakeFiles/textrenderer.dir/build

KronUIGL/Text/CMakeFiles/textrenderer.dir/clean:
	cd /home/orangepi/code/XRHS/src/KronUIGL/Text && $(CMAKE_COMMAND) -P CMakeFiles/textrenderer.dir/cmake_clean.cmake
.PHONY : KronUIGL/Text/CMakeFiles/textrenderer.dir/clean

KronUIGL/Text/CMakeFiles/textrenderer.dir/depend:
	cd /home/orangepi/code/XRHS/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/orangepi/code/XRHS/src /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Text /home/orangepi/code/XRHS/src /home/orangepi/code/XRHS/src/KronUIGL/Text /home/orangepi/code/XRHS/src/KronUIGL/Text/CMakeFiles/textrenderer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : KronUIGL/Text/CMakeFiles/textrenderer.dir/depend

