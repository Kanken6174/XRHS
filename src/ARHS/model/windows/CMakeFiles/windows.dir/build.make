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
CMAKE_SOURCE_DIR = /home/kanken/code/XRHS/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kanken/code/XRHS/src

# Include any dependencies generated for this target.
include ARHS/model/windows/CMakeFiles/windows.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include ARHS/model/windows/CMakeFiles/windows.dir/compiler_depend.make

# Include the progress variables for this target.
include ARHS/model/windows/CMakeFiles/windows.dir/progress.make

# Include the compile flags for this target's objects.
include ARHS/model/windows/CMakeFiles/windows.dir/flags.make

ARHS/model/windows/CMakeFiles/windows.dir/window.cpp.o: ARHS/model/windows/CMakeFiles/windows.dir/flags.make
ARHS/model/windows/CMakeFiles/windows.dir/window.cpp.o: /home/kanken/code/XRHS/Dependencies/AHRS_core/src/model/windows/window.cpp
ARHS/model/windows/CMakeFiles/windows.dir/window.cpp.o: ARHS/model/windows/CMakeFiles/windows.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanken/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ARHS/model/windows/CMakeFiles/windows.dir/window.cpp.o"
	cd /home/kanken/code/XRHS/src/ARHS/model/windows && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ARHS/model/windows/CMakeFiles/windows.dir/window.cpp.o -MF CMakeFiles/windows.dir/window.cpp.o.d -o CMakeFiles/windows.dir/window.cpp.o -c /home/kanken/code/XRHS/Dependencies/AHRS_core/src/model/windows/window.cpp

ARHS/model/windows/CMakeFiles/windows.dir/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/windows.dir/window.cpp.i"
	cd /home/kanken/code/XRHS/src/ARHS/model/windows && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanken/code/XRHS/Dependencies/AHRS_core/src/model/windows/window.cpp > CMakeFiles/windows.dir/window.cpp.i

ARHS/model/windows/CMakeFiles/windows.dir/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/windows.dir/window.cpp.s"
	cd /home/kanken/code/XRHS/src/ARHS/model/windows && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanken/code/XRHS/Dependencies/AHRS_core/src/model/windows/window.cpp -o CMakeFiles/windows.dir/window.cpp.s

ARHS/model/windows/CMakeFiles/windows.dir/windowManager.cpp.o: ARHS/model/windows/CMakeFiles/windows.dir/flags.make
ARHS/model/windows/CMakeFiles/windows.dir/windowManager.cpp.o: /home/kanken/code/XRHS/Dependencies/AHRS_core/src/model/windows/windowManager.cpp
ARHS/model/windows/CMakeFiles/windows.dir/windowManager.cpp.o: ARHS/model/windows/CMakeFiles/windows.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanken/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object ARHS/model/windows/CMakeFiles/windows.dir/windowManager.cpp.o"
	cd /home/kanken/code/XRHS/src/ARHS/model/windows && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ARHS/model/windows/CMakeFiles/windows.dir/windowManager.cpp.o -MF CMakeFiles/windows.dir/windowManager.cpp.o.d -o CMakeFiles/windows.dir/windowManager.cpp.o -c /home/kanken/code/XRHS/Dependencies/AHRS_core/src/model/windows/windowManager.cpp

ARHS/model/windows/CMakeFiles/windows.dir/windowManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/windows.dir/windowManager.cpp.i"
	cd /home/kanken/code/XRHS/src/ARHS/model/windows && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanken/code/XRHS/Dependencies/AHRS_core/src/model/windows/windowManager.cpp > CMakeFiles/windows.dir/windowManager.cpp.i

ARHS/model/windows/CMakeFiles/windows.dir/windowManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/windows.dir/windowManager.cpp.s"
	cd /home/kanken/code/XRHS/src/ARHS/model/windows && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanken/code/XRHS/Dependencies/AHRS_core/src/model/windows/windowManager.cpp -o CMakeFiles/windows.dir/windowManager.cpp.s

# Object files for target windows
windows_OBJECTS = \
"CMakeFiles/windows.dir/window.cpp.o" \
"CMakeFiles/windows.dir/windowManager.cpp.o"

# External object files for target windows
windows_EXTERNAL_OBJECTS =

ARHS/model/windows/libwindows.a: ARHS/model/windows/CMakeFiles/windows.dir/window.cpp.o
ARHS/model/windows/libwindows.a: ARHS/model/windows/CMakeFiles/windows.dir/windowManager.cpp.o
ARHS/model/windows/libwindows.a: ARHS/model/windows/CMakeFiles/windows.dir/build.make
ARHS/model/windows/libwindows.a: ARHS/model/windows/CMakeFiles/windows.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kanken/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libwindows.a"
	cd /home/kanken/code/XRHS/src/ARHS/model/windows && $(CMAKE_COMMAND) -P CMakeFiles/windows.dir/cmake_clean_target.cmake
	cd /home/kanken/code/XRHS/src/ARHS/model/windows && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/windows.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ARHS/model/windows/CMakeFiles/windows.dir/build: ARHS/model/windows/libwindows.a
.PHONY : ARHS/model/windows/CMakeFiles/windows.dir/build

ARHS/model/windows/CMakeFiles/windows.dir/clean:
	cd /home/kanken/code/XRHS/src/ARHS/model/windows && $(CMAKE_COMMAND) -P CMakeFiles/windows.dir/cmake_clean.cmake
.PHONY : ARHS/model/windows/CMakeFiles/windows.dir/clean

ARHS/model/windows/CMakeFiles/windows.dir/depend:
	cd /home/kanken/code/XRHS/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kanken/code/XRHS/src /home/kanken/code/XRHS/Dependencies/AHRS_core/src/model/windows /home/kanken/code/XRHS/src /home/kanken/code/XRHS/src/ARHS/model/windows /home/kanken/code/XRHS/src/ARHS/model/windows/CMakeFiles/windows.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ARHS/model/windows/CMakeFiles/windows.dir/depend

