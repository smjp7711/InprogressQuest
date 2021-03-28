#include "Engine.h"
#include "tinyxml2.h"
#include "Library.h"
#include "Timer.h"
Engine::Engine(std::string levelPath):objectLibrary(std::make_unique<Library>())
{
	loadLevel(levelPath);
}

void Engine::loadLevel(std::string levelPath)
{
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile(levelPath.c_str()) != tinyxml2::XML_SUCCESS)
	{
		printf("Bad File Path");
		exit(1);
	}

	tinyxml2::XMLElement* root = doc.FirstChildElement();
	tinyxml2::XMLElement* level = root->FirstChildElement();
	tinyxml2::XMLElement* element = level->FirstChildElement();
	std::string objectType;

	for (tinyxml2::XMLElement* currentElement = element; currentElement != NULL; currentElement = currentElement->NextSiblingElement()) {
		std::unique_ptr<Object>newObject{ nullptr };
		objectType = currentElement->Attribute("type");

		if (objectLibrary->library.find(objectType) != objectLibrary->library.end()) {
			newObject = ((*(objectLibrary->library.find(objectType))).second)->create(currentElement);
		}

		if (newObject != nullptr) {
			objects.push_back(std::move(newObject));
		}
	}
}

void Engine::update()
{
	for (auto& object : objects)
	{
		object->update();
	}
	/*for(int i = 0; i < objects.size(); i++)
	{
		objects[i]->update();
	}*/
}

void Engine::draw()
{

	for (auto& object : objects)
	{
		object->draw();
	}
	//for(int i = 0; i < objects.size(); i++)
	//{
	//	objects[i]->draw();
	//}
}

bool Engine::run()
{
		update();
		draw();
		return true;
}

void Engine::reset(){
	objects.clear();
}
