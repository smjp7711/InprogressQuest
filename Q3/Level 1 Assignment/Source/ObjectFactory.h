#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H
#include <memory>
#include "tinyxml2.h"
#include "Initializers.h"

class Object;
class Library;
class ResourceManager;
struct ObjectFactoryPresests;


class ObjectFactory {
public:
	ObjectFactory() = delete;
	//ObjectFactory(Library* objectLibrary);
	//virtual std::unique_ptr<Object> create(tinyxml2::XMLElement* objectElement) = 0;
	ObjectFactory(ResourceManager* devices);
	
	//Create objects at runtime
	Object* create(tinyxml2::XMLElement* objectElement);

	//Create object during runtime
	Object* create(ObjectFactoryPresets* presets);

private:
	//Library* objectLibrary{ nullptr };

	ResourceManager* devices{ nullptr };
	std::unique_ptr<ObjectFactoryPresets> createPresetsFromXML(tinyxml2::XMLElement* objectElement);
	void addSpritePresets(SpritePresets* presets, tinyxml2::XMLElement* componentElement);
	void addBodyPresets(BodyPresets* presets, tinyxml2::XMLElement* componentElement);
	void addUserInputPresets(UserInputPresets* presets, tinyxml2::XMLElement* componentElement);
};
#endif // !OBJECTFACTORY_H