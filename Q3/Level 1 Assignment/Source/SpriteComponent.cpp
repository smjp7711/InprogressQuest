#include "GraphicsDevice.h"
#include "Object.h"
#include "Component.h"
#include "SpriteComponent.h"
#include "UserInputComponent.h"
#include "Texture.h"
#include "Definitions.h"

SpriteComponent::SpriteComponent(Object* owner) : Component(owner)
{
	texture = nullptr;
	gDevice = nullptr;
}

SpriteComponent::~SpriteComponent() {}

void SpriteComponent::Initialize(GraphicsDevice* gDevice, std::string path)
{
	//Initializes variable
	stepLagCount = 0;

	this->gDevice = gDevice;

	//Load the Art Asset
	//TOD0 fix Texture error.
	texture = new Texture();
	texture->load(gDevice->getRenderer(), path);
	

	//Construct clipping sequence
	for (int i = 0; i < NUM_SPRITES; i++) {

		int row = i / SPRITE_SHEET_NCOLS;
		int col = i % SPRITE_SHEET_NCOLS;

		clipArray[i].x = col * SPRITE_WIDTH;
		clipArray[i].y = row * SPRITE_HEIGHT;
		clipArray[i].w = SPRITE_WIDTH;
		clipArray[i].h = SPRITE_HEIGHT;
	}

	/*/Load Font
	font = TTF_OpenFont("./Assets/Fonts/impact.ttf", 48);
	if (font == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
	}*/
}

void SpriteComponent::Start(){} 

void SpriteComponent::Update() {
	////Update the Animation Every ANIM_LAG frames (cheat to avoid more complicated
	////timing issues while demonstrating animation)
	stepLagCount++;
	stepLagCount %= ANIM_LAG;
	if (stepLagCount == 0)
	{
		stepCount++;
		stepCount %= ANIM_SIZE;
		spriteID = ANIMATION[stepCount];
	}
}

void SpriteComponent::Finish(){}

void SpriteComponent::Draw()
{
	texture->renderEx(gDevice->getRenderer(), (int)xPosition, (int)yPosition, angle, &clipArray[spriteID]);
	std::string command = owner->GetComponent<UserInput>()->getCommand();
	if (command != "")
	{
		//Render Command to Text
		SDL_Color textColor = { 255, 255, 51 };
		SDL_Texture* textSheetTexture = SDL_CreateTextureFromSurface(gDevice->getRenderer(), TTF_RenderText_Solid(font, command.c_str(), textColor));

		//Set rendering space and render to screen
		int width = 0, height = 0;
		SDL_QueryTexture(textSheetTexture, NULL, NULL, &width, &height);
		SDL_Rect renderQuad = { (Uint32)xPosition, (Uint32)yPosition - 80, width, height };

		//Render to screen
		SDL_RenderCopy(gDevice->getRenderer(), textSheetTexture, NULL, &renderQuad);

		//Reset command
		command = "";
	}
}