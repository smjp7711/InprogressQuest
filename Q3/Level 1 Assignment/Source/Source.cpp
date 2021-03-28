#include <string>
#include <iostream>
#include <memory> 
#include "Engine.h"
#include "SDL.h"
#include "GraphicsDevice.h"
#include "Object.h"
#include "InputDevice.h"
#include "Timer.h"


int main(int argc, char *argv[]) //argument list needed for it to run

{
	std::string path{ "./Assets/Config/Game.xml" };
	std::unique_ptr<GraphicsDevice> gDevice{ std::make_unique<GraphicsDevice>(800, 600) };
	std::unique_ptr<InputDevice> inputDevice{ std::make_unique<InputDevice>() };
	std::unique_ptr<Engine> engine{ std::make_unique<Engine>(path) };
	
	//Construct Graphical Device
	//Create graphics device, w800 h600
	
	//Initialize Graphics device

	//Create unique pointer to timer class
	std::unique_ptr<Timer> fps(std::make_unique<Timer>());
	//Pass in frame rate of 100
	if (!fps -> Initialize(100))
	{
		printf("Frame timer could not initialize! SDL_Error: %s\n", SDL_GetError());
		exit(1);
	}
	

	////Initialize Object
	////Do I need to change the shared_ptr to unique ptrs? 
	//std::shared_ptr<Object> object (std::make_shared <Object>());
	//object->initialize(gDevice->getRenderer(), "./Assets/Images/ufo1.png");

	//Initialize Termination Criteria
	bool quit = false;

	//If game is over quit loop
	while (!quit)
	{
		//Start the frame's time
		fps->start();
		
		////poll Event--check what next event is
		//SDL_PollEvent(event.get()); //Pass raw pointer

		////Translate Event to Quit signal
		//if (event->type == SDL_QUIT)  
		//{
		//	//If event type is equal to quit(256 sinc enum type)then true
		//	quit = true;
		//}
		//Starts render device
		gDevice->Begin();
		inputDevice->update();
		engine->run();
		//object->update();
		//Regulate before drawign and presenting
	
		//Tells device to draw
		gDevice->Present();
		fps->fpsRegulate();

	}



	return 0;
}