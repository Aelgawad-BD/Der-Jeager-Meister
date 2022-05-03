#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "GameState.h"
#include "MenuState.h"
#include "configurations.h"

// Is this called once on start?
Game* Game::s_pInstance = 0;

Game::Game()
{
}

Game::~Game()
{
}

Game* Game::GetInstance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new Game();
	}
	return s_pInstance;
}

bool Game::Initialize()
{
	this->IsRunning = true;

	this->m_textureManager = TheTextureManager;
	// Init SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("ERROR >> SDL couldn't initialize\n SDL says: %s", SDL_GetError());
		this->IsRunning = false;
	}

	// Create Window
	this->gmWindow = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN); // SDL_WINDOW_FULLSCREEN); // SDL_WINDOW_RESIZABLE);// 
	if (this->gmWindow == NULL)
	{
		printf("ERROR >> Window could not be created! \n SDL says: %s", SDL_GetError());
		this->IsRunning = false;
	}

	// Intialize Renderer (if you are using one)
	this->gmRenderer = SDL_CreateRenderer(this->gmWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (this->gmRenderer == NULL)
	{
		printf("ERROR >> Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		this->IsRunning = false;
	}

	// Renderer was successfully created. Now initialize to color
	SDL_SetRenderDrawColor(this->gmRenderer, 0x11, 0x11, 0x11, 0xFF);

	int imgFlags = IMG_INIT_PNG;
	if ((IMG_Init(imgFlags) & imgFlags) == false)
	{
		printf("ERROR >> SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		this->IsRunning = false;
	}

	if (TheTextureManager->Load(spriteSheet_jeagermeister_png, spriteSheet_jeagermeister_png, gmRenderer) == false)
	{
		printf("ERROR >> Spritesheet \"%s\" intialization failed\n", spriteSheet_jeagermeister_png);
		this->IsRunning = false;
	}
	if (TheTextureManager->Load(texture_introcard_title_png, texture_introcard_title_png, gmRenderer) == false)
	{
		printf("ERROR >> Spritesheet \"%s\" intialization failed\n", texture_introcard_title_png);
		this->IsRunning = false;
	}

	// Instantiate GameStateMachine
	m_pGameStateMachine = new GameStateMachine();

	// // create intro screen
	this->m_IntroCards.push_back(new IntroCard(new LoaderParams(0, 0, 105, 42, texture_introcard_title_png), 12000));

	if (this->IsRunning)
		m_pGameStateMachine->changeState(new MenuState());// GAME_STATE::IntroScreen;
	//else
		// this->m_state = GAME_STATE::Undetermined;

	console = Console::GetInstance();

	return this->IsRunning;
}

void Game::HandleEvents()
{
	INPT_HNDLR->update();
}

void Game::Update()
{
	this->m_pGameStateMachine->update();
}

void Game::Render()
{
	SDL_RenderClear(gmRenderer);	// clear to the draw colour

	this->m_pGameStateMachine->render();

	SDL_RenderPresent(gmRenderer);	// draw to the screen

	framesRendered++;				// Keep track of how many frames drawn on screen
}

bool Game::GetIsRunning()
{
	return this->IsRunning;
}

void Game::SetIsRunning(bool running)
{
	this->IsRunning = running;
}

SDL_Renderer* Game::GetRenderer()
{
	return this->gmRenderer;
}

void Game::SetState(GameState* state)
{
	this->m_pGameStateMachine->changeState(state);
}

void Game::PopState()
{
	this->m_pGameStateMachine->popState();
}

void Game::PushState(GameState* state)
{
	this->m_pGameStateMachine->pushState(state);
}

void Game::Shutdown()
{
	INPT_HNDLR->clean();
	delete m_pGameStateMachine;
	exit(0);
}

void Game::AddGameObject(GameObject* gameObject)
{
	if (gameObject != NULL)
	{
		this->m_GameObjects.push_back(gameObject);
	}
}

void Game::RemoveGameObject(GameObject* gameObject)
{
	if (gameObject != NULL)
	{
		std::vector<GameObject*>::iterator objectIter =
			std::find(m_GameObjects.begin(), m_GameObjects.end(), gameObject);

		if (objectIter != m_GameObjects.end())
			m_GameObjects.erase(objectIter);
	}
}

void Game::ConsoleLog()
{
	float secondsGone = SDL_GetTicks() / 1000.0f;
	console->SetCursorPosition(5, 5);
	std::cout << "Seconds Count: " << (int)secondsGone;
	console->SetCursorPosition(5, 7);
	std::cout << "Frame Count: " << framesRendered;
	console->SetCursorPosition(5, 9);
	std::cout << "Avg FPS: " << (int)(framesRendered / secondsGone);

	
	
	std::cout << std::endl;
	std::cout << std::endl;
}