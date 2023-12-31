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
include KronUIGL/Shaders/CMakeFiles/shaders.dir/depend.make

# Include the progress variables for this target.
include KronUIGL/Shaders/CMakeFiles/shaders.dir/progress.make

# Include the compile flags for this target's objects.
include KronUIGL/Shaders/CMakeFiles/shaders.dir/flags.make

KronUIGL/Shaders/CMakeFiles/shaders.dir/Shader.cpp.o: KronUIGL/Shaders/CMakeFiles/shaders.dir/flags.make
KronUIGL/Shaders/CMakeFiles/shaders.dir/Shader.cpp.o: /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Shaders/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orangepi/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object KronUIGL/Shaders/CMakeFiles/shaders.dir/Shader.cpp.o"
	cd /home/orangepi/code/XRHS/src/KronUIGL/Shaders && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shaders.dir/Shader.cpp.o -c /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Shaders/Shader.cpp

KronUIGL/Shaders/CMakeFiles/shaders.dir/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shaders.dir/Shader.cpp.i"
	cd /home/orangepi/code/XRHS/src/KronUIGL/Shaders && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Shaders/Shader.cpp > CMakeFiles/shaders.dir/Shader.cpp.i

KronUIGL/Shaders/CMakeFiles/shaders.dir/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shaders.dir/Shader.cpp.s"
	cd /home/orangepi/code/XRHS/src/KronUIGL/Shaders && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Shaders/Shader.cpp -o CMakeFiles/shaders.dir/Shader.cpp.s

KronUIGL/Shaders/CMakeFiles/shaders.dir/ShaderManager.cpp.o: KronUIGL/Shaders/CMakeFiles/shaders.dir/flags.make
KronUIGL/Shaders/CMakeFiles/shaders.dir/ShaderManager.cpp.o: /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Shaders/ShaderManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/orangepi/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object KronUIGL/Shaders/CMakeFiles/shaders.dir/ShaderManager.cpp.o"
	cd /home/orangepi/code/XRHS/src/KronUIGL/Shaders && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shaders.dir/ShaderManager.cpp.o -c /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Shaders/ShaderManager.cpp

KronUIGL/Shaders/CMakeFiles/shaders.dir/ShaderManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shaders.dir/ShaderManager.cpp.i"
	cd /home/orangepi/code/XRHS/src/KronUIGL/Shaders && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Shaders/ShaderManager.cpp > CMakeFiles/shaders.dir/ShaderManager.cpp.i

KronUIGL/Shaders/CMakeFiles/shaders.dir/ShaderManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shaders.dir/ShaderManager.cpp.s"
	cd /home/orangepi/code/XRHS/src/KronUIGL/Shaders && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Shaders/ShaderManager.cpp -o CMakeFiles/shaders.dir/ShaderManager.cpp.s

# Object files for target shaders
shaders_OBJECTS = \
"CMakeFiles/shaders.dir/Shader.cpp.o" \
"CMakeFiles/shaders.dir/ShaderManager.cpp.o"

# External object files for target shaders
shaders_EXTERNAL_OBJECTS =

KronUIGL/Shaders/libshaders.a: KronUIGL/Shaders/CMakeFiles/shaders.dir/Shader.cpp.o
KronUIGL/Shaders/libshaders.a: KronUIGL/Shaders/CMakeFiles/shaders.dir/ShaderManager.cpp.o
KronUIGL/Shaders/libshaders.a: KronUIGL/Shaders/CMakeFiles/shaders.dir/build.make
KronUIGL/Shaders/libshaders.a: KronUIGL/Shaders/CMakeFiles/shaders.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/orangepi/code/XRHS/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libshaders.a"
	cd /home/orangepi/code/XRHS/src/KronUIGL/Shaders && $(CMAKE_COMMAND) -P CMakeFiles/shaders.dir/cmake_clean_target.cmake
	cd /home/orangepi/code/XRHS/src/KronUIGL/Shaders && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shaders.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
KronUIGL/Shaders/CMakeFiles/shaders.dir/build: KronUIGL/Shaders/libshaders.a

.PHONY : KronUIGL/Shaders/CMakeFiles/shaders.dir/build

KronUIGL/Shaders/CMakeFiles/shaders.dir/clean:
	cd /home/orangepi/code/XRHS/src/KronUIGL/Shaders && $(CMAKE_COMMAND) -P CMakeFiles/shaders.dir/cmake_clean.cmake
.PHONY : KronUIGL/Shaders/CMakeFiles/shaders.dir/clean

KronUIGL/Shaders/CMakeFiles/shaders.dir/depend:
	cd /home/orangepi/code/XRHS/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/orangepi/code/XRHS/src /home/orangepi/code/XRHS/Dependencies/KronUI/src/KronUIGL/Shaders /home/orangepi/code/XRHS/src /home/orangepi/code/XRHS/src/KronUIGL/Shaders /home/orangepi/code/XRHS/src/KronUIGL/Shaders/CMakeFiles/shaders.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : KronUIGL/Shaders/CMakeFiles/shaders.dir/depend

