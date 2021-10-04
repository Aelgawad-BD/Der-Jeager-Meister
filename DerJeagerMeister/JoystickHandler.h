#pragma once

#include "InputHandler.h"
#include "Vector2D.h"

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