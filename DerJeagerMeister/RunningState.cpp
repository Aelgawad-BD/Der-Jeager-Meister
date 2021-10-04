#include "RunningState.h"

const std::string RunningState::s_runningID = "RUN";

void RunningState::update()
{
	// nothing for now
}

void RunningState::render()
{
	// nothing for now
}

bool RunningState::onEnter()
{
	std::cout << "entering PlayState\n";
	return true;
}

bool RunningState::onExit()
{
	std::cout << "exiting PlayState\n";
	return true;
}