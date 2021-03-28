#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <memory> //For smart pointers

/*
Timer -Let's you know how long since SDL2 was intitiated
Audio(We'll be using SLD Mixer since its better)
Video-Does video display, we'll use SDL image so it will allow other formats(png)
Joystick(omitted)
Haptic feedback(omitted)
Game Controller(omitted)
Event Handling-takes care of keyboard and mouse
*/

class GraphicsDevice 
{
public:
	//Default Constructor(Takes in width and height of screen)
	GraphicsDevice(Uint32, Uint32);
	//Destructor
	~GraphicsDevice();

	bool Initialize(bool); //Full screen or just window
	bool Shutdown(); //Shutsdown graphics system
	void Begin(); //Clears renderer
	void Present(); //Does drawing
	
	SDL_Renderer* getRenderer();

private:
	//Window to display graphics
	//Passing in pointer from SDL
	SDL_Window* screen;

	//Renderer will go from screen and image files
	SDL_Renderer* renderer;

	//Paramaters
	const Uint32 SCREEN_WIDTH;
	const Uint32 SCREEN_HEIGHT;

};
