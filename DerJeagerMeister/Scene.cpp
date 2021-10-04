#include "Scene.h"


Scene::Scene()
{

}

Scene::Scene(int w, int h)
{
	this->m_width = w;
	this->m_height = w;
}

void Scene::Update()
{
	for (int i = 0; i < m_backgroundObjects.size(); i++)
	{
		m_backgroundObjects[i]->Update();
	}

}

void Scene::Draw()
{
	for (int i = 0; i < m_backgroundObjects.size(); i++)// for (int i = m_backgroundObjects.size()-1; i >=0; i--)
	{
		m_backgroundObjects[i]->Draw();
	}
}

void Scene::Clean()
{
	for (int i = 0; i < m_backgroundObjects.size(); i++)
	{
		m_backgroundObjects[i]->Clean();
	}

	m_backgroundObjects.clear();
}


int Scene::getWidth()
{
	return this->m_width;
}


int Scene::getHeight()
{
	return this->m_height;
}



void Scene::setWidth(int w)
{
	this->m_width = w;
}

void Scene::setHeight(int h)
{
	this->m_height = h;
}


void Scene::addBackroundElement(Background* bgElement)
{
	m_backgroundObjects.push_back(bgElement);
}
