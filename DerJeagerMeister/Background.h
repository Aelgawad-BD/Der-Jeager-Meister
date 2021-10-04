#pragma once

#include "configurations.h"
#include "SDLGameObject.h"
// #include "Game.h"

class Background : public SDLGameObject
{
public:

	Background(const LoaderParams* pParams);
	Background(const LoaderParams* pParams, int scrollSpeed);

	void Update();
	void Draw();
	void Clean();

	void setScrollType(BACKGROUND_SCROLL st);
	void setFromTextureDisplayPosition(float x, float y);
	Vector2D getFromTextureDisplayPosition();

private:

	void infiniteScroll_update();
	void widthScroll_update();

	// Background has several SDLObjects that scroll at different speeds to imply depth
	// The higher the index the closer the element is to the scene,
	//   so m_backgroundObjects[0] is the farthest, and thus should be rendered first and scrolls the slowest

	// for scroll-able textures
	// scrolling involves drawing same texture twice
	// variables ending with _alt are related to the second instance drawn

	bool m_activeCycle_alt;

	int m_displayWidth;
	int m_displayWidth_alt;

	Vector2D m_onScreenDisplayPosition;			// you already inherit m_actual_position
	Vector2D m_onScreenDisplayPosition_alt;		// you can recycle m_virtual_position (because it doesn't make sense for backgrounds to have)

	Vector2D m_fromTextureDisplayPosition;
	Vector2D m_fromTextureDisplayPosition_alt;

	BACKGROUND_SCROLL scrollType;

};