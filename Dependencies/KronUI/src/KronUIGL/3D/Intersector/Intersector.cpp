#include "Intersector.hpp"

#include "../Elements/transform.hpp"
#include "../../Geometry/Shapes.hpp"
#include "../../../../../AHRS_core/src/model/patterns/commands/commands.hpp"
#include <glm/glm.hpp>

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

//checks if a ray intersects a rectangle (the ray is represented by a transform with a position (vec3) and a rotation (quat))
bool Intersector::RayRectangleIntersection(const std::shared_ptr<Transform>& rayTransform, const std::shared_ptr<Rectangle>& rectangle){
    glm::vec3 directionVector = rayTransform->getQuaternion() * glm::vec3(0.0f, 0.0f, 1.0f);

    // Step 2: Calculate the vector from start_position to the target_point.
    glm::vec3 toTargetVector = rectangle->storedTransform->getPosition() - rayTransform->getPosition();

    // Step 3: Calculate the dot product.
    float dotProduct = glm::dot(directionVector, glm::normalize(toTargetVector));

    // Step 4: Calculate the angle in radians.
    float angleRadians = acos(dotProduct);

    // Step 5: Check if the angle is within the cone angle.
    float coneAngleRadians = 3.0f;
    Logger::getInstance().warn("angle: " + std::to_string(angleRadians) + " coneAngle: " + std::to_string(coneAngleRadians));
    return angleRadians >= coneAngleRadians;
}