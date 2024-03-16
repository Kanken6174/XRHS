#include "./Shapes.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>

std::vector<Vertex> from3FloatVector(std::vector<float> floats){
    std::vector<Vertex> vertices;
    for(int i = 0; i < floats.size(); i+=3){
        Vertex v;
        v.Position = glm::vec3(floats[i],floats[i+1],floats[i+2]);
        v.Normal = glm::vec3(0.5f,0.5f,0.5f);
        v.TexCoords = glm::vec2(0.5f,0.5f);
        vertices.push_back(v);
    }
    return vertices;
}

X2DPoint::X2DPoint(const glm::vec3& position) : shapeElement(), _position(position){
    vertices.clear();
    vertices.resize(VERTICES_SIZE);
    verticesAmount = VERTICES_SIZE;
}

X2DPoint::X2DPoint(const glm::vec2& position) : shapeElement(), _position(glm::vec3(position.x,position.y,0.0f)){
    vertices.clear();
    vertices.resize(VERTICES_SIZE);
    verticesAmount = VERTICES_SIZE;
}

X2DPoint::X2DPoint(const float& x, const float& y) : X2DPoint(glm::vec2(x,y)){
}

X2DPoint::X2DPoint() : shapeElement(){
    vertices.clear();
    vertices.resize(VERTICES_SIZE);
    verticesAmount = VERTICES_SIZE;
}

X2DPoint::X2DPoint(const X2DPoint& p) : shapeElement(), _position(p._position){
    vertices.clear();
    vertices.resize(VERTICES_SIZE);
    verticesAmount = VERTICES_SIZE;
}

std::vector<float> X2DPoint::generateVertices(){
    vertices[0] = _position.x;
    vertices[1] = _position.y;
    vertices[2] = _position.z;
    std::cout << vertices.size() << std::endl;
    return vertices;
}

Line::Line(X2DPoint begin, X2DPoint end, float thickness) : shapeElement(), _begin(begin), _end(end), _thickness(thickness){
    vertices.clear();
    vertices.resize(2*VERTICES_SIZE);
    verticesAmount = 2*VERTICES_SIZE;
}

std::vector<float> Line::generateVertices(){
    std::vector<float> begin_vert = _begin.generateVertices();
    std::vector<float> end_vert = _end.generateVertices();
    for(int i = 0; i < VERTICES_SIZE; i++){
        vertices[i] = begin_vert[i];
        vertices[VERTICES_SIZE+i] = end_vert[i];
    }
    
    return vertices;
}

Triangle::Triangle(X2DPoint points[3]) : DrawableElement(){
    vertices.clear();
    vertices.resize(3*VERTICES_SIZE);
    verticesAmount = 3*VERTICES_SIZE; std::cout << "amnt vert" <<std::endl;
    for(int i  = 0; i < 3; i++){ std::cout << "for point" <<std::endl;
        _points[i] = X2DPoint(points[i].getVector());
    }
    vertices.resize(verticesAmount);
}  

Triangle::Triangle(const glm::vec2& point1, const glm::vec2& point2, const glm::vec2& point3){
    vertices.clear();
    verticesAmount = 3*VERTICES_SIZE;
    _points[0] = X2DPoint(glm::vec3(point1.x,point1.y,0.0f));
    _points[1] = X2DPoint(glm::vec3(point2.x,point2.y,0.0f));
    _points[2] = X2DPoint(glm::vec3(point3.x,point3.y,0.0f));
    vertices.resize(verticesAmount);
}

Triangle::Triangle(const X2DPoint& point1, const X2DPoint& point2, const X2DPoint& point3) : DrawableElement(){
    vertices.clear();
    verticesAmount = 3*VERTICES_SIZE;
    _points[0] = X2DPoint(point1);
    _points[1] = X2DPoint(point2);
    _points[2] = X2DPoint(point3);
    vertices.resize(verticesAmount);
}

Triangle::Triangle() : DrawableElement(){
    std::cout << "Tri constr" <<std::endl;
    vertices.clear();
    verticesAmount = 3*VERTICES_SIZE;
    vertices.resize(verticesAmount);
}

Triangle::Triangle(const Triangle& t) : DrawableElement(){
    std::cout << "Tri copy" <<std::endl;
    vertices.clear();
    verticesAmount = 3*VERTICES_SIZE;
    vertices.resize(verticesAmount);
    for(int i  = 0; i < 3; i++){
        _points[i] = t._points[i];
    }
}

std::vector<float> Triangle::generateVertices(){
    for(int i  = 0; i < 3; i++){
        std::vector<float> verts = _points[i].generateVertices();
        Logger::getInstance().warn("verts size: " + std::to_string(verts.size()));
        for(int j = 0; j < VERTICES_SIZE; j++)
                vertices[i*VERTICES_SIZE+j] = verts[j];
    }
    return vertices;
}

Rectangle::Rectangle(X2DPoint points[4]) : DrawableElement(){
    vertices.clear();
    verticesAmount = 2*3*VERTICES_SIZE;
    vertices.resize(verticesAmount);
    Triangle t1 = Triangle(points[0],points[1],points[2]);
    Triangle t2 = Triangle(points[1],points[2],points[3]);
    _triangles.push_back(t1);
    _triangles.push_back(t2);
}

Rectangle::Rectangle() : DrawableElement(){
    vertices.clear();
    verticesAmount = 2*3*VERTICES_SIZE;
    vertices.resize(verticesAmount);
}

Rectangle::Rectangle(const Rectangle& t) : DrawableElement(){
    vertices.clear();
    verticesAmount = 2*3*VERTICES_SIZE;
    vertices.resize(verticesAmount);
    for(Triangle t : t._triangles)
        _triangles.push_back(t);
}

Rectangle::Rectangle(const glm::vec2& size) : DrawableElement(), size(size) {
    vertices.clear();
    verticesAmount = 2*3*VERTICES_SIZE;
    vertices.resize(verticesAmount);
    // assuming X2DPoint is glm::vec3, if not you might need to adjust accordingly
    Triangle t1 = Triangle(glm::vec2(0.0f, 0.0f), glm::vec2(0.0f, size.y), glm::vec2(size.x, 0.0f));
    Triangle t2 = Triangle(glm::vec2(size.x, 0.0f), glm::vec2(0.0f, size.y), glm::vec2(size.x, size.y));
    _triangles.push_back(t1);
    _triangles.push_back(t2);
}

std::vector<float> Rectangle::generateVertices() {
    std::vector<float> vertices = std::vector<float>();
    for(Triangle t : _triangles){
        std::vector<float> verts = t.generateVertices();
        vertices.insert(vertices.end(), verts.begin(), verts.end());
    }

    return vertices;
}

EmptyRectangle::EmptyRectangle(X2DPoint points[4], float thickness) : DrawableElement(),_thickness(thickness){
    mode = RenderMode::Triangles;
    vertices.clear();
    verticesAmount = 4*2*3*VERTICES_SIZE;   //4 rectangles, * 2 triangles * 3 points * Verticies size
    vertices.resize(verticesAmount);
    for(int i  = 0; i < 4; i++)
        _points[i] = points[i]; //setup the 4 corner points
    //get the width/height of the rectangle
    float width = std::abs(_points[0].getVector().x -_points[1].getVector().x);
    float height = std::abs(_points[1].getVector().y -_points[2].getVector().y);
}

EmptyRectangle::EmptyRectangle(glm::vec3 origin,float width, float height, float thickness) : DrawableElement(), origin(origin), _width(width), _height(height), _thickness(thickness){
    mode = RenderMode::Triangles;

    vertices.clear();

    glm::vec3 heightOffset = glm::vec3(0,height,0);
    glm::vec3 widthOffset = glm::vec3(width,0,0);
}

std::vector<float> EmptyRectangle::generateVertices(){
    std::cout << "in verts" <<std::endl;
    glm::vec3 YOffset = glm::vec3(0,_height,0);
    glm::vec3 XOffset = glm::vec3(_width,0,0);
    glm::vec3 thicknessOffSetX = glm::vec3(_thickness,0,0);
    glm::vec3 thicknessOffSetY = glm::vec3(0,_thickness,0);
    glm::vec3 centerPoint = glm::vec3(_width/2,_height/2,0);
    std::cout << "done offsets" <<std::endl;
    
    //Y 
    //<thickness>
    //2***3***...
    //**  * next
    //* * ****...
    //*  **
    //0***1 X
    //*********
    //* previous
    //*********
    X2DPoint pointsA[4] = {X2DPoint(glm::vec3(origin)),                                  //bottom left
                        X2DPoint(glm::vec3(origin+thicknessOffSetX)),                 //bottom right
                        X2DPoint(glm::vec3(origin+YOffset)),                          //top left
                        X2DPoint(glm::vec3(origin+YOffset+thicknessOffSetX))  //top right
                        };
    _sides[0] = Rectangle(pointsA);

    //Y                    
    //2********************3    ↑
    //*         *          *    Thickness
    //0********************1 X  ↓
    //                *    *
    //                *next*
    origin = pointsA[2].getVector();
    X2DPoint pointsB[4] = {X2DPoint(glm::vec3(origin)),    //bottom left
                        X2DPoint(glm::vec3(origin+XOffset)),    //bottom right
                        X2DPoint(glm::vec3(origin+thicknessOffSetY)),                //top left
                        X2DPoint(glm::vec3(origin+XOffset+thicknessOffSetY))     //top right
                        };
    _sides[1] = Rectangle(pointsB);
    //********
    //       *
    //***2***3
    //   **  *
    //**** * *
    //   *  **
    //***0***1
    
    origin = pointsB[1].getVector()-YOffset-thicknessOffSetX;
    X2DPoint pointsC[4] = {X2DPoint(glm::vec3(origin)),                                  //bottom left
                        X2DPoint(glm::vec3(origin+thicknessOffSetX)),                 //bottom right
                        X2DPoint(glm::vec3(origin+YOffset)),                          //top left
                        X2DPoint(glm::vec3(origin+YOffset+thicknessOffSetX))  //top right
                        };
    _sides[2] = Rectangle(pointsC);

    //Y
    //* N *            * P *
    //2****************3   *    ↑
    //*         *      *   *    Thickness
    //0****************1**** X  ↓
    //
    //
    
    origin = pointsC[0].getVector()-thicknessOffSetY;
    X2DPoint pointsD[4] = {X2DPoint(glm::vec3(origin-XOffset+thicknessOffSetX)),    //bottom left
                        X2DPoint(glm::vec3(origin+thicknessOffSetX)),    //bottom right
                        X2DPoint(glm::vec3(origin+thicknessOffSetY-XOffset+thicknessOffSetX)),                //top left
                        X2DPoint(glm::vec3(origin+thicknessOffSetY+thicknessOffSetX))     //top right
                        };
    _sides[3] = Rectangle(pointsD);
    //-------------------------------------
    std::cout << "done verts" <<std::endl;
    std::vector<float> sideVertices;
    for(int i = 0; i < 4; i++){
        sideVertices = _sides[i].generateVertices();
        std::cout << "sideVertices.size() " << sideVertices.size() << std::endl;

        // Print out the contents of sideVertices
        for(int j = 0; j < sideVertices.size(); j++) {
            std::cout << sideVertices[j] << " ";
        }
        std::cout << std::endl;

        std::cout << "vertices.size() before insertion " << vertices.size() << std::endl;
        vertices.insert(vertices.end(), sideVertices.begin(), sideVertices.end());
        std::cout << "vertices.size() after insertion " << vertices.size() << std::endl;
    }

    
    return vertices;
}

DefaultCube::DefaultCube(float width, float height, float thickness, float offsetX, float offsetY, float offsetZ) 
    : width(width), height(height), thickness(thickness), offsetX(offsetX), offsetY(offsetY), offsetZ(offsetZ) {
    mode = RenderMode::Triangles;
}

std::vector<float> DefaultCube::generateVertices() {
    float halfW = width / 2.0f;
    float halfH = height / 2.0f;
    float halfT = thickness / 2.0f;

    vertices = std::vector<float>({
        -halfW + offsetX, -halfH + offsetY, -halfT + offsetZ,
         halfW + offsetX, -halfH + offsetY, -halfT + offsetZ,
         halfW + offsetX,  halfH + offsetY, -halfT + offsetZ,
         halfW + offsetX,  halfH + offsetY, -halfT + offsetZ,
        -halfW + offsetX,  halfH + offsetY, -halfT + offsetZ,
        -halfW + offsetX, -halfH + offsetY, -halfT + offsetZ,

        -halfW + offsetX, -halfH + offsetY,  halfT + offsetZ,
         halfW + offsetX, -halfH + offsetY,  halfT + offsetZ,
         halfW + offsetX,  halfH + offsetY,  halfT + offsetZ,
         halfW + offsetX,  halfH + offsetY,  halfT + offsetZ,
        -halfW + offsetX,  halfH + offsetY,  halfT + offsetZ,
        -halfW + offsetX, -halfH + offsetY,  halfT + offsetZ,

        -halfW + offsetX,  halfH + offsetY,  halfT + offsetZ,
        -halfW + offsetX,  halfH + offsetY, -halfT + offsetZ,
        -halfW + offsetX, -halfH + offsetY, -halfT + offsetZ,
        -halfW + offsetX, -halfH + offsetY, -halfT + offsetZ,
        -halfW + offsetX, -halfH + offsetY,  halfT + offsetZ,
        -halfW + offsetX,  halfH + offsetY,  halfT + offsetZ,

         halfW + offsetX,  halfH + offsetY,  halfT + offsetZ,
         halfW + offsetX,  halfH + offsetY, -halfT + offsetZ,
         halfW + offsetX, -halfH + offsetY, -halfT + offsetZ,
         halfW + offsetX, -halfH + offsetY, -halfT + offsetZ,
         halfW + offsetX, -halfH + offsetY,  halfT + offsetZ,
         halfW + offsetX,  halfH + offsetY,  halfT + offsetZ,

        -halfW + offsetX, -halfH + offsetY, -halfT + offsetZ,
         halfW + offsetX, -halfH + offsetY, -halfT + offsetZ,
         halfW + offsetX, -halfH + offsetY,  halfT + offsetZ,
         halfW + offsetX, -halfH + offsetY,  halfT + offsetZ,
        -halfW + offsetX, -halfH + offsetY,  halfT + offsetZ,
        -halfW + offsetX, -halfH + offsetY, -halfT + offsetZ,

        -halfW + offsetX,  halfH + offsetY, -halfT + offsetZ,
         halfW + offsetX,  halfH + offsetY, -halfT + offsetZ,
         halfW + offsetX,  halfH + offsetY,  halfT + offsetZ,
         halfW + offsetX,  halfH + offsetY,  halfT + offsetZ,
        -halfW + offsetX,  halfH + offsetY,  halfT + offsetZ,
        -halfW + offsetX,  halfH + offsetY, -halfT + offsetZ
    });

    return vertices;
}

std::shared_ptr<Mesh> DefaultCube::DirectDefaultMesh(float scale){
    DefaultCube dt = DefaultCube(scale,scale,scale);
    std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(from3FloatVector(dt.generateVertices()), 
        std::vector<unsigned int>(), 
        std::vector<Texture>());
    //also generate opengl indices
    std::vector<unsigned int> indices;
    for(int i = 0; i < mesh->vertices.size(); i++)
        indices.push_back(i);
    mesh->indices = indices;

    //print all veticies, on XYZ (each verticies have a position attribute, which is a vec3 of 3 floats)
    for(int i = 0; i < mesh->vertices.size(); i++){
        std::cout << mesh->vertices.at(i).Position.x << ", " << mesh->vertices.at(i).Position.y << ", " << mesh->vertices.at(i).Position.z << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
    return mesh;
};