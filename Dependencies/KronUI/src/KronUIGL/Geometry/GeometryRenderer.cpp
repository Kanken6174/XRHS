#include "./GeometryRenderer.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../Shaders/ShaderManager.hpp"

//global invisible draw function stored in the object to draw (self call)
void drawGeometry(DrawableElement* toDraw){
    ShaderManager::getInstance()->setShader(toDraw->shader);
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(400), 0.0f, static_cast<float>(600));
    switch(toDraw->mode){
        case RenderMode::Triangles:
                glDisable(GL_CULL_FACE);
                //std::cout << "drawing: " << toDraw->bufferID << " verticies: " << toDraw->verticesAmount << std::endl;
                // 1st attribute buffer : vertices
                glBindBuffer(GL_ARRAY_BUFFER, toDraw->bufferID);
                glVertexAttribPointer(
                0,                   // attribute 0. No particular reason for 0, but must match the layout in the shader.
                3,                   //3 (xyz) per verticies
                GL_FLOAT,            // type
                GL_FALSE,            // normalized?
                3*sizeof(float),   // stride
                (void*)0             // array buffer offset
                );
                glEnableVertexAttribArray(0);
                glDrawArrays(GL_TRIANGLES, 0, toDraw->verticesAmount); // Starting from vertex 0; 3 vertices total -> 1 triangle
                glDisableVertexAttribArray(0);
        break;
        default:
        break;
    }
}

void GeometryRenderer::addShapeToBuffer(DrawableElement* toRender){
    std::vector<float> verticies = toRender->generateVertices();
    toRender->verticesAmount = verticies.size();
    float* arr = new float[toRender->verticesAmount];
    for (const auto &value : verticies) {
        std::cout << value << ' ';
    }
    std::cout << std::endl;

    std::copy(verticies.begin(), verticies.end(), arr); //transfer data to the heap
    int i = 0;

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