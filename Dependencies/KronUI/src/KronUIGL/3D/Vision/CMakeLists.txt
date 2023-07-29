set(CMAKE_CXX_STANDARD 17)

set(local_src
    ./camera.cpp
    ./camera.hpp)

find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

set(Assimp_DIR /usr/lib/x86_64-linux-gnu/cmake/assimp-5.2/)
find_package(assimp REQUIRED)

add_library(vision ${local_src})

set_target_properties(vision PROPERTIES LINKER_LANGUAGE CXX)

set_target_properties(vision PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(vision GLEW)
target_link_libraries(vision glfw)
target_link_libraries(vision assimp)