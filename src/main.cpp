#define PATH_TO_KRONUI "../Dependencies/KronUI/src/"
#define RADIAN_TO_DEGREE 57.2957795131f

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
    
    OBJLoader* loader = new OBJLoader();

    std::vector<std::shared_ptr<Mesh>> ms = loader->loadModel("./Ressources/Models/laptop/t1.obj");
    Logger::getInstance().info("meshes loaded: " + std::to_string(ms.size()));

    std::unique_ptr<Entity> e = std::make_unique<Entity>();

    auto rps = ShaderManager::getInstance()->buildShader("./shaders/geom.vs", "./shaders/geom.fs");
    auto cubed = ShaderManager::getInstance()->buildShader("./shaders/cube.vs", "./shaders/cube.fs");
    auto shader = ShaderManager::getInstance()->buildShader("./shaders/text.vs", "./shaders/text.fs");
    auto surface = ShaderManager::getInstance()->buildShader("./shaders/surface.vs", "./shaders/surface.fs");
    auto background = ShaderManager::getInstance()->buildShader("./shaders/background.vs", "./shaders/background.fs");

    float angle = glm::radians(270.0f);
    std::shared_ptr<X11DrawSurface> ds = std::make_shared<X11DrawSurface>(glm::vec2(1.0f,1.0f),
    std::make_shared<QuaternionTransform>(glm::vec3(0.0f,1.0f,0.0f),glm::vec3(3.0f,2.0f,1.0f),glm::angleAxis(angle, glm::vec3(0.0f, 1.0f, 0.0f))));

    std::shared_ptr<VideoFrame> backgroundFrame = std::make_shared<VideoFrame>("./Ressources/Textures/wall.jpg",background, window->getSelf(), true);
    std::shared_ptr<VideoFrame> frontFrame = std::make_shared<VideoFrame>("./Ressources/Textures/hud.png",background, window->getSelf(), false);

    ds->shader = surface;
    ds->localTransform->setEulerAngles(glm::vec3(0.0f,90.0f/RADIAN_TO_DEGREE,0.0f));
    ds->setupSurface();

    World::getInstance()->addEntity(ds);

    MeshRenderer* mr = new MeshRenderer(cubed);
    for(auto mesh : ms){
        std::shared_ptr<Entity> es = std::make_shared<Entity>(0,0,0,0,0,0);
        es->localTransform->setEulerAngles(glm::vec3(0.0f,90.0f/RADIAN_TO_DEGREE,0.0f));
        es->mesh = mesh;
        es->mesh->setupMesh(cubed->ID);
        World::getInstance()->addEntity(es);
    }

    std::shared_ptr<SimpleSkeleton> sk = std::make_shared<SimpleSkeleton>(cubed->ID);

    //TrueTypeManager* ttm = new TrueTypeManager("./f2.ttf");
    //TextRenderer tx = TextRenderer(shader,window,ttm);
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
        sk->head->localTransform->setPosition(InputSystem::getInstance().getCamera().transform->getPosition()*glm::vec3(3.0f,3.0f,-5.0f));
        sk->head->localTransform->setQuaternion(InputSystem::getInstance().getCamera().transform->getQuaternion());
        processWorldTransforms();

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindVertexArray(VertexArrayID);
        
        OpencvToVideoFrame::updateFromNode(backgroundFrame, tlm->localPipeline->getNodes().at(0));
#ifdef DEBUG_UI
        //OpencvToVideoFrame::updateFromNodeWithTransparency(frontFrame, tlm->localPipeline->getNodes().at(3));
#endif
        backgroundFrame->render();

        mr->renderAllWorld();
    
        //tx.RenderText("test", (window->_width/2.5), window->_height/2, i, glm::vec3(1.0f,1.0f,1.0f));
        i+= 0.001f;
        frontFrame->render();
        ds->updateSurfaceFromWindow(); //virtual pc window
        cameraMatrixOp(ds->shader);
        ds->drawSurface(InputSystem::getInstance().getCamera().viewMatrix, InputSystem::getInstance().getCamera().projectionMatrix);
        glClear(GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(KronUIWindowManager::getWindow()->getSelf());
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}