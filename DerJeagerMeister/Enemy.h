#pragma once
#include "Character.h"
#include "SDLGameObject.h"

// Enemy class
class Enemy : public Character
{
public:

	Enemy(const LoaderParams* pParams);

	virtual void Draw();
	virtual void Update();
	virtual void Clean();
};