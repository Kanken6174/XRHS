#include "DrawSurface.hpp"
#include <GL/glew.h>
#include "../../../../include/logger.hpp"
#define GLM_ENABLE_EXPERIMENTAL 1
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../../Shaders/ShaderManager.hpp"
#include "../../Geometry/Shapes.hpp"

DrawSurface::DrawSurface(const glm::vec2& size, std::shared_ptr<Transform> transform) : DrawSurface(size, defaultIndicies(), transform)
{
    _size = size;
    //call other constructor with default indices
    name = "DrawSurfaceEntity";
    customRenderer = true;
}

DrawSurface::DrawSurface(const glm::vec2& size, std::vector<unsigned int> indices, std::shared_ptr<Transform> transform)
{
    mesh = std::make_shared<Mesh>();
    mesh->indices = indices;
    localTransform = transform;
    rect = std::make_shared<Rectangle>(size);
    std::vector<float> vertices = rect->generateVertices();
    //output all the vertices
    for(int i = 0; i < vertices.size(); i++){
        std::cout << ' ' << vertices[i] << std::endl;
    }
    for (int i = 0; i < vertices.size(); i += 3) {
        Vertex v;
        v.Position = glm::vec3(vertices[i], vertices[i + 1], vertices[i + 2]);
        //Texture coordinates. You'll need to adjust these if your vertices aren't arranged in a simple rectangle.
        if (i == 0*VERTICES_SIZE) // bottom-left corner
                v.TexCoords = glm::vec2(0.0f, 0.0f);
            else if (i == 1*VERTICES_SIZE) // bottom-right corner
                v.TexCoords = glm::vec2(1.0f, 0.0f);
            else if (i == 2*VERTICES_SIZE) // top-right corner
                v.TexCoords = glm::vec2(0.0f, 1.0f);
            else if (i == 3*VERTICES_SIZE) // top-left corner
                v.TexCoords = glm::vec2(0.0f, 1.0f);
            else if (i == 4*VERTICES_SIZE) // top-right corner
                v.TexCoords = glm::vec2(1.0f, 0.0f);
            else if (i == 5*VERTICES_SIZE) // top-left corner
                v.TexCoords = glm::vec2(1.0f, 1.0f);
        v.Normal = glm::vec3(0.0f, 0.0f, 0.0f);
        mesh->vertices.push_back(v);
        //log all data
        Logger::getInstance().warn("Vertex: " + std::to_string(v.Position.x) + " " + std::to_string(v.Position.y) + " " + std::to_string(v.Position.z));
        Logger::getInstance().warn("Texture: " + std::to_string(v.TexCoords.x) + " " + std::to_string(v.TexCoords.y));
    }
    glGenBuffers(1, &PBO);
}

void DrawSurface::setupSurface() {
    Logger::getInstance().warn(std::to_string(mesh->vertices.size()));
    // Generate and bind a new texture object
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    // Generate random pixel data
    int width = 1920;
    int height = 1080;
    std::vector<unsigned char> pixelData(3 * width * height);

    // Allocate and populate texture memory
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelData.data());

    // Proceed as in the original method
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, mesh->vertices.size() * sizeof(Vertex), &mesh->vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->indices.size() * sizeof(unsigned int), &mesh->indices[0], GL_STATIC_DRAW);

    // Vertex positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);

    // Texture coordinates
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}
