#include "../Elements/entity.hpp"
#include <memory>
//in this file are declared the various types of kinematic joints, these define how a child entity is affected by a parent entity (through it's local transform)
using namespace std;

class AbstractKinematicJoint
{
public:
    virtual void update(shared_ptr<Entity> parent, shared_ptr<Entity> current) = 0;
};

//This kinematic joint just takes the parent' current transform and multiplies it by the child's local transform to obtain the child's current transform
class BasicKinematicJoint : public AbstractKinematicJoint
{
public:
    virtual void update(shared_ptr<Entity> parent, shared_ptr<Entity> current) override;
};

// this joint will use the child's local transform to find out how far it is from the parent and will modify the rotation and position of the child to 
// have it move as if connected to the parent by a fixed joint
class DerivedKinematicJoint : public AbstractKinematicJoint
{
public:
    virtual void update(shared_ptr<Entity> parent, shared_ptr<Entity> current) override;
};