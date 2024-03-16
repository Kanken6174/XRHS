#include "./GeometryRenderer.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../Shaders/ShaderManager.hpp"
#include "./Shapes.hpp"

//global invisible draw function stored in the object to draw (self call)
void drawGeometry(DrawableElement* toDraw){
    ShaderManager::getInstance()->setShader(toDraw->shader);
    toDraw->shader->setVec4("geomColor", toDraw->geomColor);
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(400), 0.0f, static_cast<float>(600));
                glDisable(GL_CULL_FACE);
                glBindBuffer(GL_ARRAY_BUFFER, toDraw->bufferID);
                glVertexAttribPointer(
                0,                   // attribute 0. No particular reason for 0, but must match the layout in the shader.
                3,                   //3 (xyz) per verticies
                GL_FLOAT,            // type
                GL_FALSE,            // normalized?
                3*sizeof(float),     // stride
                (void*)0             // array buffer offset
                );
                glEnableVertexAttribArray(0);
                glDrawArrays(toDraw->mode == RenderMode::Triangles ? GL_TRIANGLES : GL_TRIANGLE_FAN, 0, toDraw->verticesAmount/VERTICES_SIZE); // Starting from vertex 0; 3 vertices total -> 1 triangle
                glDisableVertexAttribArray(0);
}

void GeometryRenderer::prepareShape(std::shared_ptr<DrawableElement> toRender){
    std::vector<float> verticies = toRender->generateVertices();
    toRender->verticesAmount = verticies.size();
    toRender->shader = shader;
    float* arr = new float[toRender->verticesAmount];

    std::copy(verticies.begin(), verticies.end(), arr); //transfer data to the heap

    GLuint vertexhandle;
    glGenBuffers(1, &vertexhandle);
    glBindBuffer(GL_ARRAY_BUFFER, vertexhandle);
    glBufferData(GL_ARRAY_BUFFER, toRender->verticesAmount * sizeof(float), arr, GL_STATIC_DRAW);

    float* bufferData = new float[toRender->verticesAmount];
    glGetBufferSubData(GL_ARRAY_BUFFER, 0, toRender->verticesAmount * sizeof(float), bufferData);

    std::cout << "Buffer contents:" << std::endl;
    for(int i = 0; i < toRender->verticesAmount; ++i) {
        std::cout << bufferData[i] << ' ';
    }
    std::cout << std::endl;

    arrays[vertexhandle] = arr;

    toRender->bufferID = vertexhandle;
    toRender->drawerFunction = &drawGeometry;
    toRender->mode = RenderMode::Triangles;

    std::cout << "shape added to buffer: " << toRender->bufferID << std::endl;
}