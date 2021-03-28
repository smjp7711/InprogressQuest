#ifndef VIEW_H
#define VIEW_H


class InputDevice;
struct Vector2D {
	float x;
	float y;
};

class View {

public:
	View(InputDevice* inputDevice, Vector2D position);
	bool update();

private:
	InputDevice* input;
	Vector2D position;
};




#endif //!VIEW_H