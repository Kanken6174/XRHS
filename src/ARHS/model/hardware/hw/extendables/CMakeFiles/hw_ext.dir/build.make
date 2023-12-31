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
include ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/depend.make

# Include the progress variables for this target.
include ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/progress.make

# Include the compile flags for this target's objects.
include ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/flags.make

ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/DeviceTree.cpp.o: ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/flags.make
ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/DeviceTree.cpp.o: /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/model/hardware/hw/extendables/DeviceTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orangepi/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/DeviceTree.cpp.o"
	cd /home/orangepi/code/XRHS/src/ARHS/model/hardware/hw/extendables && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw_ext.dir/DeviceTree.cpp.o -c /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/model/hardware/hw/extendables/DeviceTree.cpp

ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/DeviceTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw_ext.dir/DeviceTree.cpp.i"
	cd /home/orangepi/code/XRHS/src/ARHS/model/hardware/hw/extendables && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/model/hardware/hw/extendables/DeviceTree.cpp > CMakeFiles/hw_ext.dir/DeviceTree.cpp.i

ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/DeviceTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw_ext.dir/DeviceTree.cpp.s"
	cd /home/orangepi/code/XRHS/src/ARHS/model/hardware/hw/extendables && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/model/hardware/hw/extendables/DeviceTree.cpp -o CMakeFiles/hw_ext.dir/DeviceTree.cpp.s

# Object files for target hw_ext
hw_ext_OBJECTS = \
"CMakeFiles/hw_ext.dir/DeviceTree.cpp.o"

# External object files for target hw_ext
hw_ext_EXTERNAL_OBJECTS =

ARHS/model/hardware/hw/extendables/libhw_ext.a: ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/DeviceTree.cpp.o
ARHS/model/hardware/hw/extendables/libhw_ext.a: ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/build.make
ARHS/model/hardware/hw/extendables/libhw_ext.a: ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/orangepi/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libhw_ext.a"
	cd /home/orangepi/code/XRHS/src/ARHS/model/hardware/hw/extendables && $(CMAKE_COMMAND) -P CMakeFiles/hw_ext.dir/cmake_clean_target.cmake
	cd /home/orangepi/code/XRHS/src/ARHS/model/hardware/hw/extendables && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw_ext.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/build: ARHS/model/hardware/hw/extendables/libhw_ext.a

.PHONY : ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/build

ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/clean:
	cd /home/orangepi/code/XRHS/src/ARHS/model/hardware/hw/extendables && $(CMAKE_COMMAND) -P CMakeFiles/hw_ext.dir/cmake_clean.cmake
.PHONY : ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/clean

ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/depend:
	cd /home/orangepi/code/XRHS/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/orangepi/code/XRHS/src /home/orangepi/code/XRHS/Dependencies/AHRS_core/src/model/hardware/hw/extendables /home/orangepi/code/XRHS/src /home/orangepi/code/XRHS/src/ARHS/model/hardware/hw/extendables /home/orangepi/code/XRHS/src/ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ARHS/model/hardware/hw/extendables/CMakeFiles/hw_ext.dir/depend

