#include "TextureManager.h"
#include <SDL_image.h>

#include "configurations.h"

// non-const static member variables have to be declared here
TextureManager* TextureManager::s_pInstance;

TextureManager::TextureManager()
{
}

TextureManager* TextureManager::GetInstance()
{
	if (s_pInstance == 0)
		s_pInstance = new TextureManager();
	return s_pInstance;
}

bool TextureManager::Load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

	if (pTempSurface == 0)
	{
		return false;
	}

	SDL_Texture* pTexture =
		SDL_CreateTextureFromSurface(pRenderer, pTempSurface);

	SDL_FreeSurface(pTempSurface);

	// everything went ok, add the texture to our list
	if (pTexture != 0)
	{
		m_textureMap[id] = pTexture;
		return true;
	}

	// reaching here means something went wrong
	return false;
}

bool TextureManager::UnLoad(std::string texID)
{
	if (m_textureMap[texID] != NULL)
	{
		SDL_DestroyTexture(m_textureMap[texID]);
		m_textureMap.erase(texID);
		return true;
	}
	return false;
}

// DrawFrame() could be used for both animate and inanimate objects. For inanimate objects set both the frame and row to 1 (both are one-based not zero-based)
void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect dstRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = dstRect.w = width;
	srcRect.h = dstRect.h = height;

	dstRect.x = x;
	dstRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &dstRect, 0, 0, flip);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, float currentFrame,
	SDL_Renderer* pRenderer, float scale, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect dstRect;

	srcRect.x = width * currentFrame;
	srcRect.y = height * currentRow;
	srcRect.w = width;
	srcRect.h = height;

	dstRect.x = x;
	dstRect.y = y;
	dstRect.w = width * scale;
	dstRect.h = height * scale;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &dstRect, 0, 0, flip);
}

void TextureManager::DrawFromTo(std::string id,
	int from_x, int from_y, int from_width, int from_height,
	int to_x, int to_y, int to_width, int to_height,
	SDL_Renderer* pRenderer, float scale, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect dstRect;

	srcRect.x = from_x;
	srcRect.y = from_y;
	srcRect.w = from_width;
	srcRect.h = from_height;

	dstRect.x = to_x;
	dstRect.y = to_y;
	dstRect.w = to_width * scale;
	dstRect.h = to_height * scale;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &dstRect, 0, 0, flip);
}


/*
	The following is used to scroll backgrounds that are wider than the window
*/

void TextureManager::DrawInfiniteScroll(
	std::string id,
	int scrollSpeed,
	int source1X,
	int source2X,
	int destin1X,
	int destin2X,
	int text1Width,
	int text2Width,
	SDL_Renderer* pRenderer)
{

	SDL_Rect srcRect1;
	SDL_Rect dstRect1;

	srcRect1.x = source1X;
	srcRect1.y = 0;// height* currentRow;
	srcRect1.w = text1Width;
	srcRect1.h = SCREEN_HEIGHT;// height;

	dstRect1.x = destin1X;
	dstRect1.y = 0;
	dstRect1.w = text1Width; // SCREEN_WIDTH; //width * scale;
	dstRect1.h = SCREEN_HEIGHT;// height* scale;


	SDL_Rect srcRect2;
	SDL_Rect dstRect2;

	srcRect2.x = source2X;
	srcRect2.y = 0;// height* currentRow;
	srcRect2.w = text2Width;
	srcRect2.h = SCREEN_HEIGHT;// height;

	dstRect2.x = destin2X;
	dstRect2.y = 0;
	dstRect2.w = text2Width; //  SCREEN_WIDTH; //width * scale;
	dstRect2.h = SCREEN_HEIGHT;// height* scale;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect1, &dstRect1, 0, 0, SDL_FLIP_NONE);
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect2, &dstRect2, 0, 0, SDL_FLIP_NONE);
}