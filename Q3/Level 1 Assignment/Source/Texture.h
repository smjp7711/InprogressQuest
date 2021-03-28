#pragma once
#include <string>
#include "SDL.h"
#include "SDL_image.h"

class Texture
{
public:
	~Texture(); //Destructor
	Texture();
	//Texture(std::string path);
	//Loads our image , path is were our image is sitting
	bool load(SDL_Renderer* renderer, std::string path); 

	//Deallocates texture -tells SDL when texture is not longer needed
	void free();

	//Renders texture at given point
	//(Which one to render to, position(xy) to be rendered at, Rectangle of Where on the sprite sheet)
	void render(int x, int y, SDL_Rect* clip = NULL);
	void renderEx(SDL_Renderer* renderer, int x, int y, float angle, SDL_Rect* clip = NULL);
	//Get image dimension
	int getWidth();
	int getHeight();
	static SDL_Renderer* renderer;
private:
	//The actual hardware texture
	SDL_Texture* texture{ nullptr };
	
	//Image dimension
	int width{ 0 };
	int height{ 0 };

};