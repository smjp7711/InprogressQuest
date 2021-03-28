#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <memory>
#include <vector>
#include "SDL.h"
#include "ObjectFactory.h"

class Component;
class SpriteComponent;
class UserInputComponent;
//class PlayerComponent;
//class MonsterComponent;
class GraphicsDevice;


class Object{
public:
	Object();
	~Object();

	bool Initialize(ObjectFactory::Initializers initializers);
	void AddComponent(Component* component);

	template<class T>
	T* GetComponent()
	{
		for (auto comp : components)
		{
			T* target = nullptr;
			if (target = dynamic_cast<T*>(comp))
			{
				return(target);
			}
		}

		//Return NULL;
		return(nullptr);
	}

	std::vector<std::unique_ptr<Object>> Update();
	void draw();
	SDL_Event* event;
	

protected:
	std::vector<Component*> components;
	bool initialized;
}

#endif // !OBJECT_H