set(CMAKE_CXX_STANDARD 17)

set(input_SRC
    ./Input.cpp
    ./Input.hpp)

set(glm_DIR /usr/include/glm)
find_package(glm REQUIRED)

find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

add_library(input ${input_SRC})

set_target_properties(input PROPERTIES LINKER_LANGUAGE CXX)

set_target_properties(input PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(input GLEW)
target_link_libraries(input glfw)
target_link_libraries(input 3D)