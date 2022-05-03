#pragma once

#include "InputHandler.h"

class KeyboardHandler : public InputHandler
{
public:
	KeyboardHandler();
	void update();
	void clean();
	float GetXDirectionValue();
	float GetYDirectionValue();
	bool GetFireButtonValue();
	bool GetSelectValue();

private:
	const Uint8* keyStates;

	bool select_keyEnabled = true;
	bool select_keyState = false;
	bool right_keyState  = false;
	bool down_keyState   = false;
	bool left_keyState   = false;
	bool up_keyState     = false;
};