#include "transform.hpp"
#include <memory>

class Light {
public:
    enum class LightType { Point, Directional, Spot };

private:
    LightType type;
    glm::vec3 color;
    float intensity;
    std::shared_ptr<Transform> transform;

public:
    Light(std::shared_ptr<Transform> xtransform,
          LightType type = LightType::Point,
          glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f),
          float intensity = 1.0f)
    : type(type), color(color), intensity(intensity), transform(xtransform) {}

    ~Light() = default;

    LightType GetType() const { return type; }
    void SetType(LightType type) { this->type = type; }

    const glm::vec3& GetColor() const { return color; }
    void SetColor(const glm::vec3& color) { this->color = color; }

    float GetIntensity() const { return intensity; }
    void SetIntensity(float intensity) { this->intensity = intensity; }

    std::shared_ptr<Transform> GetTransform() { return transform; }
};