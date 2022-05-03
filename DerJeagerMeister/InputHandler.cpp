#include "InputHandler.h"
#include "KeyboardHandler.h"
#include "JoystickHandler.h"

InputHandler* InputHandler::s_pInputHandlerInstance = 0;
bool InputHandler::m_bJoysticksInitialised = false;

InputHandler* InputHandler::GetInstance()
{
	if (s_pInputHandlerInstance == 0)
	{
		s_pInputHandlerInstance = CreateInstance();
	}
	return s_pInputHandlerInstance;
}

InputHandler* InputHandler::CreateInstance()
{
	InputHandler* inputHandler;
	if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);

	if (SDL_NumJoysticks() > 0)
	{
		m_bJoysticksInitialised = true;
		return new JoystickHandler();
	}
	else
	{
		m_bJoysticksInitialised = false;
		return new KeyboardHandler();
	}
}

bool InputHandler::joysticksInitialised()
{
	return m_bJoysticksInitialised;
}