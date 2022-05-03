#pragma once

#include "InputHandler.h"
#include "Vector2D.h"

#define SQR 0
#define EX 1
#define CRCL 2
#define TRGL 3

#define LEFT_TRIGGER_1 4 
#define RIGHT_TRIGGER_1 5 
#define LEFT_TRIGGER_2 6 
#define RIGHT_TRIGGER_2 7

#define SELECT 8 
#define START 9

#define LEFT_STICK_HORIZONTAL 0
#define LEFT_STICK_VERTICAL 1
#define RIGHT_STICK_HORIZONTAL 2
#define RIGHT_STICK_VERTICAL 3


class JoystickHandler : public InputHandler
{
public:
	JoystickHandler();
	void update();
	void clean();

	bool InitialiseJoySticks();

	float GetXDirectionValue();
	float GetYDirectionValue();
	bool GetFireButtonValue();
	bool GetSelectValue();
	bool GetButtonState(int joystick, int button);

private:
	// Connected Joysticks
	std::vector<SDL_Joystick*> m_joysticks;

	// Right and Left analog values of all the controllers connected
	std::vector< std::pair<Vector2D*, Vector2D*>> m_joystickValues;

	// config val
	float m_joystickDeadZone = 0.00f;

	// Buttons
	std::vector<std::vector<bool>> m_buttonStates;
};