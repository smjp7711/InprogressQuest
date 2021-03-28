/*Main area where SDL image will be used, Graphic loaded and saved here
every obj that will have image on screen will have texture obj w/it.*/
#include <iostream>
#include "Texture.h"


SDL_Renderer* Texture::renderer{ nullptr };
//Destructor
Texture::~Texture()
{
	free();
}

Texture::Texture()
{
	width = 0;
	height = 0;
	texture = NULL;

}
/*Texture::Texture(std::string path)
{
	load(path);
}*/

bool Texture::load(SDL_Renderer* renderer, std::string path)
{
//Destroy existing texture information
	free();
// Load the image , create a "surface" can move L R or Up and down but that all
	SDL_Surface* surface{ IMG_Load(path.c_str()) };
//If image loaded
	if (!surface )
	{
		printf("Unable to load image %s! SDL_Image Error: %s\n", path.c_str(), IMG_GetError());

	}
	else
	{
		//Color key --> Says don't render anything that is of this color, choose color not in our image(like a green screen) 
		//Set color key to background(bright magenta), RGB format
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 0, 255));

		//Create an optimized image
		//Function takes in renderer it is going to and surface it is coming from
		texture = SDL_CreateTextureFromSurface(renderer, surface);

		if (texture == NULL)
		{
			printf("Unable to create texture from image %s! SDL Error %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Set the height and widht fromt the texture
			SDL_QueryTexture(texture, NULL, NULL, &width, &height);

			//Free surface 
			SDL_FreeSurface(surface);
		}
	}
	return(texture != NULL);
}

void Texture::free()
{
	if(texture != nullptr)
	{
		SDL_DestroyTexture(texture);
		texture = nullptr;
		width = 0;
		height = 0;
	}
}
//Render class  since texture class will also draw image to the screen and decide what image goes to the screen
void Texture::render(int x, int y, SDL_Rect* clip)
{
	//Set rendering space and rend to screen
	//Takes xy values, as an array

	SDL_Rect renderQuad = {x,y, width, height}; 

	//Set clip rendering dimension
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;

	}
//Render to screen
	SDL_RenderCopy(renderer, texture, clip, &renderQuad);
}
void Texture::renderEx(SDL_Renderer* renderer, int x, int y, float angle, SDL_Rect* clip)
{
	//Set rendering space and rend to screen
		//Takes xy values, as an array

	SDL_Rect renderQuad{ x,y, width, height };

	//Set clip rendering dimension
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	//Render to screen
	SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, NULL, SDL_FLIP_NONE);
}

int Texture::getWidth()
{
	return(width);
}

int Texture::getHeight()
{
	return(height);
}