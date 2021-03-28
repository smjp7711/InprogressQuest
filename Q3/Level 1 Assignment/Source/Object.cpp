#include "Object.h"
#include "Constants2.h"
#include "Texture.h"
#include "Component.h"
#include "SpriteComponent.h"
#include "UserInputComponent.h"

Object::Object(){
	initialized = false;
}

Object::~Object(){

}


bool Object::Initialize(ObjectFactory::Initializers initializers){

	return initialized;
}

//Adds passed componet to the object
void Object::AddComponent(Component* component){
	components.push_back(component);
}

//Runs the update method for all attached components
std::vector<std::unique_ptr<Object>> Object::Update(){

	std::vector<std::unique_ptr<Object>> newObjects;

	for (auto& component : components)
	{
		//Call the update function for all componetns
		if( auto temp = component->Update(); temp.size() > 0)
		{
			newObjects.insert(newObjects.end(), std::make_move_iterator(temp.begin()), std::make_move_iterator(temp.end()));
		}
	}

	return newObjects;
}
//Method finds the sprite componen and if it exists casts it to sprite, calls sprite's draw method
void Object::draw()
{
	if (SpriteComponent* sprite = getComponent<SpriteComponet>(); sprite != nullptr)
	{
		sprite->draw();
	}
}




