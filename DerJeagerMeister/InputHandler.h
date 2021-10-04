#pragma once

#include <SDL.h>
#include <vector>
#include <iostream>

//#include "Vector2D.h"
//#include "configurations.h"
//#include "Game.h"

#define INPT_HNDLR InputHandler::GetInstance()
#define JOYSTICK_ONE 0
#define JOYSTICK_TWO 1
#define LEFT_ANALOGE_STICK  1
#define RIGHT_ANALOGE_STICK 2

// SINGELTON
class InputHandler
{
public:
	static InputHandler* GetInstance();
	virtual void update() = 0;
	virtual void clean() = 0;

	bool joysticksInitialised();

	virtual float GetXDirectionValue() = 0;
	virtual float GetYDirectionValue() = 0;
	virtual bool GetFireButtonValue() = 0;
	virtual bool GetSelectValue() = 0;


private:
	static InputHandler* CreateInstance();
	static InputHandler* s_pInputHandlerInstance;

protected:
	// Joysticks initialised?
	static bool m_bJoysticksInitialised;
};