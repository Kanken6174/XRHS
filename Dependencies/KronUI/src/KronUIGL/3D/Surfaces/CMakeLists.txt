cmake_minimum_required(VERSION 3.10)
project(surfaces)

set(CMAKE_CXX_STANDARD 17)

set(local_src
    ./DrawSurface.cpp
    ./DrawSurface.hpp
    ./VideoFrame.hpp)

find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

set(Assimp_DIR /usr/lib/x86_64-linux-gnu/cmake/assimp-5.2/)
find_package(assimp REQUIRED)

# Find X11
find_package(X11 REQUIRED)
if (NOT X11_Xinerama_FOUND)
  message(STATUS "Xinerama not found")
endif()

add_library(surfaces ${local_src})

set_target_properties(surfaces PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(surfaces GLEW)
target_link_libraries(surfaces glfw)
target_link_libraries(surfaces assimp)

# Link against X11 and Xinerama
if (X11_FOUND AND X11_Xinerama_FOUND)
  include_directories(${X11_INCLUDE_DIR})
  target_link_libraries(surfaces ${X11_LIBRARIES} ${X11_Xinerama_LIB})
else()
  message(STATUS "X11 or Xinerama not found")
endif()