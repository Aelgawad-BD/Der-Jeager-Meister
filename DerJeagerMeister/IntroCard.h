#pragma once

#include "SDLGameObject.h"
//#include "LoaderParams.h"


class IntroCard : public SDLGameObject
{
private:
	unsigned int startTimeStamp;
	unsigned int m_displayTime;

public:
	bool isOn;
	IntroCard(const LoaderParams* pParams);
	IntroCard(const LoaderParams* pParams, unsigned int duration);
	void SetDisplayTime(unsigned int duration);
	void Update();
	void Draw();
	void Center();
};