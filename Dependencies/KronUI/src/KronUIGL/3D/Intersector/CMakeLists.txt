set(CMAKE_CXX_STANDARD 17)

set(local_src
    ./Intersector.cpp
    ./Intersector.hpp
    )

find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

set(Assimp_DIR /usr/lib/x86_64-linux-gnu/cmake/assimp-5.2/)
find_package(assimp REQUIRED)

add_library(intersector ${local_src})

set_target_properties(intersector PROPERTIES LINKER_LANGUAGE CXX)

set_target_properties(intersector PROPERTIES LINKER_LANGUAGE CXX)