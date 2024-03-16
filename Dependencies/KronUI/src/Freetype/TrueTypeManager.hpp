#ifndef TTM_guard
#define TTM_guard
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>
#include <string>

/// Holds all state information relevant to a character as loaded using FreeType
struct Character {
    unsigned int TextureID; // ID handle of the glyph texture
    glm::ivec2   Size;      // Size of glyph
    glm::ivec2   Bearing;   // Offset from baseline to left/top of glyph
    unsigned int Advance;   // Horizontal offset to advance to next glyph
};

class TrueTypeManager{
public:
    std::map<GLchar, Character> Characters = std::map<GLchar, Character>();
    TrueTypeManager(std::string font_name);
};
#endif