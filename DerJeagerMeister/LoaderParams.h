#pragma once
#include <string>

// Bundles up all the constant GameObject values that do not change during the course of the game
//  also makes GameObject re-usable for other projects

class LoaderParams
{
private:
	std::string m_texid;
	int m_x;
	int m_y;
	int m_w;
	int m_h;

public:
	LoaderParams(int x, int y, int width, int height, std::string
		textureID) : m_x(x), m_y(y), m_w(width), m_h(height),
		m_texid(textureID)
	{
		// every thing is assigned up there!
	}

	// GETTERS
	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_w; }
	int getHeight() const { return m_h; }
	std::string getTextureID() const { return m_texid; }
};