#include "PlayState.h"

#include "Game.h"
#include "PauseState.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Player.h"
//#include "configurations.h"

const std::string PlayState::s_playID = "PLAY";




bool PlayState::onEnter()
{
	if (TheTextureManager->Load(spriteSheet_jeagermeister_png, spriteSheet_jeagermeister_png, GAME->GetRenderer()) == false)
	{
		printf("ERROR >> Spritesheet \"%s\" intialization failed\n", spriteSheet_jeagermeister_png);
		return false;
	}

	if (TheTextureManager->Load(texture_levelbackground_png, texture_levelbackground_png, GAME->GetRenderer()) == false)
	{
		printf("ERROR >> Texture \"%s\" intialization failed\n", texture_levelbackground_png);
		return false;
	}


	this->player = new Player(new LoaderParams(75, 500, 133, 126, spriteSheet_jeagermeister_png));
	this->background = new Background(new LoaderParams(0, 0, 2800, 800, texture_levelbackground_png));

	std::cout << "entering a State of Play\n";
	return true;
}






void PlayState::MoveScene()
{


	// The Master of Puppets
	//  there should be a centralized way to handle all objects
	//	positions, and translate them from logical in game positions
	//	to actual on screen co-ordinates
	//
	//[Todo]
	//	This should NOT be the PlayState class


	// Unless you are close to either the very end or very
	//  begining of the scene


	// But the norm is that the Player is in the middle of the screen, and
	//  the background moves.


}




void PlayState::update()
{
	

	for (int i = 0; i < m_GameObjects.size(); i++)
	{
		m_GameObjects[i]->Update();
	}

	PositionTranslator::TranslatePosition(background, player, m_GameObjects);

	player->Update();

	background->Update();

	if (INPT_HNDLR->GetSelectValue())
		onPause();
}




void PlayState::render()
{

	background->Draw();

	for (int i = 0; i < m_GameObjects.size(); i++)
	{
		m_GameObjects[i]->Draw();
	}

	player->Draw();
}




bool PlayState::onPause()
{
	GAME->PushState(new PauseState());
	return true;
}




bool PlayState::onExit()
{
	player->Clean();

	background->Clean();

	for (int i = 0; i < m_GameObjects.size(); i++)
	{
		m_GameObjects[i]->Clean();
	}

	m_GameObjects.clear();

	TheTextureManager->UnLoad(spriteSheet_jeagermeister_png);

	background->Clean();
	TheTextureManager->UnLoad(texture_levelbackground_png);


	std::cout << "exiting PlayState\n";
	return true;
}