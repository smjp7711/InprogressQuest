#ifndef MONSTER_H
#define MONSTER_H
#include "Object.h"
class Texture;
class Monster : public Object
{
public:
	Monster(Texture* texture, Vector2D position, float angle);
	std::unique_ptr<Object> update() override;
	void draw() override;
};
#endif // !MONSTER_H
