#pragma once

#include "GameObject.h"
#include "Vector2D.h"


class SDLGameObject : public GameObject
{
	// #pragma message("SDLGameObject is included")
protected:

	std::string m_textureID;
	Vector2D m_virtual_position;
	Vector2D m_actual_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	int m_width;
	int m_height;
	int m_currentRow;
	float m_currentFrame;
	bool m_isFlipped;
	float m_scale;

public:

	SDLGameObject(const LoaderParams* params);
	virtual void Update();
	virtual void Draw();
	virtual void Clean();

	// GETTERS
	virtual std::string GetTextureId();
	virtual int GetTextureWidth();
	virtual int GetXSpeed();
	virtual Vector2D GetVirtualPosition();
	virtual Vector2D GetActualPosition();


	// SETTERS
	void SetXSpeed(int xSpeed);
	void SetActualPosition(float x, float y);

};