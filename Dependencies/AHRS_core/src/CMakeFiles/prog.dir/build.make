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
CMAKE_BINARY_DIR = /home/kanken/code/AHRS_core/src

# Include any dependencies generated for this target.
include CMakeFiles/prog.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/prog.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/prog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prog.dir/flags.make

CMakeFiles/prog.dir/main.cpp.o: CMakeFiles/prog.dir/flags.make
CMakeFiles/prog.dir/main.cpp.o: main.cpp
CMakeFiles/prog.dir/main.cpp.o: CMakeFiles/prog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanken/code/AHRS_core/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/prog.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/prog.dir/main.cpp.o -MF CMakeFiles/prog.dir/main.cpp.o.d -o CMakeFiles/prog.dir/main.cpp.o -c /home/kanken/code/AHRS_core/src/main.cpp

CMakeFiles/prog.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prog.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanken/code/AHRS_core/src/main.cpp > CMakeFiles/prog.dir/main.cpp.i

CMakeFiles/prog.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prog.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanken/code/AHRS_core/src/main.cpp -o CMakeFiles/prog.dir/main.cpp.s

CMakeFiles/prog.dir/topLevelManager.cpp.o: CMakeFiles/prog.dir/flags.make
CMakeFiles/prog.dir/topLevelManager.cpp.o: topLevelManager.cpp
CMakeFiles/prog.dir/topLevelManager.cpp.o: CMakeFiles/prog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanken/code/AHRS_core/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/prog.dir/topLevelManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/prog.dir/topLevelManager.cpp.o -MF CMakeFiles/prog.dir/topLevelManager.cpp.o.d -o CMakeFiles/prog.dir/topLevelManager.cpp.o -c /home/kanken/code/AHRS_core/src/topLevelManager.cpp

CMakeFiles/prog.dir/topLevelManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prog.dir/topLevelManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanken/code/AHRS_core/src/topLevelManager.cpp > CMakeFiles/prog.dir/topLevelManager.cpp.i

CMakeFiles/prog.dir/topLevelManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prog.dir/topLevelManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanken/code/AHRS_core/src/topLevelManager.cpp -o CMakeFiles/prog.dir/topLevelManager.cpp.s

# Object files for target prog
prog_OBJECTS = \
"CMakeFiles/prog.dir/main.cpp.o" \
"CMakeFiles/prog.dir/topLevelManager.cpp.o"

# External object files for target prog
prog_EXTERNAL_OBJECTS =

prog: CMakeFiles/prog.dir/main.cpp.o
prog: CMakeFiles/prog.dir/topLevelManager.cpp.o
prog: CMakeFiles/prog.dir/build.make
prog: pipeline/libpipelineLib.a
prog: pluginManagement/libPluginManager.a
prog: pipeline/libpipelineLib.a
prog: pluginManagement/libPluginManager.a
prog: model/windows/libwindows.a
prog: ui/support/libsupport.a
prog: model/controllers/libcontrollers.a
prog: /usr/lib/x86_64-linux-gnu/libOpenGL.so
prog: /usr/lib/x86_64-linux-gnu/libGLX.so
prog: /usr/lib/x86_64-linux-gnu/libGLU.so
prog: model/hardware/psvr/libpsvr.a
prog: model/hardware/ihidapi/libihidapi.a
prog: /usr/local/lib/libhidapi-hidraw.so.0.13.0
prog: model/hardware/cameras/libcameras.a
prog: model/hardware/hw/libhw.a
prog: model/hardware/hw/extendables/libhw_ext.a
prog: model/patterns/observer/libobservers.a
prog: threadweaver/libthreadweaver.a
prog: model/perfcheckers/libperfcheckers.a
prog: processing/zbar/libzbarLib.a
prog: /usr/local/lib/libopencv_gapi.so.4.6.0
prog: /usr/local/lib/libopencv_stitching.so.4.6.0
prog: /usr/local/lib/libopencv_aruco.so.4.6.0
prog: /usr/local/lib/libopencv_barcode.so.4.6.0
prog: /usr/local/lib/libopencv_bgsegm.so.4.6.0
prog: /usr/local/lib/libopencv_bioinspired.so.4.6.0
prog: /usr/local/lib/libopencv_ccalib.so.4.6.0
prog: /usr/local/lib/libopencv_dnn_objdetect.so.4.6.0
prog: /usr/local/lib/libopencv_dnn_superres.so.4.6.0
prog: /usr/local/lib/libopencv_dpm.so.4.6.0
prog: /usr/local/lib/libopencv_face.so.4.6.0
prog: /usr/local/lib/libopencv_freetype.so.4.6.0
prog: /usr/local/lib/libopencv_fuzzy.so.4.6.0
prog: /usr/local/lib/libopencv_hfs.so.4.6.0
prog: /usr/local/lib/libopencv_img_hash.so.4.6.0
prog: /usr/local/lib/libopencv_intensity_transform.so.4.6.0
prog: /usr/local/lib/libopencv_line_descriptor.so.4.6.0
prog: /usr/local/lib/libopencv_mcc.so.4.6.0
prog: /usr/local/lib/libopencv_quality.so.4.6.0
prog: /usr/local/lib/libopencv_rapid.so.4.6.0
prog: /usr/local/lib/libopencv_reg.so.4.6.0
prog: /usr/local/lib/libopencv_rgbd.so.4.6.0
prog: /usr/local/lib/libopencv_saliency.so.4.6.0
prog: /usr/local/lib/libopencv_stereo.so.4.6.0
prog: /usr/local/lib/libopencv_structured_light.so.4.6.0
prog: /usr/local/lib/libopencv_phase_unwrapping.so.4.6.0
prog: /usr/local/lib/libopencv_superres.so.4.6.0
prog: /usr/local/lib/libopencv_optflow.so.4.6.0
prog: /usr/local/lib/libopencv_surface_matching.so.4.6.0
prog: /usr/local/lib/libopencv_tracking.so.4.6.0
prog: /usr/local/lib/libopencv_highgui.so.4.6.0
prog: /usr/local/lib/libopencv_datasets.so.4.6.0
prog: /usr/local/lib/libopencv_plot.so.4.6.0
prog: /usr/local/lib/libopencv_text.so.4.6.0
prog: /usr/local/lib/libopencv_videostab.so.4.6.0
prog: /usr/local/lib/libopencv_videoio.so.4.6.0
prog: /usr/local/lib/libopencv_wechat_qrcode.so.4.6.0
prog: /usr/local/lib/libopencv_xfeatures2d.so.4.6.0
prog: /usr/local/lib/libopencv_ml.so.4.6.0
prog: /usr/local/lib/libopencv_shape.so.4.6.0
prog: /usr/local/lib/libopencv_ximgproc.so.4.6.0
prog: /usr/local/lib/libopencv_video.so.4.6.0
prog: /usr/local/lib/libopencv_xobjdetect.so.4.6.0
prog: /usr/local/lib/libopencv_imgcodecs.so.4.6.0
prog: /usr/local/lib/libopencv_objdetect.so.4.6.0
prog: /usr/local/lib/libopencv_calib3d.so.4.6.0
prog: /usr/local/lib/libopencv_dnn.so.4.6.0
prog: /usr/local/lib/libopencv_features2d.so.4.6.0
prog: /usr/local/lib/libopencv_flann.so.4.6.0
prog: /usr/local/lib/libopencv_xphoto.so.4.6.0
prog: /usr/local/lib/libopencv_photo.so.4.6.0
prog: /usr/local/lib/libopencv_imgproc.so.4.6.0
prog: /usr/local/lib/libopencv_core.so.4.6.0
prog: /usr/lib/x86_64-linux-gnu/libzbar.so
prog: CMakeFiles/prog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kanken/code/AHRS_core/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable prog"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prog.dir/build: prog
.PHONY : CMakeFiles/prog.dir/build

CMakeFiles/prog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prog.dir/clean

CMakeFiles/prog.dir/depend:
	cd /home/kanken/code/AHRS_core/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kanken/code/AHRS_core/src /home/kanken/code/AHRS_core/src /home/kanken/code/AHRS_core/src /home/kanken/code/AHRS_core/src /home/kanken/code/AHRS_core/src/CMakeFiles/prog.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prog.dir/depend

