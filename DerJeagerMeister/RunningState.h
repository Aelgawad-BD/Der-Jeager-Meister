#pragma once
 #include "GameState.h"

class RunningState : public GameState
{
public:
	void update();
	void render();

	bool onEnter();
	bool onExit();

	virtual std::string getStateID() const { return s_runningID; }

private:
	static const std::string s_runningID;

};