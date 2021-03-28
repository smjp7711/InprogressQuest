#include "PlayerFactory.h"
#include "Player.h"
#include "Library.h"
#include "SDL.H"
#include <iostream>
PlayerFactory::PlayerFactory(Library* library) : ObjectFactory(library)
{

}
std::unique_ptr<Object> PlayerFactory::create(tinyxml2::XMLElement* objectElement)
{
	Vector2D position;
	float angle;
	objectElement = objectElement->FirstChildElement();
	objectElement->QueryFloatAttribute("x", &position.x);
	objectElement->QueryFloatAttribute("y", &position.y);
	objectElement->QueryFloatAttribute("angle", &angle);
	return((std::unique_ptr<Object>)(std::make_unique<Player>(objectLibrary->artLibrary.find("Player")->second.get(),position, angle)));
}
