set(CMAKE_CXX_STANDARD 17)

set(local_src
    ./mesh.hpp
    ./mesh.cpp
    ./texture.hpp
    ./vertex.hpp
    ./transform.hpp
    ./transform.cpp
    ./entity.hpp
    ./entity.cpp
    ./world.hpp
    ./world.cpp
    ./light.hpp
    )

find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

set(Assimp_DIR /usr/lib/x86_64-linux-gnu/cmake/assimp-5.2/)
find_package(assimp REQUIRED)

add_library(elements ${local_src})

set_target_properties(elements PROPERTIES LINKER_LANGUAGE CXX)

set_target_properties(elements PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(elements GLEW)
target_link_libraries(elements glfw)
target_link_libraries(elements assimp)