set(CMAKE_CXX_STANDARD 17)

set(local_src
    ./MeshRenderer.cpp
    ./MeshRenderer.hpp)

find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

set(Assimp_DIR /usr/lib/x86_64-linux-gnu/cmake/assimp-5.2/)
find_package(assimp REQUIRED)

add_library(renderers ${local_src})

set_target_properties(renderers PROPERTIES LINKER_LANGUAGE CXX)

set_target_properties(renderers PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(renderers GLEW)
target_link_libraries(renderers glfw)
target_link_libraries(renderers assimp)
target_link_libraries(renderers elements)