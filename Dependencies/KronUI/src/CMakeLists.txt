cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_DEBUG "-g -Ofast -fPIC")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -fPIC")
set(OpenGL_GL_PREFERENCE GLVND)

project(KronUI)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
include_directories (/usr/include/freetype2)
find_package(Freetype REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

add_subdirectory(Bases)
add_subdirectory(Freetype)
add_subdirectory(KronUIGL)
#add_subdirectory(Intersector)

set(main_source_files main.cpp)

add_executable(KronUI ${main_source_files})

MESSAGE(STATUS "CMAKE FLAGS : ${LINK_OPTIONS}")

target_link_libraries(KronUI ${GLEW_LIBRARIES} ${OPENGL_LIBRARY} glfw bases TTM KronUIGL ${FREETYPE_LIBRARIES})

SET(GCC_COVERAGE_COMPILE_FLAGS "-L/usr/local/lib -I/usr/include/glm")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})