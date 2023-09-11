#include "Skeleton.hpp"
#include "../Elements/world.hpp"
#include "../../Geometry/Shapes.hpp"

void recursiveMeshSetup(std::shared_ptr<Entity> entity, uint programID){
    if(entity->mesh){
        entity->mesh->setupMesh(programID);
    }else{
        Logger::getInstance().warn("Entity with name: " + entity->name + " has no mesh!");
        return;
    }
    for(auto child : entity->children){
        recursiveMeshSetup(child, programID);
    }
}

Hand::Hand(std::shared_ptr<Entity> parentNode, bool rightHand){
    this->name = rightHand ? "Right Hand" : "Left Hand";
    this->parent = parentNode;
    this->isRightHand = rightHand;
    //we don't create the bones of the hand yet, later
}

SimpleSkeleton::SimpleSkeleton(uint programID){
    this->name = "SimpleSkeleton";

    head = std::make_shared<Head>(std::make_shared<SimpleSkeleton>(*this));
    leftHand = std::make_shared<Hand>(std::make_shared<SimpleSkeleton>(*this),true);
    rightHand = std::make_shared<Hand>(std::make_shared<SimpleSkeleton>(*this),true);

    leftHand->isRightHand = false;
    rightHand->isRightHand = true;

    head->children.push_back(leftHand);
    head->children.push_back(rightHand);

    leftHand->parent = head;
    rightHand->parent = head;
    head->transform->setPosition(glm::vec3(1.0f,1.8f,1.0f));    //head is origin, relative to the world, 1.8m high
    head->transform->setEulerAngles(glm::vec3(1.0f,60.0f,1.0f));
    //head->localTransform->setPosition(glm::vec3(0.1f,10.1f,0.18f));    //head is origin, relative to the world, 1.8m high
    World::getInstance()->addEntity(head);  //this also sets the parent of the head to the world

    head->mesh = DefaultCube::DirectDefaultMesh(5.0f);
    leftHand->mesh = DefaultCube::DirectDefaultMesh();
    rightHand->mesh = DefaultCube::DirectDefaultMesh();
    
    recursiveMeshSetup(head,programID);
}

Head::Head(std::shared_ptr<Entity> parentNode){
    this->name = "Head";
    this->parent = parentNode;
    eyeL = std::make_shared<Entity>(std::make_shared<Head>(*this));
    eyeR = std::make_shared<Entity>(std::make_shared<Head>(*this));
    mouth = std::make_shared<Entity>(std::make_shared<Head>(*this));

    eyeL->mesh = DefaultCube::DirectDefaultMesh(0.1f);
    eyeR->mesh = DefaultCube::DirectDefaultMesh(0.1f);
    mouth->mesh = DefaultCube::DirectDefaultMesh(0.1f);

    eyeL->name = "Left Eye";
    eyeR->name = "Right Eye";
    mouth->name = "Mouth";

    this->children.push_back(eyeL);
    this->children.push_back(eyeR);
    this->children.push_back(mouth);

    eyeL->localTransform->setPosition(glm::vec3(-0.05f,0.0f,0.0f));
    eyeR->localTransform->setPosition(glm::vec3(0.05f,0.0f,0.0f));
    mouth->localTransform->setPosition(glm::vec3(0.0f,-0.05f,0.0f));
}