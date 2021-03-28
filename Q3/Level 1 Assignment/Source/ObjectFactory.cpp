#include "ObjectFactory.h"
#include "Texture.h"
#include "Object.h"
#include "Initializers.h"
#include "SpriteComponent.h"
#include "BodyComponent.h"
#include "UserInputComponent.h"
#include "AssetLibrary.h"

/*ObjectFactory::ObjectFactory(Library* objectLibrary): objectLibrary(objectLibrary)
{
}
*/

ObjectFactory::ObjectFactory(ResourceManager* devices):devices(devices){

}

Object* ObjectFactory::create(tinyxml2::XMLElement* objectElement){
	std::unique_ptr<ObjectFactoryPresets> presets = std::move(createPresetsFromXML(objectElement));
	Object* newObject = create(presets.get());
	return newObject;
}

Object* ObjectFactory::create(ObjectFactoryPresets* presets) {
	Object* newObject = new Object;
	if (presets->spriteInitializers.createSprite)
	{
		newObject->AddComponent(new SpriteComponent(newObject));
		presets->bodyInitializers.sprite = newObject->GetComponent<SpriteComponent>();
	}

	if (presets->bodyInitializers.createBody)
	{
		newObject->AddComponent(new BodyComponent(newObject));
		newObject->GetComponent<BodyComponent>();
	}

	if (presets->userInputInitializers.createUserInput)
	{
		newObject->AddComponent(new UserInputComponent(newObject)); 
	}

	return newObject;
}

std::unique_ptr<ObjectFactoryPresets> ObjectFactory::createPresetsFromXML(tinyxml2::XMLElement* objectElement){
	std::unique_ptr<ObjectFactoryPresets> presets = std::make_unique<ObjectFactoryPresets>();
	presets->objectType = objectElement->Attribute("type");
	for(
		tinyxml2::XMLElement* componentElement = objectElement->FirstChildElement();
		componentElement;
		componentElement = componentElement->NextSiblingElement();
	)
	{
		std::string componentName = componentElement->Attribute("name");
		if(componentName == "Sprite")
		{
			addSpritePresets(&presets->spriteInitializers, componentElement);
		}
		else if(componentName == "Body")
		{
			addBodyPresets(&presets->bodyInitializers, componentElement);
		}
		else if(componentName == "UsereInput")
		{
			addUserInputPresets(&presets->userInputInitializers, componentElement);
		}
	}

	return presets;

}

void ObjectFactory::addSpritePresets(SpritePresets* presets, tinyxml2::XMLElement* componentElement) {
	presets->createSprite = true;
	presets->Devices = devices;
	bool isSprite{ false };
	componentElement->QueryBoolAttribute("sprite", &isSprite);
	if(isSprite)
	{
		presets->spriteTexture = devices->AssetLibrary->getArtAssest(componentElement->Attribute("asset"));
	}
	else
	{
		presets->spriteTexture = std::make_shared<Texture>(devices->gDevice.get(), componentElement->Attribute("text"), false);
	}
}

void ObjectFactory::addBodyPresets(BodyPresets* presets, tinyxml2::XMLElement* componentElement)
{
	presets->createBody = true;
}

void ObjectFactory::addUserInputPresets(UserInputPresets* presets, tinyxml2::XMLElement* componentElement)
{
	presets->createUserInput = true;
	int temp;
	//1. Get trigger from XML
	componentElement->QueryIntAttribute("trigger", &temp);
	presets->TriggeredInput = (InputDevice::UserInputs)temp;
}