#pragma once
#include <vector>
#include "Component.h"
#include "SDL.h"
//#include "InputDevice.h"
//#include "EventHandler.h"
//#include "IEventTrigger.h"

class UserInputComponent : public Component
{
public:
	UserInputComponent(Object*);
	~UserInputComponent();
	void Initialize();
	void HandleEvent(SDL_Event* event);

	void Start() override;
	void Update() override;
	void Finish() override;

	std::string getCommand() { return command; }

protected:
	float commandAngle;
	float xVelocity;
	float yVelocity;
	std::string command;
};

/*Code used from gaem eninge, incorrect for our assignment

class Object;
class ResourceManager;

class UserInputComponent : public Component, public ITrigger{
	public:
		UserInputComponent(
			Object* owner,
			ResourceManager* devices,
			InputDevice::UserInputs TriggeredInput,
			EventHandler::Event = EventHandler::Event::UserInput);
		std::vector<std::unique_ptr<Object>> triggerEvent(EventHandler::EventData data) override;
		std::vector<std::unique_ptr<Object>> update() override;
	private:
		ResourceManager* devices;
		InputDevice::UserInputs TriggeredInput;
		bool canBeTriggered{ true };*/

/*UserInput::UserInput(Object* owner) :Component(owner)
{

}

UserInput::~UserInput()
{
}

void UserInput::Initialize()
{
}

void UserInput::HandleEvent(SDL_Event* event)
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

void UserInput::Update()
{
	HandleEvent(_owner->event);
	Sprite* sprite = _owner->GetComponent<Sprite>();

	//Quasi-physics updates
	sprite->xPosition += xVelocity;
	sprite->yPosition += yVelocity;
	sprite->angle += commandAngle;

	////Set commandAngle to 0 to avoid frustrated steering.
	commandAngle = 0.0f;


}

void UserInput::Finish()
{
}

void UserInput::Start()
{
}
*/