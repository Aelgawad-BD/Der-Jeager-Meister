#pragma once

#include "GameObject.h"
#include "GameState.h"

#include <vector>


class PauseState : public GameState
{
public:
	void update();
	void render();

	bool onEnter();
	bool onExit();
	virtual std::string getStateID() const { return s_pauseId; }

private:
	static const std::string s_pauseId;

	static void pauseToPlay();
	static void pauseToMenu();

	GameObject* resume_button;
	GameObject* menu_button;

	int index;

	std::vector<GameObject*> m_gameObjects;
};