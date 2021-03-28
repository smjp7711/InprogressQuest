#include "MonsterFactory.h"
#include "Monster.h"
#include "Library.h"
MonsterFactory::MonsterFactory(Library* library) : ObjectFactory(library)
{

}
std::unique_ptr<Object> MonsterFactory::create(tinyxml2::XMLElement* objectElement)
{
	Vector2D position;
	float angle;
	objectElement = objectElement->FirstChildElement();
	objectElement->QueryFloatAttribute("x", &position.x);
	objectElement->QueryFloatAttribute("y", &position.y);
	objectElement->QueryFloatAttribute("angle", &angle);
	
	return((std::unique_ptr<Object>)(std::make_unique<Monster>(objectLibrary->artLibrary.find("Monster")->second.get(), position, angle)));
}
