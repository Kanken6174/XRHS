
#include <glm/glm.hpp>
#include "./Drawing.hpp"
#include "../3D/Elements/mesh.hpp"

class X2DPoint : public shapeElement{
private:
    glm::vec3 _position = glm::vec3(0,0,0);
public:
    X2DPoint(const glm::vec3& position);
    X2DPoint(const glm::vec2& position);
    X2DPoint(const float& x, const float& y);
    X2DPoint();
    X2DPoint(const X2DPoint& p);
    std::vector<float> generateVertices() override;
    glm::vec3 getVector(){return _position;}
};

class Line : public shapeElement{
private:
    X2DPoint _begin,_end;
    float _thickness = 1.0f;
public:
    Line(X2DPoint begin, X2DPoint end, float thickness = 1.0f);
    std::vector<float> generateVertices() override;
};

class Triangle : public DrawableElement{
private:
    X2DPoint _points[3];
public:
    Triangle(X2DPoint* points);
    Triangle(const X2DPoint& point1, const X2DPoint& point2, const X2DPoint& point3);
    Triangle(const glm::vec2& point1, const glm::vec2& point2, const glm::vec2& point3);
    Triangle();
    Triangle(const Triangle& t);
    std::vector<float> generateVertices() override;
};

class Rectangle : public DrawableElement{
private:
    glm::vec2 size;
    std::vector<Triangle> _triangles; //the 2 triangles that make a filled rectangle
public:
    //order of the points should be bottom left, top left, bottom right, top right [4]
    Rectangle(X2DPoint points[4]);
    Rectangle(const glm::vec2& size);
    Rectangle();
    Rectangle(const Rectangle& t);
    std::vector<float> generateVertices() override;
};

class EmptyRectangle : public DrawableElement{
private:
    Rectangle _sides[4]; //an empty rectangle has 4 sides which are all filled rectangles of a specific width
    X2DPoint _points[4];   //points for the 4 sides
    float _thickness = 1.0f;
    float _width = 0.0f;
    float _height = 0.0f;
public:
    //order of the points should be bottom left, top left, bottom right, top right [4]
    EmptyRectangle(X2DPoint* points, float thickness = 1.0f);
    EmptyRectangle(glm::vec3 origin,float width, float height, float thickness = 1.0f);
    std::vector<float> generateVertices() override;
};


class DefaultCube : public DrawableElement{
public:
    DefaultCube(float width, float height, float thickness, float offsetX = 0, float offsetY = 0, float offsetZ = 0);

    std::vector<float> generateVertices() override;

    static std::shared_ptr<Mesh> DirectDefaultMesh(float scale = 1.0f);

private:
    float width, height, thickness;
    float offsetX, offsetY, offsetZ;
};