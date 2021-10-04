#pragma once

//#include <stdio.h>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "MenuObject.h"
#include "IntroCard.h"
#include "GameStateMachine.h"
#include "Console.h"
#include "TextureManager.h"

#define GAME Game::GetInstance()

// Singelton:
//   GAME

class Game
{
private:
	SDL_Window* gmWindow;
	SDL_Renderer* gmRenderer;
	bool IsRunning;
	TextureManager* m_textureManager;
	std::vector<IntroCard*> m_IntroCards;
	std::vector <GameObject*> m_GameObjects;
	MenuObject* m_menu;
	GameStateMachine* m_pGameStateMachine;
	//GAME_STATE m_state;
	Game();
	~Game();
	static Game* s_pInstance;
	Console* console;
	int framesRendered;

public:
	static Game* GetInstance();

	bool Initialize();
	void HandleEvents();
	void Update();
	void Render();
	void Shutdown();
	void ConsoleLog();

	void AddGameObject(GameObject* gameObject);
	void RemoveGameObject(GameObject* gameObject);
	bool GetIsRunning();
	void SetIsRunning(bool running);
	SDL_Renderer* GetRenderer();
	void PushState(GameState* state);
	void SetState(GameState* state);
	void PopState();
};