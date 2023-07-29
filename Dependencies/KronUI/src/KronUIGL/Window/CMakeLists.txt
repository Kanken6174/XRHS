set(window_src
    ./KronUIWindow.hpp
    ./KronUIWindow.cpp)

find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

add_library(window ${window_src})

link_libraries(window GLEW)
link_libraries(window glfw)