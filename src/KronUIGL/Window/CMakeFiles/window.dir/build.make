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
include KronUIGL/Window/CMakeFiles/window.dir/depend.make

# Include the progress variables for this target.
include KronUIGL/Window/CMakeFiles/window.dir/progress.make

# Include the compile flags for this target's objects.
include KronUIGL/Window/CMakeFiles/window.dir/flags.make

KronUIGL/Window/CMakeFiles/window.dir/KronUIWindow.cpp.o: KronUIGL/Window/CMakeFiles/window.dir/flags.make
KronUIGL/Window/CMakeFiles/window.dir/KronUIWindow.cpp.o: /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Window/KronUIWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orangepi/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object KronUIGL/Window/CMakeFiles/window.dir/KronUIWindow.cpp.o"
	cd /home/orangepi/code/XRHS/src/KronUIGL/Window && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/window.dir/KronUIWindow.cpp.o -c /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Window/KronUIWindow.cpp

KronUIGL/Window/CMakeFiles/window.dir/KronUIWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/window.dir/KronUIWindow.cpp.i"
	cd /home/orangepi/code/XRHS/src/KronUIGL/Window && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Window/KronUIWindow.cpp > CMakeFiles/window.dir/KronUIWindow.cpp.i

KronUIGL/Window/CMakeFiles/window.dir/KronUIWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/window.dir/KronUIWindow.cpp.s"
	cd /home/orangepi/code/XRHS/src/KronUIGL/Window && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Window/KronUIWindow.cpp -o CMakeFiles/window.dir/KronUIWindow.cpp.s

# Object files for target window
window_OBJECTS = \
"CMakeFiles/window.dir/KronUIWindow.cpp.o"

# External object files for target window
window_EXTERNAL_OBJECTS =

KronUIGL/Window/libwindow.a: KronUIGL/Window/CMakeFiles/window.dir/KronUIWindow.cpp.o
KronUIGL/Window/libwindow.a: KronUIGL/Window/CMakeFiles/window.dir/build.make
KronUIGL/Window/libwindow.a: KronUIGL/Window/CMakeFiles/window.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/orangepi/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libwindow.a"
	cd /home/orangepi/code/XRHS/src/KronUIGL/Window && $(CMAKE_COMMAND) -P CMakeFiles/window.dir/cmake_clean_target.cmake
	cd /home/orangepi/code/XRHS/src/KronUIGL/Window && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/window.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
KronUIGL/Window/CMakeFiles/window.dir/build: KronUIGL/Window/libwindow.a

.PHONY : KronUIGL/Window/CMakeFiles/window.dir/build

KronUIGL/Window/CMakeFiles/window.dir/clean:
	cd /home/orangepi/code/XRHS/src/KronUIGL/Window && $(CMAKE_COMMAND) -P CMakeFiles/window.dir/cmake_clean.cmake
.PHONY : KronUIGL/Window/CMakeFiles/window.dir/clean

KronUIGL/Window/CMakeFiles/window.dir/depend:
	cd /home/orangepi/code/XRHS/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/orangepi/code/XRHS/src /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Window /home/orangepi/code/XRHS/src /home/orangepi/code/XRHS/src/KronUIGL/Window /home/orangepi/code/XRHS/src/KronUIGL/Window/CMakeFiles/window.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : KronUIGL/Window/CMakeFiles/window.dir/depend

