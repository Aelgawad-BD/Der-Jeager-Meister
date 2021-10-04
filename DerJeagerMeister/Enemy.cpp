#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : Character(pParams)
{

}

void Enemy::Draw()
{
	SDLGameObject::Draw(); // we now use SDLGameObject
}

void Enemy::Update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 8));
}

void Enemy::Clean()
{
}