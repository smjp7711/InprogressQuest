#include "UserInputComponent.h"
#include "SpriteComponent.h"
#include "Object.h"

UserInputComponent::UserInputComponent(Object* owner) :Component(owner)
{

}

UserInputComponent::~UserInputComponent()
{
}

void UserInputComponent::Initialize()
{
}

void UserInputComponent::HandleEvent(SDL_Event* event)
{
	switch (event->type)
	{
	case SDL_KEYDOWN:
		switch (event->key.keysym.sym)
		{
		case SDLK_LEFT:
			commandAngle = -360.0f / 100.f;
			command = "left";
			break;
		case SDLK_RIGHT:
			commandAngle = 360.0f / 100.f;
			command = "right";
			break;
		case SDLK_UP:
			xVelocity = 1.0f;
			yVelocity = 1.0f;
			command = "up";
			break;
		case SDLK_DOWN:
			xVelocity = 0.0f;
			yVelocity = 0.0f;
			command = "down";
			break;
		}
	}
}

void UserInputComponent::Update()
{
	HandleEvent(owner->event);
	SpriteComponent* sprite = owner->GetComponent<SpriteComponent>();

	//Quasi-physics updates
	sprite->xPosition += xVelocity;
	sprite->yPosition += yVelocity;
	sprite->angle += commandAngle;

	////Set commandAngle to 0 to avoid frustrated steering.
	commandAngle = 0.0f;


}

void UserInputComponent::Finish()
{
}

void UserInputComponent::Start()
{
}
