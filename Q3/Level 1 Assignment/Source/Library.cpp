#include <memory>
#include "Library.h"
#include "PlayerFactory.h"
#include "MonsterFactory.h"
#include "Texture.h"
Library::Library()
{
	library["Player"] = std::make_unique<PlayerFactory>(this);
	library["Monster"] = std::make_unique<MonsterFactory>(this);

	//TODO::make sure texture loads.
	artLibrary["Player"] = std::make_shared<Texture>("./Assets/Images/falcon1.png");
	artLibrary["Monster"] = std::make_shared<Texture>("./Assets/Images/ufo2.png");
}

Library::~Library()
{
}
