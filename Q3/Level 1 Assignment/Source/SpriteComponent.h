
#ifndef SPRITE_H
#define SPRITE_H

#include"Constants2.h"
#include "Component.h"
#include "SDL.h"
#include "Definitions.h"
//#include "SDL_ttf.h"
class Object;
class GraphicsDevice;
class Texture;

class SpriteComponent : public Component
{
public:
	SpriteComponent(Object*);
	~SpriteComponent();
	void Initialize(GraphicsDevice*, std::string);

	void Start()   override;
	void Update()  override;
	void Finish()  override;

	void Draw();
	float xPosition;
	float yPosition;
	float angle;

protected:
	Texture* texture;
	GraphicsDevice* gDevice;
	SDL_Rect clipArray[NUM_SPRITES];



	Uint32 stepLagCount;
	Uint32 stepCount;

	Uint32 spriteID;

	//TTF_Font* font;
};


#endif

