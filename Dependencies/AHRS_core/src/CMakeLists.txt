cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(OpenGL_GL_PREFERENCE GLVND)

project(visnode)

find_package(OpenCV REQUIRED)
find_package(TBB REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${CMAKE_BINARY_DIR})

MESSAGE(STATUS "OpenCV_INCLUDE_DIRS : ${OpenCV_INCLUDE_DIRS}")
MESSAGE(STATUS "Opencv_LINK_DIRS : ${Opencv_LINK_DIRS}")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_subdirectory(threadweaver)
add_subdirectory(model/perfcheckers)
add_subdirectory(model/hardware/ihidapi)
add_subdirectory(model/hardware/cameras)
add_subdirectory(model/hardware/psvr)
add_subdirectory(model/hardware/hw/extendables)
add_subdirectory(model/hardware/hw)
add_subdirectory(model/controllers)
add_subdirectory(model/patterns/observer)
add_subdirectory(model/patterns/commands)
add_subdirectory(processing/zbar)
add_subdirectory(model/windows)
add_subdirectory(ui/support)
add_subdirectory(pipeline)
add_subdirectory(pluginManagement)

set(main_source_files topLevelManager.cpp topLevelManager.hpp)

add_library(visnode_lib ${main_source_files})

MESSAGE(STATUS "CMAKE FLAGS : ${LINK_OPTIONS}")

target_link_libraries(visnode_lib pipelineLib tbb Threads::Threads)

SET(GCC_COVERAGE_COMPILE_FLAGS "-L/usr/local/lib")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})