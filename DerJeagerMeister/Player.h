#pragma once
//
#include "Character.h"
#include "SDLGameObject.h"
//#include "InputHandler.h"
// ToDo: Should Player be Singelton?

class Player : public Character
{
public:

	Player(const LoaderParams* pParams);

	virtual void Update();
	virtual void Draw();
	virtual void Clean();	

	// void CacheFrames();

private:
	void HandleInput();
	// void HandleAttack();
};