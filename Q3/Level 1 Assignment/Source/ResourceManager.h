#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <vector>
#include <memory>
#include "Definitions.h" //Need to add

class ObjectFactory;
class AssetLibrary;
class InputDevice;
class GraphicsDevice;
class EventHandler;
class Object;
/*
class SoundDevice;
class Physics Device;

*/
class ResourceManager
{
public:
	ResourceManager() = delete;
	ResourceManager(std::string assetPath);
	~ResourceManager();

	void update();
	void draw();
	//To kill off objects
	bool killObject(Object* butAScratch);
//Devices
	std::unique_ptr<GraphicsDevice> gDevice{ nullptr };
	std::unique_ptr<InputDevice> iDevice{ nullptr };
	//std::unique_ptr<PhysicsDevice> pDevice{ nullptr };
	//std::unique_ptr<SoundDevice> sDevice{ nullptr };

	//Libary
	std::unique_ptr<AssetLibrary> assetLibary{ nullptr };

	//Factory
	std::unique_ptr<ObjectFactory> factory{ nullptr };

	std::vector<std::unique_ptr<Object>> objects;
	std::unique_ptr<EventHandler> eventHandler{ nullptr };

	eInt FPS{ 0 };

private:
	std::vector<std::unique_ptr<Object>> newObjects;


};

#endif