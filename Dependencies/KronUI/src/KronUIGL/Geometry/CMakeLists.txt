set(Geometry_src
    ./Drawing.hpp
    ./Shapes.hpp
    ./Shapes.cpp
    ./GeometryRenderer.cpp
    ./GeometryRenderer.hpp)

set(glm_DIR /usr/include/glm)
find_package(glm REQUIRED)

find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

add_library(geometry ${Geometry_src})

set_target_properties(geometry PROPERTIES LINKER_LANGUAGE CXX)

#target_link_libraries(geometry glm)
target_link_libraries(geometry GLEW)
target_link_libraries(geometry glfw)