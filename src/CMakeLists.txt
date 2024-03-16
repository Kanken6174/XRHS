cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_DEBUG "-g -Ofast -fPIC -ldl")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -fPIC -ldl")
set(OpenGL_GL_PREFERENCE GLVND)

project(KronUI)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
include_directories(/usr/include/freetype2)
find_package(Freetype REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

add_subdirectory(${PROJECT_SOURCE_DIR}/../Dependencies/KronUI/src/Bases ${CMAKE_BINARY_DIR}/Bases)
add_subdirectory(${PROJECT_SOURCE_DIR}/../Dependencies/KronUI/src/Freetype ${CMAKE_BINARY_DIR}/Freetype)
add_subdirectory(${PROJECT_SOURCE_DIR}/../Dependencies/KronUI/src/KronUIGL ${CMAKE_BINARY_DIR}/KronUIGL)

add_subdirectory(${PROJECT_SOURCE_DIR}/../Dependencies/AHRS_core/src ${CMAKE_BINARY_DIR}/ARHS)

set(main_source_files main.cpp Glue.hpp)

# Change output directory for the binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

add_executable(KronUI ${main_source_files})

MESSAGE(STATUS "CMAKE FLAGS : ${LINK_OPTIONS}")

target_link_libraries(KronUI ${GLEW_LIBRARIES} ${OPENGL_LIBRARY} glfw bases TTM KronUIGL ${FREETYPE_LIBRARIES} visnode_lib)

SET(GCC_COVERAGE_COMPILE_FLAGS "-L/usr/local/lib -I/usr/include/glm")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

# Copy shaders, Ressources, and media folders to the output directory
file(COPY ${CMAKE_SOURCE_DIR}/shaders DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(COPY ${CMAKE_SOURCE_DIR}/Ressources DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(COPY ${CMAKE_SOURCE_DIR}/media DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(COPY ${CMAKE_SOURCE_DIR}/f2.ttf DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# Find Git to retrieve the current commit hash
find_package(Git QUIET)
if(GIT_FOUND)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_REV
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
else()
    set(GIT_REV "unknown")
endif()

# Detect platform and architecture
set(PLATFORM_INFO "${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR}")

# Create the zip directory if it doesn't exist
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/../zip)

add_custom_target(zip_bin ALL
    COMMAND ${CMAKE_COMMAND} -E echo "Zipping the bin directory..."
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/../zip"
    COMMAND zip -r "${CMAKE_BINARY_DIR}/../zip/XRHS_${GIT_REV}_${PLATFORM_INFO}.zip" .
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    DEPENDS KronUI)

# Ensure the zip is created after the main build
add_dependencies(zip_bin KronUI)
