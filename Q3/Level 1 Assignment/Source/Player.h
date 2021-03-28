#ifndef PLAYER_H
#define PLAYER_H
#include "Object.h"
class Texture;
class Player: public Object
{
public:
	Player(Texture* texture, Vector2D position, float angle);
	std::unique_ptr<Object> update() override;
	void draw() override;
	
};
#endif // !PLAYER_H
