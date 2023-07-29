set(shaders_src
    ./Shader.hpp
    ./ShaderManager.cpp
    ./ShaderManager.hpp)

include_directories (/usr/include/freetype2)
find_package(Freetype REQUIRED)

find_package(GLEW REQUIRED)

set(glm_DIR /usr/include/glm)
find_package(glm REQUIRED)

add_library(shaders ${shaders_src})

target_link_libraries(shaders GLEW)
#target_link_libraries(shaders glm)
target_link_libraries(shaders paints)
target_link_libraries(shaders bases)
target_link_libraries(shaders 3D)