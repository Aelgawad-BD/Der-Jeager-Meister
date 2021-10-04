#include "SDLGameObject.h"

#include "Game.h"
#include "TextureManager.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) :
	GameObject(pParams), m_actual_position(pParams->getX(), pParams->getY()), m_virtual_position(pParams->getX(), pParams->getY()), m_velocity(0, 0), m_acceleration(0, 0)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();

	m_currentRow = 0;
	m_currentFrame = 0;
	this->m_scale = 1.0f;
	m_isFlipped = false;
}

void SDLGameObject::Update()
{
	m_virtual_position = m_virtual_position + m_velocity;
	m_velocity = m_velocity + m_acceleration;
}

void SDLGameObject::Draw()
{
	TheTextureManager->DrawFrame(m_textureID, (int)m_actual_position.GetX(), (int)m_actual_position.GetY(),
		m_width, m_height, m_currentRow, m_currentFrame,
		GAME->GetRenderer(), this->m_scale, m_isFlipped ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

//// [Todo] See if the Scroll() can be consolidated with Draw()
////
// void SDLGameObject::Scroll()
// {
//  	TheTextureManager->DrawInfiniteScroll(m_textureID, m_width, GAME->GetRenderer(), int speed);
// }

void SDLGameObject::Clean()
{

}

std::string SDLGameObject::GetTextureId()
{
	return this->m_textureID;
}

int SDLGameObject::GetTextureWidth()
{
	return this->m_width;
}

int SDLGameObject::GetXSpeed()
{
	return this->m_velocity.GetX();
}

Vector2D SDLGameObject::GetVirtualPosition()
{
	return this->m_virtual_position;
}

Vector2D SDLGameObject::GetActualPosition()
{
	return this->m_actual_position;
}

void SDLGameObject::SetXSpeed(int xSpeed)
{
	this->m_velocity.SetX(xSpeed);
}

void SDLGameObject::SetActualPosition(float x, float y)
{
	this->m_actual_position.SetX(x);
	this->m_actual_position.SetY(y);
}