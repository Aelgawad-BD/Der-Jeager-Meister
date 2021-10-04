#include "JoystickHandler.h"

#include "Game.h"

// For a comprehensive list of joystick buttons
// https://wiki.libsdl.org/SDL_GameControllerButton

JoystickHandler::JoystickHandler()
{
	InitialiseJoySticks();
}

void JoystickHandler::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		// this->listenToSelectKey = false;
		int joystickID = event.jaxis.which;

		if (event.type == SDL_JOYAXISMOTION)
		{
			// Reset all analoges
			for (size_t i = 0; i < m_joystickValues.size(); i++)
			{
				m_joystickValues[i].first->SetX(0);
				m_joystickValues[i].second->SetX(0);

				m_joystickValues[i].first->SetY(0);
				m_joystickValues[i].second->SetY(0);
			}




			// LEFT ANALOG - Right & Left Axis
			if (event.jaxis.axis == 0)
			{
				if (event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[joystickID].first->SetX(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[joystickID].first->SetX(-1);
				}
				else
				{
					m_joystickValues[joystickID].first->SetX(0);
				}
			}

			// LEFT ANALOG - Up & Down Axis
			if (event.jaxis.axis == 1)
			{
				if (event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[joystickID].first->SetY(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[joystickID].first->SetY(-1);
				}
				else
				{
					m_joystickValues[joystickID].first->SetY(0);
				}
			}

			// RIGHT ANALOG move left or right
			if (event.jaxis.axis == 3)
			{
				if (event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[joystickID].second->SetX(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[joystickID].second->SetX(-1);
				}
				else
				{
					m_joystickValues[joystickID].second->SetX(0);
				}
			}

			// RIGHT ANALOG move up or down
			if (event.jaxis.axis == 4)
			{
				if (event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[joystickID].second->SetY(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[joystickID].second->SetY(-1);
				}
				else
				{
					m_joystickValues[joystickID].second->SetY(0);
				}
			}
		}

		if (event.type == SDL_JOYBUTTONDOWN)
		{
			m_buttonStates[joystickID][event.jbutton.button] = true;
		}

		if (event.type == SDL_JOYBUTTONUP)
		{
			m_buttonStates[joystickID][event.jbutton.button] = false;
		}

		if (event.type == SDL_CONTROLLER_BUTTON_START)
		{
			// this->currentSelectKeyState = true;
		}

		// QUIT EVENT
		if (event.type == SDL_QUIT)
		{
			GAME->Shutdown();
		}
	}
}

void JoystickHandler::clean()
{
	if (InputHandler::m_bJoysticksInitialised)
	{
		for (size_t i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_JoystickClose(m_joysticks[i]);
		}
	}
}

bool JoystickHandler::InitialiseJoySticks()
{
	if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
	{
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}

	if (SDL_NumJoysticks() > 0)
	{
		// CONTROLLER LOOP
		for (int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_Joystick* joy = SDL_JoystickOpen(i);
			if (joy)
			{
				m_joysticks.push_back(joy);
				m_joystickValues.push_back(std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));

				std::vector<bool> tempButtons;
				// CONTROLLER BUTTON LOOP
				for (size_t j = 0; j < SDL_JoystickNumButtons(joy); j++)
				{
					tempButtons.push_back(false);
				}
				m_buttonStates.push_back(tempButtons);
			}
			else
			{
				std::cout << SDL_GetError();
			}
		}
		SDL_JoystickEventState(SDL_ENABLE);
		std::cout << "Initialised " << m_joysticks.size() << " joystick(s)";
		return true;
	}
	else
	{
		return false;
	}
}

bool JoystickHandler::GetButtonState(int joystick, int button)
{
	return m_buttonStates[joystick][button];
}

float JoystickHandler::GetXDirectionValue()
{
	if (m_joystickValues.size() > 0)
		return m_joystickValues[0].first->GetX();
	else
		return 0.0f;
}

float JoystickHandler::GetYDirectionValue()
{
	if (m_joystickValues.size() > 0)
		return m_joystickValues[0].first->GetY();
	else
		return 0.0f;
}

bool JoystickHandler::GetFireButtonValue()
{
	// [ToDo] You need to get the proper Macro for the Joystick button for firing
	return m_buttonStates[0][0];
}

bool JoystickHandler::GetSelectValue()
{
	return false;//currentSelectKeyState;
}