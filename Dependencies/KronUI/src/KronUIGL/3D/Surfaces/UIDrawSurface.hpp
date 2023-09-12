#include "DrawSurface.hpp"
#include "../../../../../AHRS_core/src/model/patterns/commands/commands.hpp"

class DrawCommand : public Command {
protected:
    std::shared_ptr<DrawSurface> surface;
public:
    DrawCommand(std::shared_ptr<DrawSurface> surface) : surface(surface) {}
    virtual void Execute() = 0;
};

class UIDrawSurface : public DrawSurface {
protected:
    std::vector<std::shared_ptr<DrawCommand>> drawCommands;
    GLuint framebufferId;
public:
    UIDrawSurface(const glm::vec2& size, std::shared_ptr<Transform> transform) : DrawSurface(size, transform) {customRenderer = true;}
    void addCommand(std::shared_ptr<DrawCommand> command) {drawCommands.push_back(command);}
    void runCommands();
    void setupSurface() override;
    void FBOBegin();
    void FBOEnd();
};