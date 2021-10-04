#pragma once

#include <vector>

#include "GameObject.h"
#include "GameState.h"
#include "Player.h"
#include "PositionTranslator.h"
#include "Scene.h"

class PlayState : public GameState
{
public:
	void update();
	void render();

	bool onEnter();
	void MoveScene();
	bool onPause();
	bool onExit();

	virtual std::string getStateID() const { return s_playID; };

private:

	static const std::string s_playID;

	Player* player;
	std::vector<GameObject*> m_GameObjects;

	// Scene* scene; // Use a Background for now, and ever maybe!
	Background* background;
	
};
