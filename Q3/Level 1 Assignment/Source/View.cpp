#include "View.h"

View::View(InputDevice* inputDevice, Vector2D position): input(inputDevice), position(position)
{
}

bool View::update()
{
	return false;
}
