#include <memory>
#include <vector>
#include <optional>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform;
class Rectangle;
class BoolCommand;

//modern Signleton
class Intersector {
protected:
    static std::shared_ptr<Intersector> _instance;
    std::vector<std::tuple<std::shared_ptr<Rectangle>,std::optional<std::shared_ptr<BoolCommand>>>> surfaces;
    std::vector<std::tuple<std::shared_ptr<Transform>,std::optional<std::shared_ptr<BoolCommand>>>> emitters;
    bool RayRectangleIntersection(const std::shared_ptr<Transform>& rayTransform, const std::shared_ptr<Rectangle>& rectangle);
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
};