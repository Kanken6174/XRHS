#include "DrawSurface.hpp"
#include "../../../../../AHRS_core/src/model/patterns/commands/commands.hpp"

class DrawCommand : public Command {
public:
    DrawCommand() {}
    virtual void Execute() override {}
};

class UIDrawSurface : public DrawSurface {
protected:
    std::vector<std::shared_ptr<DrawCommand>> drawCommands;
    GLuint framebufferId;
    bool ready = false;
public:
    UIDrawSurface(const glm::vec2& size, std::shared_ptr<Transform> transform) : DrawSurface(size, transform) {customRenderer = true;}
    void addCommand(std::shared_ptr<DrawCommand> command) {drawCommands.push_back(command);}
    void runCommands();
    void setupUISurface();
    void FBOBegin();
    void FBOEnd();
    void render();
};