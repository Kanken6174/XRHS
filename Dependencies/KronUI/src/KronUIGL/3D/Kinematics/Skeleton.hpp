#include "../Elements/entity.hpp"
#include <memory>
// the hand itself is bone 0 of the hand (origin)
class Hand : public Entity{
public:
    std::vector<std::shared_ptr<Entity>> thumb; //each finger will have 4 parts,from the origin to the finger tip
    std::vector<std::shared_ptr<Entity>> index;
    std::vector<std::shared_ptr<Entity>> middle;
    std::vector<std::shared_ptr<Entity>> ring;
    std::vector<std::shared_ptr<Entity>> pinky;
    bool isRightHand;

    Hand(std::shared_ptr<Entity> parentNode, bool rightHand);
};

class Leg: public Entity{
    std::shared_ptr<Entity> thigh;
    std::shared_ptr<Entity> tibia;
    bool isRightLeg;
};

class Head : public Entity{
public:
    std::shared_ptr<Entity> eyeL;
    std::shared_ptr<Entity> eyeR;
    std::shared_ptr<Entity> mouth;

    Head(std::shared_ptr<Entity> parentNode);
};

class foot: public Entity{
public:
    std::shared_ptr<Entity> footBack;
    std::shared_ptr<Entity> footMiddle;
    std::shared_ptr<Entity> footFront;
    bool isRightFoot;
};

class SimpleSkeleton : public Entity{
public:
    std::shared_ptr<Head> head;
    std::shared_ptr<Hand> leftHand;
    std::shared_ptr<Hand> rightHand;

    SimpleSkeleton(uint programID);
};

class FBTSkeleton : public SimpleSkeleton{
public:
    std::shared_ptr<Entity> neck;
    std::shared_ptr<Entity> leftShoulder;
    std::shared_ptr<Entity> rightShoulder;
    std::shared_ptr<Entity> spine;
    std::shared_ptr<Entity> leftHip;
    std::shared_ptr<Entity> rightHip;
    std::shared_ptr<Leg> leftLeg;
    std::shared_ptr<Leg> rightLeg;
};