set(KronUIGL_src
    ./KronUIGL.hpp)

#set(glm_DIR /usr/include/glm)
#find_package(glm REQUIRED)

find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

add_library(KronUIGL ${KronUIGL_src})

set_target_properties(KronUIGL PROPERTIES LINKER_LANGUAGE CXX)

#target_link_libraries(geometry glm)
#target_link_libraries(KronUIGL GLEW)
#target_link_libraries(KronUIGL glfw)

add_subdirectory(Geometry)
add_subdirectory(Paints)
add_subdirectory(Shaders)
add_subdirectory(Text)
add_subdirectory(Window)
add_subdirectory(3D)
add_subdirectory(Input)

target_link_libraries(KronUIGL geometry)
target_link_libraries(KronUIGL paints)
target_link_libraries(KronUIGL shaders)
target_link_libraries(KronUIGL textrenderer)
target_link_libraries(KronUIGL window)
target_link_libraries(KronUIGL 3D)
target_link_libraries(KronUIGL input)
