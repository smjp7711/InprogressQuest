#include <iostream>
#include "InputDevice.h"

InputDevice::InputDevice(){

	//create the event system
	event = std::make_unique<SDL_Event>();
	//check if there is an event, if not then exit program
	if(!event){
		printf("SDL Event could not initialize!");
		exit(1);
	}

	//initialize all keystates to false
	keyStates[UserInputs::NA] = false;
	keyStates[UserInputs::DOWN] = false;
	keyStates[UserInputs::UP] = false;
	keyStates[UserInputs::LEFT] = false;
	keyStates[UserInputs::RIGHT] = false;
	keyStates[UserInputs::SPACE] = false;
	keyStates[UserInputs::QUIT] = false;
	keyStates[UserInputs::S] = false;
	keyStates[UserInputs::W] = false;
	keyStates[UserInputs::A] = false;
	keyStates[UserInputs::D] = false;
	update();
}

//updates event based on SDL_Event
void InputDevice::update()
{
	UserInputs gEvent;
	//if an event exists
	if(SDL_PollEvent(event.get()))
	{
		//update the proper key state depending on the event
		switch (event->type)
		{
			case SDL_KEYDOWN:
				//translate the SDL event to a game event
				gEvent = keyTranslate();
				keyStates.find(gEvent)->second = true;
				break;

			case SDL_KEYUP:
				gEvent = keyTranslate();
				keyStates.find(gEvent)->second = false;
				break;

			case SDL_QUIT:
				keyStates.find(UserInputs::QUIT)->second = true;
				break;
			default:
				break;
		}
	}
}

//converts SDL events into game events
InputDevice::UserInputs InputDevice::keyTranslate()
{
	//present a case for each possible expected press
	switch(event->key.keysym.sym)
	{
		case SDLK_LEFT:
			return UserInputs::LEFT;
			break;
		case SDLK_RIGHT:
			return UserInputs::RIGHT;
			break;
		case SDLK_UP:
			return UserInputs::UP;
			break;
		case SDLK_DOWN:
			return UserInputs::DOWN;
			break;
		case SDLK_a:
			return UserInputs::LEFT;
			break;
		case SDLK_d:
			return UserInputs::RIGHT;
			break;
		case SDLK_w:
			return UserInputs::UP;
			break;
		case SDLK_s:
			return UserInputs::DOWN;
			break;

	}

	return UserInputs::NA;
}