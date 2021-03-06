#include <string>
#include <iostream>
#include "tinyxml2.h"

#include "ResourceManager.h"
#include "ComponentsList.h"
#include "Object.h"

#include "InputDevice.h"
#include "GraphicsDevice.h"
//#include "ViewCallBack.h"  //not sure if I need
#include "Texture.h"
//#include "PhysicsDevice.h" //will add on later

#include "AssetLibrary.h"
#include "ObjectFactory.h"

#include "Definitions.h"

using namespace std;
inline bool createThisDevice(tinyxml2::XMLElement* createMe)
{
	bool create;
	createMe->QueryBoolAttribute("create", &create);
	return create;
}

//Made initialie an arugment to be ste to true or false withing the constructor
ResourceManager::ResourceManager(std::string assetPath)
{
	tinyxml2::XMLDocument levelConfig;
	if(!levelConfig.LoadFile(assetPath.c_str()) == tinyxml2::XML_SUCCESS)
	{
	printf("Bad File Path");
	exit(1);
	};

	tinyxml2::XMLElement* levelRoot = levelConfig.FirstChildElement();//Level
	tinyxml2::XMLElement* levelElement = levelRoot->FirstChildElement();//Screen

	//========================================
	//Construct Event Handler
	//========================================
	eventHandler = make_unique<EventHandler>();

	//========================================
	//Construct Device Manager
	//========================================
	int screenWidth{ 0 };
	int screenHeight{ 0 };
	levelElement->QueryIntAttribute("width", &screenWidth);
	levelElement->QueryIntAttribute("height", &screenHeight);

	gDevice = std::make_unique<GraphicsDevice>(this, screenWidth, screenHeight, true);
	/*
	if (tinyxml2::XMLElement* fontConfig = levelElement->FirstChildElement(); fontConfig)
	{
		RGBA fontColor;

		fontConfig->QueryIntAttribute("R", (int*)&fontColor.R);
		fontConfig->QueryIntAttribute("G", (int*)&fontColor.G);
		fontConfig->QueryIntAttribute("B", (int*)&fontColor.B);
		fontConfig->QueryIntAttribute("A", (int*)&fontColor.A);

		int fontSize;
		fontConfig->QueryIntAttribute("size", &fontSize);

		string fontPath = fontConfig->Attribute("path");

		gDevice->setFont(fontPath, fontSize, fontColor);
	}

	levelElement = levelElement->NextSiblingElement();//FPS
	//FPS = std::stoi(levelElement->GetText()); */

	//========================================
	//Construct Object Factory
	//========================================
	factory = std::make_unique<ObjectFactory>(this);

	levelElement = levelElement->NextSiblingElement();//Devices


	//========================================
	//Construct Input Device
	//========================================
	tinyxml2::XMLElement* deviceConfig = levelElement->FirstChildElement("Input");
	if (createThisDevice(deviceConfig))
	{
		//TODO:: load inputs from file.
		iDevice = std::make_unique<InputDevice>();
	}

	//========================================
	//Construct Physics Device
	//========================================
	//deviceConfig = deviceConfig->NextSiblingElement("Physics");
	//if (createThisDevice(deviceConfig))
	//{
		//Vector2D gravity{ 0, 0 };
		//deviceConfig->QueryFloatAttribute("gravityX", &gravity.x);
		//deviceConfig->QueryFloatAttribute("gravityY", &gravity.y);
		//pDevice = std::make_unique<PhysicsDevice>(gravity);
	//}


	//========================================
	//Construct Asset Library
	//========================================
	deviceConfig = deviceConfig->NextSiblingElement("AssetLibrary");
	if (createThisDevice(deviceConfig))
	{
		assetLibrary = std::make_unique<AssetLibrary>(this);

		//*********************Load sprites***************************
		tinyxml2::XMLElement* asset = deviceConfig->FirstChildElement("Asset");

		while (asset)
		{
			//We have some errors here, may need to address them later.
			assetLibrary->addArtAsset(asset->Attribute("name"), asset->Attribute("spritePath"));
			asset = asset->NextSiblingElement("Asset");
		}


	}




	//========================================
	//Construct Objects
	//========================================
	for (
		levelElement = levelElement->NextSiblingElement("Object");
		levelElement;
		levelElement = levelElement->NextSiblingElement("Object")
		)
	{
		objects.push_back(std::unique_ptr<Object>(factory->create(levelElement)));
	}

	//***********************************************************

	//
	//set-up debugging
	//
	//Box2DDebugdraw* debugdraw = new Box2DDebugdraw();
	//debugdraw->Initialize(this);
 //   debugdraw->setFlags(b2draw::e_shapeBit | b2draw::e_aabbBit);  //Turn on shape (red color) and aabb (green) 

	////Add the Debug draw to the world
	//if(debugdraw!=NULL)
	//{
	//	pDevice -> getWorld() -> setDebugdraw(debugdraw);
	//}
}
bool ResourceManager::killObject(Object* butAScratch)
{
	return false;
}
ResourceManager::~ResourceManager()
{
	if (!objects.empty())
	{
		objects.clear();
	}
	iDevice = nullptr;
	//sDevice = nullptr;
	gDevice = nullptr;
	//pDevice = nullptr;
	assetLibrary = nullptr;
	factory = nullptr;
}

void ResourceManager::update()
{
	iDevice->update();

	//pDevice->update(1.0f / FPS);

	for (auto objectIter = objects.begin(); objectIter != objects.end(); )
	{
		if (
			StatComponent* compHealth = (*objectIter)->getComponent<StatComponent>();
			compHealth != nullptr && compHealth->isDead)
		{
			//**************Bring out your dead********************
			(*objectIter)->removeComponents();
			objects.erase(objectIter);
			//*******************************************************
		}
		else
		{
			objectIter++;
		}
	}
	//if (objects.size() > 5)
	//{
	//	cout << objects[5]->getComponent<BodyComponent>()->getPosition().x << ", " << objects[5]->getComponent<BodyComponent>()->getPosition().y << endl;
	//}
	for (auto& object : objects)
	{
		std::vector<std::unique_ptr<Object>> temp = object->update();
		if (!temp.empty())
		{
			newObjects.insert(newObjects.end(), std::make_move_iterator(temp.begin()), std::make_move_iterator(temp.end()));
		}
	}

	if (!newObjects.empty())
	{
		objects.insert(objects.end(), std::make_move_iterator(newObjects.begin()), std::make_move_iterator(newObjects.end()));
		newObjects.clear();
	}
}

void ResourceManager::draw()
{
	gDevice->Begin();

	for (auto& object : objects)
	{
		object->draw();
	}

	gDevice->draw();

	gDevice->Present();
}
