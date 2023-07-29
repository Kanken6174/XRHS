set(TTM_src
    ./TrueTypeManager.cpp
    ./TrueTypeManager.hpp)
    
MESSAGE(STATUS "building TTM")

include_directories (/usr/include/freetype2)
find_package(Freetype REQUIRED)

find_package(GLEW REQUIRED)

set(glm_DIR /usr/include/glm)
find_package(glm REQUIRED)

add_library(TTM ${TTM_src})

target_link_libraries(TTM ${FREETYPE_LIBRARIES})
target_link_libraries(TTM GLEW)
#target_link_libraries(TTM glm)

MESSAGE(STATUS "Done building TTM")