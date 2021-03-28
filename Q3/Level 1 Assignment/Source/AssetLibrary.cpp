#include "AssetLibrary.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "ComponentsList.h"
#include "Object.h"
//#include "Sound.h"

AssetLibrary::AssetLibrary(ResourceManager* devices)
{
	this->devices = devices;
}

AssetLibrary::~AssetLibrary()
{
}

std::shared_ptr<Texture> AssetLibrary::getArtAsset(std::string searchString)
{
	return artLibrary.find(searchString)->second;
}

bool AssetLibrary::addArtAsset(std::string name, std::string path)
{
	artLibrary[name] = std::make_shared<Texture>(devices->gDevice.get(), path);

	if (!artLibrary[name]->initialized)
	{
		auto artIter = artLibrary.find(name);
		artLibrary.erase(artIter);
		return false;
	}

	return true;

}

bool AssetLibrary::hasSprites()
{
	return !artLibrary.empty();
}
