#include "Object.h"
#include "Component.h"

//The owner is set upon creation
Component::Component(Object* owner) : owner(owner) {}

Component::~Component() {}

void Component::OwnerDestroyed()
{
	Finish();
	owner = nullptr;
}



Object* Component::GetOwner()
{
	return(owner);
}