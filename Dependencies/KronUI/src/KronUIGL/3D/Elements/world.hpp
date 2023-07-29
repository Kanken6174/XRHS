#pragma once

#include "entity.hpp"
#include "light.hpp"
#include <memory>
#include <vector>

#include <memory>
#include <vector>

class World : public Entity {
protected:
    World& operator=(const World&) = delete;
public:
    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<std::shared_ptr<Light>> lights;

    static std::shared_ptr<World> instance;
    
    static std::shared_ptr<World>& getInstance() {
        if (!instance) {
            instance = std::make_shared<World>();
        }
        return instance;
    }

    void addLight(std::shared_ptr<Light> l) {
        lights.push_back(l);
    }

    void addEntity(std::shared_ptr<Entity> e) {
        entities.push_back(e);
    }
};