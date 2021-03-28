#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include "ObjectFactory.h"
#include "tinyxml2.h"
class Library;
class PlayerFactory : public ObjectFactory
{
public:
	PlayerFactory() = delete;
	PlayerFactory(Library* library);
	~PlayerFactory() {}
	std::unique_ptr<Object> create(tinyxml2::XMLElement* objectElement) override;
};

#endif // !PLAYERFACTORY_H
