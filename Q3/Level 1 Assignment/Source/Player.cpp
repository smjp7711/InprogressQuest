#include "Player.h"
#include "Texture.h"
Player::Player(Texture* texture, Vector2D position, float angle) :Object(texture, position, angle)
{

}

//bool Player::initialize( std::string path)
//{
//
//	this->renderer = renderer;
//	//Load Assets
//	//Creating temporary pointer
//	std::unique_ptr<Texture> tmpTexture(std::make_unique<Texture>());
//	texture = move(tmpTexture);
//	
//	//Temp texture is not point to nothing, load texture
//	texture->load(renderer, path);
//
//	//Construct Clipping sequence for ufo animation
//	for (int i = 0; i < NUM_SPRITES; i++)
//	{
//		int row = i / SPRITE_SHEET_NCOLS;
//		int col = i % SPRITE_SHEET_NCOLS;
//
//		clipArray[i].x = col * SPRITE_WIDTH;
//		clipArray[i].y = row * SPRITE_HEIGHT;
//		clipArray[i].w = SPRITE_WIDTH;
//		clipArray[i].h = SPRITE_HEIGHT;
//	}
//	return true;
//}

std::unique_ptr<Object> Player::update()
{
	//translation
	position.x += 1.0f;
	position.y += 1.0f;

	//1 rotation/second
	angle += 360.0f / 100.0f;

	//stepLagCount++;
	//stepLagCount %= ANIM_LAG;
	//if (stepLagCount == 0)
	//{
	//	stepCount++;
	//	stepCount %= ANIM_SIZE;
	//	spriteID = ANIMATION[stepCount];
	//}

	return nullptr;
}

void Player::draw()
{
	texture->renderEx((int)position.x, (int)position.y, angle, NULL); //Pass render at 0,0 to start
}
