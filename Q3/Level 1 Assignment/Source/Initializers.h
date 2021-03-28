#ifndef INITIALIZERS_H
#define INITIALIZERS_H
#include <memory>
#include "InputDevice.h"


class ResourceManager;
class BodyComponent;
class SpriteComponent;
class Texture;

struct SpritePresets
{
	bool createSprite{ false };
	std::shared_ptr<Texture> spriteTexture{ nullptr };
	ResourceManager* Devices{ nullptr };

};


enum class BodyShape { Rectangle, Circle };
enum class BodyType { Static, Kinematic, Dynamic };
enum class JointType{Revolute, Distance, Prismatic, Wheel, Weld, Pulley, Friction, Gear, Mouse, Rope, None};

struct BodyPresets
{
	BodyPresets();
	~BodyPresets();
	bool createBody{ false };
	float angle{ 0.0f };
	//PhysicsStats physics;
	SpriteComponent* sprite{ nullptr };
	
};


struct UserInputPresets
{
	bool createUserInput{ false };
	InputDevice::UserInputs TriggeredInput;
	int triggeringEvent;

};

struct ObjectFactoryPresets
{
	std::string objectType{ "" };
	SpritePresets spriteInitializers;
	BodyPresets bodyInitializers;
	UserInputPresets userInputInitializers;
	
	//eInt health{ 0 };//move to new AssetLibraryGame
	ResourceManager* devices{ nullptr };
};





#endif  //INITIALIZERS_H
