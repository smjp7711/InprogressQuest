#ifndef INPUTDEVICE_H
#define INPUTDEVIE_H
#include "SDL.h"
#include <memory>
#include <map>


class InputDevice{
public:
	InputDevice();
	void update();
	//get possible user inputs (the game is strictly keyboard intputs)
	enum class UserInputs
	{
		NA,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		SPACE,
		A,
		W,
		S,
		D,
		QUIT
	};
	std::map<UserInputs, bool> keyStates;

	private:
		UserInputs keyTranslate();
		std::unique_ptr<SDL_Event> event {nullptr};
};



#endif //!INPUTDEVICE_H
