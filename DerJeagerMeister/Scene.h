#pragma once
#include <vector>

#include "Background.h"
// #include "configurations.h"

class Scene
{
public:
	Scene();
	Scene(int w, int h);

	void Update();
	void Draw();
	void Clean();

	int getWidth();
	int getHeight();

	void setWidth(int w);
	void setHeight(int h);
	void addBackroundElement(Background* bgElement);
	
private:

	int m_width;
	int m_height;

	std::vector<Background*> m_backgroundObjects;

};
