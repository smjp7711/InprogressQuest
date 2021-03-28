#include <iostream>
#include "GraphicsDevice.h"
#include "Texture.h"
#include "SDL.h"
#include "SDL_image.h"
//Initializer
GraphicsDevice::GraphicsDevice(Uint32 width, Uint32 height) : SCREEN_WIDTH(width), SCREEN_HEIGHT(height)
{
	Initialize(false);
}

GraphicsDevice::~GraphicsDevice()
{
//Shutdown
	if (!Shutdown())
	{
		//Prints out what the error was
		printf("SDL could not shut down! SDL_Error: %s\n", SDL_GetError());
		exit(1); //Lets us know we exited with error
	}
	
			
}

	bool GraphicsDevice::Initialize(bool fullScreen)
	{
	//Initialize all SDL subsystems
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
			return (false);
		}

	//Initialize SDL_Image subsystems(Change depending on image type, we are using PNG)
		if(!IMG_INIT_PNG)
		{
			printf("SDL_Image could not initialize! SDL_Error: %s\n", IMG_GetError());
			return (false);
		}
	//Create screen for graphics to apppear(Graphics device already has SDL window called screen)
		if (!fullScreen)
		{
			//If not full screen show window
			screen = SDL_CreateWindow(
				"Fakalaga_gamename",
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				SCREEN_WIDTH, SCREEN_HEIGHT,
				SDL_WINDOW_SHOWN);
		}

		else
		{ //else show full screen windown
			screen = SDL_CreateWindow(
				"Fakalaga_gamename",
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				SCREEN_WIDTH, SCREEN_HEIGHT,
				SDL_WINDOW_FULLSCREEN);
		}
		//Construct Renderer(-1 initializes to 1st driver that supports renderer, flag to use accelerated render, snappier)
		renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
		
		//Check to see is there
		if (renderer == NULL)
		{
			printf("Rendered could not be created! SDL_Error: %s\n", SDL_GetError());
			return(false);
		}
		Texture::renderer = renderer;
		//Set default background colors(sets to black & fully visible)
		SDL_SetRenderDrawColor(renderer, 0, 0, 0 ,255);		
		//If initialized propertly 
		return true;
	}

	//Shutdown
	//REMINDER: Shut down in reverse order than you started
	bool GraphicsDevice::Shutdown()
	{
		//Free the window
		SDL_DestroyWindow(screen);
		screen = NULL;
		
		//Free Renderer
		SDL_DestroyRenderer(renderer);
		renderer = NULL; //set to null since its not longer there
		//Quit image
		IMG_Quit();

		//Quit subsystem(everything at same time)
		SDL_Quit(); 
		return true;
	}

	
	SDL_Renderer* GraphicsDevice::getRenderer()
	{
		return renderer;
	}

	void GraphicsDevice::Begin()
	{
		//Gives us blank screen
		SDL_RenderClear(renderer);
	}

	void GraphicsDevice::Present()
	{
		SDL_RenderPresent(renderer);
	}