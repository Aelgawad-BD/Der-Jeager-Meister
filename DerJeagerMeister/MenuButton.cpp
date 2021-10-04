#include "MenuButton.h"

#include "configurations.h"

MenuButton::MenuButton(const LoaderParams* pParams, void (*callback)()) : SDLGameObject(pParams), m_onClick(callback)
{
	m_currentState = button_state::NORMAL;
	m_currentFrame = 0;
	m_scale = 2.0f;
}

void MenuButton::Update()
{
	if (this->m_currentState == button_state::INFOCUS)
	{
		if (m_currentFrame < BUTTON_FRAMES)
		{
			this->m_currentFrame++;
		}
	}

	else if (this->m_currentState == button_state::NORMAL)
		m_currentFrame = 0;

	/*if (INPT_HNDLR->GetSelectValue())
		m_onClick();*/
		// the code above would call the button event in case of a return regardless of which button was selected, all buttons on the screen will be invoced

	SDLGameObject::Update();
}

void MenuButton::Draw()
{
	SDLGameObject::Draw();
}

void MenuButton::Clean()
{
	SDLGameObject::Clean();
}

void MenuButton::setButtonState(button_state state)
{
	this->m_currentState = state;
}
