#pragma once
#include <memory>
#include <vector>
#include <optional>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform;
class Rectangle;
class BoolCommand;

class IntersectionData {
protected:
    glm::vec3 intersectionPoint;
    glm::vec2 facexy;
public:

    IntersectionData(glm::vec3 intersectionPoint, glm::vec2 facexy) : intersectionPoint(intersectionPoint), facexy(facexy) {}
    IntersectionData() : intersectionPoint(glm::vec3(0.0f,0.0f,0.0f)), facexy(glm::vec2(0.0f,0.0f)) {}

    glm::vec3 getIntersectionPoint() { return intersectionPoint; }
    glm::vec2 getFaceXY() { return facexy; }

    void setIntersectionPoint(glm::vec3 intersectionPoint) { this->intersectionPoint = intersectionPoint; }
    void setFaceXY(glm::vec2 facexy) { this->facexy = facexy; }
};

//modern Signleton
class Intersector {
protected:
    static std::shared_ptr<Intersector> _instance;
    IntersectionData _lastEvent;
    std::vector<std::tuple<std::shared_ptr<Rectangle>,std::optional<std::shared_ptr<BoolCommand>>>> surfaces;
    std::vector<std::tuple<std::shared_ptr<Transform>,std::optional<std::shared_ptr<BoolCommand>>>> emitters;
    bool TriangleRayIntersection(const glm::vec3& rayOrigin, const glm::vec3& rayVector, const glm::vec3 triangle[3], glm::vec3& intersectionPoint);
    bool RayRectangleIntersection(const std::shared_ptr<Transform>& rayTransform, const std::shared_ptr<Rectangle>& rectangle);
    bool ConeToOriginIntersection(const std::shared_ptr<Transform>& rayTransform, const std::shared_ptr<Rectangle>& rectangle);
public:
    static std::shared_ptr<Intersector> getInstance() {
        if (_instance == nullptr) {
            _instance = std::make_shared<Intersector>();
        }
        return _instance;
    }
    void runInteresctions();
    void addSurface(std::shared_ptr<Rectangle> surface, std::optional<std::shared_ptr<BoolCommand>> command);
    void addEmitter(std::shared_ptr<Transform> emitter, std::optional<std::shared_ptr<BoolCommand>> command);
    IntersectionData getLastEvent() { return _lastEvent; }
};