#include "IntroCard.h"

#include "configurations.h"


IntroCard::IntroCard(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_currentFrame = 0;
	startTimeStamp = SDL_GetTicks();
	isOn = true;
}

IntroCard::IntroCard(const LoaderParams* pParams, unsigned int duration) : SDLGameObject(pParams), m_displayTime(duration)
{
	m_currentFrame = 0;
	startTimeStamp = SDL_GetTicks();
	isOn = true;
	this->m_scale = 4.0f;
	Center();
}

void IntroCard::SetDisplayTime(unsigned int duration)
{
	m_displayTime = duration;
}

void IntroCard::Update()
{
	unsigned int currentTimeStampSec = SDL_GetTicks();
	if (currentTimeStampSec - startTimeStamp < m_displayTime)
	{
		// this->Draw();
	}
	else
	{
		this->startTimeStamp = 0;
		isOn = false;
	}
}

void IntroCard::Draw()
{
	SDLGameObject::Draw();
}

void IntroCard::Center()
{
	this->m_actual_position.SetX(SCREEN_WIDTH / 2 - ((this->m_width * this->m_scale) / 2));
	this->m_actual_position.SetY((SCREEN_HEIGHT / 2) - ((this->m_height * this->m_scale) / 2));
}