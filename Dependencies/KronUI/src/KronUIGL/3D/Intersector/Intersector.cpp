#include "Intersector.hpp"

#include "../Elements/transform.hpp"
#include "../../Geometry/Shapes.hpp"
#include "../../../../../AHRS_core/src/model/patterns/commands/commands.hpp"
#include <glm/glm.hpp>

#define RADIAN_TO_DEGREE 57.2957795131

std::shared_ptr<Intersector> Intersector::_instance = nullptr;

void Intersector::runInteresctions() {
    for( auto& emitter : emitters){
        for( auto& surface : surfaces){
            bool intersection = RayRectangleIntersection(std::get<0>(emitter), std::get<0>(surface));
            if(std::get<1>(surface).has_value() && intersection != std::get<1>(surface).value()->value){
                std::get<1>(surface).value()->value = intersection;
                std::get<1>(surface).value()->Execute();
            }
            if(std::get<1>(emitter).has_value() && intersection != std::get<1>(emitter).value()->value){
                std::get<1>(emitter).value()->value = intersection;
                std::get<1>(emitter).value()->Execute();
            }
        }
    }
}

void Intersector::addSurface(std::shared_ptr<Rectangle> surface, std::optional<std::shared_ptr<BoolCommand>> command)
{
    if(surface->storedTransform == nullptr)
        Logger::getInstance().fatal("Intersector::addSurface: surface->storedTransform == nullptr");
    surfaces.push_back(std::make_tuple(surface, command));
}

void Intersector::addEmitter(std::shared_ptr<Transform> emitter, std::optional<std::shared_ptr<BoolCommand>> command)
{
    emitters.push_back(std::make_tuple(emitter, command));
}

// checks if a cone intersects a rectangle's origin (the ray is represented by a transform with a position (vec3) and a rotation (quat))
bool Intersector::ConeToOriginIntersection(const std::shared_ptr<Transform>& rayTransform, const std::shared_ptr<Rectangle>& rectangle){
    glm::vec3 directionVector = rayTransform->getQuaternion() * glm::vec3(0.0f, 0.0f, 1.0f);

    // Step 2: Calculate the vector from start_position to the target_point.
    glm::vec3 toTargetVector = rectangle->storedTransform->getPosition() - rayTransform->getPosition();

    // Step 3: Calculate the dot product.
    float dotProduct = glm::dot(directionVector, glm::normalize(toTargetVector));

    // Step 4: Calculate the angle in radians.
    float angleRadians = acos(dotProduct);

    // Step 5: Check if the angle is within the cone angle.
    float coneAngleRadians = 3.0f;
    Logger::getInstance().warn("angle: " + std::to_string(angleRadians*RADIAN_TO_DEGREE) + " coneAngle: " + std::to_string(coneAngleRadians));
    return angleRadians >= coneAngleRadians;
}

bool Intersector::TriangleRayIntersection(const glm::vec3& rayOrigin, const glm::vec3& rayVector, const glm::vec3 triangle[3], glm::vec3& intersectionPoint) {
    const float EPSILON = 0.0000001; // A small value used for numerical stability

    glm::vec3 edge1, edge2, h, s, q;
    float a, f, u, v;

    // Calculate two edges of the triangle
    edge1 = triangle[1] - triangle[0];
    edge2 = triangle[2] - triangle[0];

    // Calculate the cross product of the ray vector and the second triangle edge
    h = glm::cross(rayVector, edge2);

    // Compute the dot product of the first edge and the cross product (a determinant-like value)
    a = glm::dot(edge1, h);

    // Check if the ray is nearly parallel to the triangle (avoid division by zero)
    if (a > -EPSILON && a < EPSILON){
        Logger::getInstance().warn("Parallel, a: " + std::to_string(a));
        return false; // The ray is parallel to the triangle, no intersection.
    }

    // Calculate f, the reciprocal of a (used for later calculations)
    f = 1.0 / a;

    // Calculate s, the vector from the ray origin to the first triangle vertex
    s = rayOrigin - triangle[0];

    // Calculate u, a parameter that determines how far along the ray the intersection occurs
    u = f * glm::dot(s, h);

    // Check if u is outside the valid range [0, 1]
    if (u < 0.0 || u > 1.0){
        Logger::getInstance().warn("u: " + std::to_string(u));
        return false; // The intersection point is outside the triangle.
    }

    // Calculate q, a vector representing the direction from the first triangle vertex to the intersection point
    q = glm::cross(s, edge1);

    // Calculate v, another parameter that determines the position of the intersection on the ray
    v = f * glm::dot(rayVector, q);

    // Check if v is outside the valid range [0, 1]
    if (v < 0.0 || u + v > 1.0){
        Logger::getInstance().warn("v: " + std::to_string(v));
        return false; // The intersection point is outside the triangle.
    }

    // At this stage, we can compute t, the parameter determining where the intersection occurs along the ray.
    float t = f * glm::dot(edge2, q);

    // Check if t is positive (ray intersection) and greater than EPSILON for numerical stability
    if (t < EPSILON) {
        // Compute the intersection point using the ray's origin and direction
        intersectionPoint = rayOrigin + rayVector * t;
        Logger::getInstance().warn("intersection at: " + std::to_string(intersectionPoint.x) + " " + std::to_string(intersectionPoint.y) + " " + std::to_string(intersectionPoint.z));
        DebugDrawer::drawPointVec3(intersectionPoint, glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
        return true; // The ray intersects the triangle, and intersectionPoint contains the intersection point.
    }
    else {
        // There is a line intersection, but not a ray intersection.
        Logger::getInstance().warn("t: " + std::to_string(t));
        return false;
    }
}


bool Intersector::RayRectangleIntersection(const std::shared_ptr<Transform>& rayTransform, const std::shared_ptr<Rectangle>& rectangle) {
    // Get the center of the rectangle
    glm::vec3 center = rectangle->storedTransform->getPosition();

    // Calculate half of the rectangle's width and height
    float halfWidth = rectangle->getSize().x / 2.0f;
    float halfHeight = rectangle->getSize().y / 2.0f;

    // Calculate the bottom left corner of the rectangle
    glm::vec3 bottomLeft = center - rectangle->storedTransform->getQuaternion() * glm::vec3(halfWidth, halfHeight, 0.0f);

    // Calculate the other corners of the rectangle
    glm::vec3 p1 = bottomLeft;
    glm::vec3 p2 = bottomLeft + rectangle->storedTransform->getQuaternion() * glm::vec3(rectangle->getSize().x, 0.0f, 0.0f);
    glm::vec3 p3 = bottomLeft + rectangle->storedTransform->getQuaternion() * glm::vec3(0.0f, rectangle->getSize().y, 0.0f);
    glm::vec3 p4 = center + rectangle->storedTransform->getQuaternion() * glm::vec3(halfWidth, halfHeight, 0.0f);

    // Define two triangles from the rectangle's points
    glm::vec3 triangle1[3] = { p1, p2, p3 };
    glm::vec3 triangle2[3] = { p2, p3, p4 };

    // Initialize intersection point
    glm::vec3 intersectionPoint;

    // Check for intersection with each triangle
    if (TriangleRayIntersection(rayTransform->getPosition(), rayTransform->getQuaternion() * glm::vec3(0.0f, 0.0f, 1.0f), triangle1, intersectionPoint) ||
        TriangleRayIntersection(rayTransform->getPosition(), rayTransform->getQuaternion() * glm::vec3(0.0f, 0.0f, 1.0f), triangle2, intersectionPoint)) {
        // Calculate intersection coordinates relative to the rectangle
        glm::vec3 localIntersectionPoint = intersectionPoint - center;
        float intersectionX = glm::dot(localIntersectionPoint, glm::normalize(p2 - p1));
        float intersectionY = glm::dot(localIntersectionPoint, glm::normalize(p3 - p1));

        _lastEvent.setIntersectionPoint(intersectionPoint);
        _lastEvent.setFaceXY(glm::vec2(intersectionX, intersectionY));

        return true;
    }

    return false;
}

