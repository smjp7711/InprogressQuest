
#ifndef COMPONENT_H
#define COMPONENT_H


class Object;

class Component
{
public:
	Component(Object* owner);
	~Component();
	void OwnerDestroyed();
	Object* GetOwner();
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Finish() = 0;

protected:
	Object* owner;
};


#endif