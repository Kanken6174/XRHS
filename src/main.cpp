#define PATH_TO_KRONUI "../Dependencies/KronUI/src/"

#include "Glue.hpp"

#define DEBUG_UI
//#undef DEBUG_UI

void GLAPIENTRY MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
    Logger::Level log_level;

    switch(severity)
    {
        case GL_DEBUG_SEVERITY_HIGH:
            log_level = Logger::Level::ERROR;
            break;
        case GL_DEBUG_SEVERITY_MEDIUM:
            log_level = Logger::Level::WARNING;
            break;
        case GL_DEBUG_SEVERITY_LOW:
            log_level = Logger::Level::INFO;
            break;
        case GL_DEBUG_SEVERITY_NOTIFICATION:
        default:
            log_level = Logger::Level::INFO;
            break;
    }

    std::string log_message = "GL CALLBACK: ";
    if (type == GL_DEBUG_OUTPUT) log_message += "** GL ERROR ** ";
    log_message += "type = 0x" + std::to_string(type) + ", severity = 0x" + std::to_string(severity) + ", message = " + std::string(message);

    Logger::getInstance().log(log_level, log_message);
}

int main(){
    topLevelManager* tlm = new topLevelManager();
    std::srand(std::time(nullptr));
    Logger::getInstance().info("KronUI started");

    KronUIWindow* window = new KronUIWindow("test", 1920, 1080); 
    Logger::getInstance().info("KronUIWindow created");

    KronUIWindowManager::setWindow(window);
    glEnable( GL_DEBUG_OUTPUT );
    glDebugMessageCallback( MessageCallback, 0 );
    glfwSetCursorPosCallback(window->getSelf(), mouse_callback);

    double time = glfwGetTime();
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);

    DefaultCube* dc = new DefaultCube(10.0f,0.5f,10.0f, 0.0f, -0.5f, 0.0f);
    DefaultCube* dc2 = new DefaultCube(0.5f,0.5f,0.5f, 5.0f,0.0f,0.0f);
    
    OBJLoader* loader = new OBJLoader();

    std::vector<std::shared_ptr<Mesh>> ms = loader->loadModel("./Ressources/Models/laptop/t1.obj");
    Logger::getInstance().info("meshes loaded: " + std::to_string(ms.size()));

    std::unique_ptr<Entity> e = std::make_unique<Entity>();
    

    GeometryRenderer* gr = new GeometryRenderer();
    gr->addShapeToBuffer(dc);
    gr->addShapeToBuffer(dc2);

    auto rps = ShaderManager::getInstance()->buildShader("./shaders/geom.vs", "./shaders/geom.fs");
    auto cubed = ShaderManager::getInstance()->buildShader("./shaders/cube.vs", "./shaders/cube.fs");
    auto shader = ShaderManager::getInstance()->buildShader("./shaders/text.vs", "./shaders/text.fs");
    auto surface = ShaderManager::getInstance()->buildShader("./shaders/surface.vs", "./shaders/surface.fs");
    auto background = ShaderManager::getInstance()->buildShader("./shaders/background.vs", "./shaders/background.fs");

    float angle = glm::radians(270.0f);
    std::shared_ptr<DrawSurface> ds = std::make_shared<DrawSurface>(glm::vec2(1.0f,1.0f),DrawSurface::defaultIndicies(),
    std::make_shared<QuaternionTransform>(glm::vec3(0.0f,1.0f,0.0f),glm::vec3(3.0f,2.0f,1.0f),glm::angleAxis(angle, glm::vec3(0.0f, 1.0f, 0.0f))));

    std::shared_ptr<VideoFrame> backgroundFrame = std::make_shared<VideoFrame>("./Ressources/Textures/wall.jpg",background, window->getSelf(), true);
    std::shared_ptr<VideoFrame> frontFrame = std::make_shared<VideoFrame>("./Ressources/Textures/hud.png",background, window->getSelf(), false);

    ds->shader = surface;
    ds->setupSurface();

    std::shared_ptr<QuaternionTransform> baseLightTransform = std::make_shared<QuaternionTransform>(glm::vec3(-5.0f,5.0f,-2.0f),glm::vec3(1.0f,1.0f,1.0f),glm::vec3(1.0f,1.0f,1.0f));
    std::shared_ptr<Light> l = std::make_shared<Light>(baseLightTransform,Light::LightType::Point, glm::vec3(1.0f,0.0f,0.0f),0.1f);

    std::shared_ptr<QuaternionTransform> baseLightTransform2 = std::make_shared<QuaternionTransform>(glm::vec3(5.0f,5.0f,-2.0f),glm::vec3(1.0f,1.0f,1.0f),glm::vec3(1.0f,1.0f,1.0f));
    std::shared_ptr<Light> l2 = std::make_shared<Light>(baseLightTransform2,Light::LightType::Point, glm::vec3(0.0f,1.0f,0.0f),0.1f);

    std::shared_ptr<Light> l3 = std::make_shared<Light>(InputSystem::getInstance().getCamera().transform,Light::LightType::Point, glm::vec3(0.0f,0.0f,1.0f),1.0f);


    World::getInstance()->addLight(l);
    //World::getInstance()->addLight(l2);
    World::getInstance()->addLight(l3);

    MeshRenderer* mr = new MeshRenderer(cubed);
    for(auto mesh : ms){
        std::shared_ptr<Entity> es = std::make_shared<Entity>(0,0,0,0,0,0);
        es->mesh = mesh;
        es->mesh->get()->setupMesh(cubed->ID);
        World::getInstance()->addEntity(es);
    }

    dc->shader = cubed;
    dc2->shader = cubed;
    glm::mat4 modelMatrix = glm::mat4(1.0f);
    dc->shader->setMat4("model", modelMatrix); 
    dc2->shader->setMat4("model", modelMatrix);

    TrueTypeManager* ttm = new TrueTypeManager("./f2.ttf");
    TextRenderer tx = TextRenderer(shader,window,ttm);
    float i = 0;
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    const float frameTimeTarget = 1.0f / 60.0f; // Time for one frame at 60 FPS.

    glEnable(GL_DEPTH_TEST);

    backgroundFrame->prepareFrame();

    while (!glfwWindowShouldClose(window->getSelf()))
    {
        float frameStart = glfwGetTime();
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window->getSelf(), deltaTime);

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindVertexArray(VertexArrayID);

        OpencvToVideoFrame::updateFromNode(backgroundFrame, tlm->localPipeline->getNodes().at(0));
#ifdef DEBUG_UI
        OpencvToVideoFrame::updateFromNodeWithTransparency(frontFrame, tlm->localPipeline->getNodes().at(3));
#endif


        backgroundFrame->render();

        dc->shader->setMat4("view", InputSystem::getInstance().getCamera().viewMatrix);
        dc->shader->setMat4("projection", InputSystem::getInstance().getCamera().projectionMatrix);
        //dc->drawSelf();
        dc2->shader->setMat4("view", InputSystem::getInstance().getCamera().viewMatrix);
        dc2->shader->setMat4("projection", InputSystem::getInstance().getCamera().projectionMatrix);
        dc2->drawSelf();
        
        mr->shader->setMat4("view", InputSystem::getInstance().getCamera().viewMatrix);
        mr->shader->setMat4("projection", InputSystem::getInstance().getCamera().projectionMatrix);
        mr->renderAllWorld();
        //tx.RenderText("test", (window->_width/2.5), window->_height/2, i, glm::vec3(1.0f,1.0f,1.0f));
        i+= 0.001f;
        frontFrame->render();
        /*ds->updateSurfaceFromWindow();
        ds->shader->setMat4("view", InputSystem::getInstance().getCamera().viewMatrix);
        ds->shader->setMat4("projection", InputSystem::getInstance().getCamera().projectionMatrix);
        ds->drawSurface(InputSystem::getInstance().getCamera().viewMatrix, InputSystem::getInstance().getCamera().projectionMatrix);
*/      glClear(GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(KronUIWindowManager::getWindow()->getSelf());
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}