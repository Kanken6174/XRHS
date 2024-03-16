#pragma once
#include <assimp/scene.h>
#include <string>
#include <vector>
#include "../../../../include/stb_image.h"
#include <GL/glew.h>
#include "../../../../include/logger.hpp"


class Texture {
public:
    unsigned int id;
    std::vector<float> textureCoordinates;
    std::string type;
    aiString path;

    static Texture loadFromPng(const std::string& filename) {
        Texture texture;

        int width, height, numComponents;
        unsigned char* data = stbi_load(filename.c_str(), &width, &height, &numComponents, 4);
        
        if (data != nullptr) {
            glGenTextures(1, &texture.id);
            glBindTexture(GL_TEXTURE_2D, texture.id);

            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

            // set the texture wrapping/filtering options
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            stbi_image_free(data);
        } else {
            Logger::getInstance().error("Texture failed to load at path: " + filename);
        }

        return texture;
    }
};