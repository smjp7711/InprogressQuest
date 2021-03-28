#include "Monster.h"
#include "Texture.h"

Monster::Monster(Texture* texture, Vector2D position, float angle) :Object(texture, position, angle)
{

}
std::unique_ptr<Object> Monster::update()
{
	return nullptr;
}

void Monster::draw()
{
	texture->renderEx((int)position.x, (int)position.y, angle);
}
