#pragma once
//
//#include "Game.h"
#include "GameState.h"
#include "GameObject.h"
#include "Scene.h"
//#include "MenuButton.h"
//#include "Background.h"
//#include "PlayState.h"

/*
	I am assuming that there is only one menu
	and the menu state has menu button objects

	[ToDo]
	The proper way is to have a MenuObject (that does not extend SDLGameObject)
	and the MenuObject in turn has the MenuButtonObject(s), and perhaps a background tecture
	and MenuState object has a vector referring to all menus (MenuObjects) there are in the game
*/

class MenuState : public GameState
{
	void update();
	void render();

	bool onEnter();
	bool onExit();

	virtual std::string getStateID() const { return s_menuID; }

private:

	// [ToDo] Create a vector to hold the MenuObjects
	GameObject* start_button;
	GameObject* exit_button;
	Scene* menu_background;

	int index = 0;
	static const std::string s_menuID;

	static void menuToPlay();
	static void menuToVoid();
};