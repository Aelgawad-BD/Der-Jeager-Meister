#pragma once
#include <map>
#include <string>
#include <SDL.h>

// Singelton 
//  handles all image assets throught the game
#define  TheTextureManager TextureManager::GetInstance()

class TextureManager
{
private:

	std::map<std::string, SDL_Texture*> m_textureMap;
	static TextureManager* s_pInstance;
	TextureManager();

public:

	static TextureManager* GetInstance();
	bool Load(std::string filename, std::string id, SDL_Renderer* renderer);
	bool UnLoad(std::string id);
	void Draw(std::string id, int xPos, int yPos, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, float currentFrame, SDL_Renderer* pRenderer, float scale, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawFromTo(std::string id, int from_x, int from_y, int from_width, int from_height, int to_x, int to_y,
	                int to_width, int to_height, SDL_Renderer* pRenderer, float scale, SDL_RendererFlip flip);
	void DrawInfiniteScroll(std::string id, int scrollSpeed, int source1X, int source2X, int destin1X, int destin2X, int text1Width, int text2Width, SDL_Renderer* pRenderer);
};