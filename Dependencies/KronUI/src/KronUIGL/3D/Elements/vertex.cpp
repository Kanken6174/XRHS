#include "vertex.hpp"

std::vector<Vertex> from3FloatVector(std::vector<float> floats){
    std::vector<Vertex> vertices;
    for(int i = 0; i < floats.size(); i+=3){
        Vertex v;
        v.Position = glm::vec3(floats[i],floats[i+1],floats[i+2]);
        vertices.push_back(v);
    }
    return vertices;
}