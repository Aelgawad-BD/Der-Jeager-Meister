#pragma once

#include "SDLGameObject.h"
//#include "InputHandler.h"

enum button_state
{
	NORMAL = 1,
	INFOCUS = 2,
	CLICKED = 3
};

class MenuButton : public SDLGameObject
{
public:

	MenuButton(const LoaderParams* pParams, void (*callback)());

	void Update();
	void Draw();
	void Clean();

	void setButtonState(button_state state);

private:

	button_state m_currentState;
	void (*m_onClick)();
	bool m_buttonReleased;
};