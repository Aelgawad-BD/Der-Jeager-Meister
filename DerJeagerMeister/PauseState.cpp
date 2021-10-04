#include "PauseState.h"

#include "configurations.h"
#include "MenuState.h"
#include "Game.h"
#include "InputHandler.h"
#include "MenuButton.h"
#include "TextureManager.h"

const std::string PauseState::s_pauseId = "PAUSE";

void PauseState::update()
{
	bool return_val = false;
	float y_val = INPT_HNDLR->GetYDirectionValue();
	return_val = INPT_HNDLR->GetSelectValue();

	if (y_val > 0 && index < 1)
		index++;
	else if (y_val < 0 && index > 0)
		index--;

	MenuButton* resBtn = static_cast<MenuButton*>(resume_button);
	MenuButton* mnuBtn = static_cast<MenuButton*>(menu_button);

	if (index == 0)
	{
		resBtn->setButtonState(INFOCUS);
		mnuBtn->setButtonState(NORMAL);
	}
	else if (index == 1)
	{
		mnuBtn->setButtonState(INFOCUS);
		resBtn->setButtonState(NORMAL);
	}

	resume_button->Update();
	menu_button->Update();
	//menu_background->Update();

	if (return_val && index == 0)
		pauseToPlay();
	if (return_val && index == 1)
		pauseToMenu();
}

void PauseState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Draw();
	}
}

bool PauseState::onEnter()
{
	if (TheTextureManager->Load(texture_menubutton_resume_png, texture_menubutton_resume_png, GAME->GetRenderer()) == false)
	{
		printf("ERROR >> Spritesheet \"%s\" intialization failed\n", texture_menubutton_resume_png);
		return false;
	}

	if (TheTextureManager->Load(texture_menubutton_menu_png, texture_menubutton_menu_png, GAME->GetRenderer()) == false)
	{
		printf("ERROR >> Spritesheet \"%s\" intialization failed\n", texture_menubutton_menu_png);
		return false;
	}

	resume_button = new MenuButton(new LoaderParams(200, 200, 128, 85, texture_menubutton_resume_png), pauseToPlay);
	menu_button = new MenuButton(new LoaderParams(200, 400, 128, 85, texture_menubutton_menu_png), pauseToMenu);

	m_gameObjects.push_back(resume_button);
	m_gameObjects.push_back(menu_button);

	std::cout << "--> entering PauseState\n";
	return true;
}

bool PauseState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Clean();
	}

	m_gameObjects.clear();

	TheTextureManager->UnLoad(texture_menubutton_resume_png);
	TheTextureManager->UnLoad(texture_menubutton_menu_png);

	std::cout << "<-- exiting PauseState\n";
	return true;
}

void PauseState::pauseToPlay()
{
	GAME->PopState();
}

void PauseState::pauseToMenu()
{
	GAME->SetState(new MenuState());
}
