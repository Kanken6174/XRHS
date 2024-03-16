set(CMAKE_CXX_STANDARD 17)

set(local_src
    ./OBJLoader.cpp
    ./OBJLoader.hpp)

find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

set(Assimp_DIR /usr/lib/x86_64-linux-gnu/cmake/assimp-5.2/)
find_package(assimp REQUIRED)

add_library(loaders ${local_src})

set_target_properties(loaders PROPERTIES LINKER_LANGUAGE CXX)

set_target_properties(loaders PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(loaders GLEW)
target_link_libraries(loaders glfw)
target_link_libraries(loaders assimp)
target_link_libraries(loaders elements)