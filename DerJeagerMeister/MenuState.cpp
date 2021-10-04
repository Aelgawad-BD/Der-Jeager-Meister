#include "MenuState.h"
#include "InputHandler.h"
#include "MenuButton.h"
#include "TextureManager.h"
#include "Background.h"
#include "configurations.h"
#include "Game.h"
#include "PlayState.h"


const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	float y_val = INPT_HNDLR->GetYDirectionValue();
	bool return_val = INPT_HNDLR->GetSelectValue();

	if (y_val > 0 && index < 1)
		index++;
	else if (y_val < 0 && index > 0)
		index--;

	MenuButton* strtBtn = static_cast<MenuButton*>(start_button);
	MenuButton* extBtn = static_cast<MenuButton*>(exit_button);

	if (index == 0)
	{
		strtBtn->setButtonState(INFOCUS);
		extBtn->setButtonState(NORMAL);
	}
	else if (index == 1)
	{
		extBtn->setButtonState(INFOCUS);
		strtBtn->setButtonState(NORMAL);
	}

	start_button->Update();
	exit_button->Update();
	menu_background->Update();

	if (return_val && index == 0)
		menuToPlay();
	if (return_val && index == 1)
		menuToVoid();
}

void MenuState::render()
{
	menu_background->Draw();
	start_button->Draw();
	exit_button->Draw();
}

bool MenuState::onEnter()
{
	if (!TheTextureManager->Load(texture_menubutton_start_png, texture_menubutton_start_png, GAME->GetRenderer()))
	{
		std::cout << "ERROR: could not load texture for Start button" << std::endl;
		return false;
	}

	if (!TheTextureManager->Load(texture_menubutton_exit_png, texture_menubutton_exit_png, GAME->GetRenderer()))
	{
		std::cout << "ERROR: could not load texture for Exit button" << std::endl;
		return false;
	}

	if (!TheTextureManager->Load(texture_menubackground_png, texture_menubackground_png, GAME->GetRenderer()))
	{
		std::cout << "ERROR: could not load texture for Menu Background" << std::endl;
		return false;
	}

	if (
		TheTextureManager->Load(texture_menubackground_base_png, texture_menubackground_base_png, GAME->GetRenderer()) == false ||
		TheTextureManager->Load(texture_menubackground_mountains_png, texture_menubackground_mountains_png, GAME->GetRenderer()) == false ||
		TheTextureManager->Load(texture_menubackground_trees_3_png, texture_menubackground_trees_3_png, GAME->GetRenderer()) == false ||
		TheTextureManager->Load(texture_menubackground_trees_2_png, texture_menubackground_trees_2_png, GAME->GetRenderer()) == false ||
		TheTextureManager->Load(texture_menubackground_trees_1_png, texture_menubackground_trees_1_png, GAME->GetRenderer()) == false ||
		TheTextureManager->Load(texture_menubackground_trees_0_png, texture_menubackground_trees_0_png, GAME->GetRenderer()) == false ||
		TheTextureManager->Load(texture_menubackground_night_png, texture_menubackground_night_png, GAME->GetRenderer()) == false
		)
	{
		std::cout << "ERROR: could not load one or more textures for the Menu Background" << std::endl;
	}

	start_button = new MenuButton(new LoaderParams(200, 200, 128, 85, texture_menubutton_start_png), this->menuToPlay);
	exit_button = new MenuButton(new LoaderParams(200, 400, 128, 85, texture_menubutton_exit_png), this->menuToVoid);
	menu_background = new Scene();

	GAME->AddGameObject(start_button);
	GAME->AddGameObject(exit_button);
	// GAME->AddGameObject(menu_background);

	menu_background->addBackroundElement(new Background(new LoaderParams(0, 0, 2800, SCREEN_HEIGHT, texture_menubackground_base_png), 0));
	menu_background->addBackroundElement(new Background(new LoaderParams(0, 0, 2800, SCREEN_HEIGHT, texture_menubackground_mountains_png), 1));
	menu_background->addBackroundElement(new Background(new LoaderParams(0, 0, 2800, SCREEN_HEIGHT, texture_menubackground_trees_0_png), 2));
	menu_background->addBackroundElement(new Background(new LoaderParams(0, 0, 2800, SCREEN_HEIGHT, texture_menubackground_trees_1_png), 3));
	menu_background->addBackroundElement(new Background(new LoaderParams(0, 0, 2800, SCREEN_HEIGHT, texture_menubackground_trees_2_png), 4));
	menu_background->addBackroundElement(new Background(new LoaderParams(0, 0, 2800, SCREEN_HEIGHT, texture_menubackground_trees_3_png), 5));
	menu_background->addBackroundElement(new Background(new LoaderParams(0, 0, 4200, SCREEN_HEIGHT, texture_menubackground_night_png), 1));

	std::cout << "entering MenuState\n";
	render();
	return true;
}

bool MenuState::onExit()
{
	GAME->RemoveGameObject(start_button);
	GAME->RemoveGameObject(exit_button);
	//GAME->RemoveGameObject(menu_background);

	TheTextureManager->UnLoad(texture_menubutton_start_png);
	TheTextureManager->UnLoad(texture_menubutton_exit_png);
	TheTextureManager->UnLoad(texture_menubackground_png);


	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::menuToPlay()
{
	GAME->SetState(new PlayState());
}

void MenuState::menuToVoid()
{
	GAME->SetIsRunning(false);
}