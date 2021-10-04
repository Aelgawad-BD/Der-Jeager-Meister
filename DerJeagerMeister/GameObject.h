#pragma once

#include "LoaderParams.h"
//#include "configurations.h"

#include <SDL.h>
#include <string>
#include <vector>

class GameObject
{
	//protected:
	//	std::string m_textureID;
	//	int m_XPos;
	//	int m_YPos;
	//	int m_width;
	//	int m_height;
	//	int m_currentRow;
	//	int m_currentFrame;

public:

	GameObject(const LoaderParams* params);
	virtual void Update() = 0;
	virtual void Draw() = 0;
	// virtual void infiniteScroll_update() = 0;
	virtual void Clean() = 0;
};