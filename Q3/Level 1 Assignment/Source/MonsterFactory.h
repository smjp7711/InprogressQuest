#ifndef MONSTERFACTORY_H
#define MONSTERFACTORY_H
#include "ObjectFactory.h"
#include "tinyxml2.h"
class Library;
class MonsterFactory : public ObjectFactory
{
public:
	MonsterFactory() = delete;
	MonsterFactory(Library* library);
	~MonsterFactory() {}
	std::unique_ptr<Object> create(tinyxml2::XMLElement* objectElement);
};

#endif // !MONSTERFACTORY_H
