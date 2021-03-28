#pragma once
#include "SDL.h"

class Timer
{
public:
	Timer();
	bool Initialize(Uint32);

	//The various clock actins
	void start();
	void stop();
	void pause();
	void unpause();

	//Gets the timer's time (in ticks)
	Uint32 getTicks();

	//Check the status of the timer
	bool isStarted();
	bool isPaused();

	//Regulate, pause game in order to get to desired frame rate
	void fpsRegulate();
private:
	//The clock time when the timer is started
	Uint32 startTicks;
	float mpf; // how long ea frame is supposed to take in milliseconds

	//Ticks stored whent he timer was paused
	Uint32 pausedTicks;

	//The time status
	bool paused;
	bool started;


};