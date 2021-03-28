#include <iostream>
#include "Timer.h"

Timer::Timer()
{
//Initialize the variables
	startTicks = 0;
	pausedTicks = 0;
	paused = false;
	started = false;
	mpf = 0;
}

bool Timer::Initialize(Uint32 fps)
{
	if(fps > 0)
	{
		//Translate fpts to mpf
		mpf = (float)1000 / fps;
		return true;
	}
	else
	{
		return false;
	
	}
}

void Timer::start()
{
	//Start the timer
	started = true;
	//Unpause the timer
	paused = false;

	//Get the current clock time
	startTicks = SDL_GetTicks();  //Tells us # tiks passed since SDL started
}

void Timer::stop()
{
	//Stop the timer
	started = false;
	paused = false;
}

void Timer::pause()
{
//Check it is started and not paused
	if((started == true) && (paused== false))
	{
		paused = true;
		//Gets point at which timer was paused
		pausedTicks = SDL_GetTicks() - startTicks;

	}
}

void Timer::unpause()
{
	if (paused == true)
	{
		paused = false;
		//Starts back up at point at which timer was paused
		startTicks = SDL_GetTicks() - pausedTicks;
		//Reset paused ticks
		pausedTicks = 0;
	
	}

}

Uint32 Timer::getTicks()
{
	//Check if it is running
	if (started == true)
	{//if paused return where we paused it at
		if (paused== true)
		{
			return pausedTicks;
		}
		else
		{//Tertuns difference from when we started and now
			return SDL_GetTicks() - startTicks;
		}
	
	}
	//If not running at all return 0
	return 0;
}

bool Timer::isStarted()
{
	return started;
}

bool Timer::isPaused()
{
	return paused;
}
void Timer::fpsRegulate()
{
	if (getTicks()< mpf) //if amount of ms is less than we want per frame
	{
		//See how many ticks, if its less, delay until we get to amount of millisecons we want
		SDL_Delay(mpf - (float)SDL_GetTicks()); 
	}

}
