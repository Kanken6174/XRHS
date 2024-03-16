set(textRenderer_src
    ./TextRenderer.hpp
    ./TextRenderer.cpp)

set(glm_DIR /usr/include/glm)
find_package(glm REQUIRED)

include_directories (/usr/include/freetype2)
find_package(Freetype REQUIRED)

add_library(textrenderer ${textRenderer_src})

#target_link_libraries(textrenderer glm)
target_link_libraries(textrenderer shaders)
target_link_libraries(textrenderer window)
target_link_libraries(textrenderer ${FREETYPE_LIBRARIES})
target_link_libraries(textrenderer TTM)