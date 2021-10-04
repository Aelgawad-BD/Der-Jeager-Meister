#include <iostream>

#include "configurations.h"
#include "Game.h"

int main(int argc, char** args)
{
	Uint32 frameStart;
	Uint32 frameTime;

	Game* pGame = GAME;

	std::cout << "Initializing..." << std::endl;

	if (pGame->Initialize() == false)
	{
		std::cout << "Initialization Failed: " << SDL_GetError() << std::endl;
		return 0;
	}

	std::cout << "Initialization Complete." << std::endl;

	while (pGame->GetIsRunning())
	{
		frameStart = SDL_GetTicks();

		pGame->HandleEvents();
		pGame->Update();
		pGame->ConsoleLog();
		pGame->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < DELAY_TIME)
			SDL_Delay((int)DELAY_TIME - frameTime);
	}

	std::cout << "Shutting Down..." << std::endl;

	pGame->Shutdown();

	return 0;
}