#ifndef ASSETLIBRARY_H
#define ASSETLIBARARY_H

#include <string>
#include <map>
#include <memory>

class ResourceManager;
class Texture;
//class SoundEffect;
//class BackgroundMusic;
class GraphicsDevice;
class Object;
class Component;

class AssetLibrary
{
public:
	AssetLibrary(ResourceManager* devices);
	AssetLibrary() = delete;
	~AssetLibrary();
	
	//Gets asset's name
	std::shared_ptr<Texture> getArtAsset(std::string name);
	bool addArtAsset(std::string name, std::string path);

	bool hasSprites();


	//TOD ADD MUSIC
	//bool addSoundEffect(std::string name, std::string path);
	//bool addBackgroundMusic(std::string name, std::string path);
	//SoundEffect* playSoundEffect(std::string path);
	//BackgroundMusic* playBackgroundMusic(std::string& name);

	//bool hasSounds();

private:
	//Will pass string values to pass by reference
	std::map<std::string, std::shared_ptr<Texture>> artLibrary;
	ResourceManager* devices{ nullptr }; 
	//TODO: ADD MUSIC
	//std::map<std::string, std::shared_ptr<SoundEffect>> soundEffectLibary;
	//std::map<std::string, std::shared_ptr<BackgroundMusic>> musicLibary;

};


#endif 