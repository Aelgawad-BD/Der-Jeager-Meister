#pragma once

#include "Player.h"
#include "Scene.h"
#include "SDLGameObject.h"
//#include "configurations.h"

class PositionTranslator
{
public:

	static bool AtCenter(int range, int position)
	{
		return (position >= (range / 2) - MARGIN) && (position <= (range / 2) + MARGIN);
	}

	static void TranslatePosition(Background* background, Player* player, std::vector<GameObject*> others)
	{
		/*
		 *
		 * Three Factoring sizes and positions
		 * -- SCREEN aka View Port
		 * -- SCENE and other inanimate objects (and animate but not moving)
		 * -- PLAYER
		 *
		 */

		 // For PLAYER
		 //  Get players position (logical position) from PLayer Object
		 //  Work out where on screen it should be (Actual position)
		 //  update the player objects position

		// For SCENE
		//  represent the camera as an SDL_Rect which should be smaller than
		//  the actual background texture. Update the SDL_Rect accordingly

		//float playerXLogicalPos = player->GetVirtualPosition().GetX();
		//float playerYLogicalPos = player->GetVirtualPosition().GetY();
		//int playerXSpeed = player->GetXSpeed();

		//SDL_Rect Camera;

		//Camera.x = (int)background->getFromTextureDisplayPosition().GetX();
		//Camera.y = (int)background->getFromTextureDisplayPosition().GetY();
		//Camera.w = SCREEN_WIDTH;
		//Camera.h = SCREEN_HEIGHT;

		// player->SetActualPosition(player->GetVirtualPosition().GetX(), player->GetVirtualPosition().GetY());

		//if (playerXLogicalPos < (SCREEN_WIDTH / 2) + MARGIN
		//	&&
		//	playerXLogicalPos >(SCREEN_WIDTH / 2) - MARGIN)
		//{
		//	// is there more background to the right??
		//	if (Camera.x + Camera.w <= background->GetTextureWidth() && playerXSpeed >= 0)
		//	{
		//		// Char in mid-screen and Camera HAS NOT yet scrolled all the way to the right end.
		//		player->SetActualPosition(SCREEN_WIDTH / 2, playerYLogicalPos);
		//		Camera.x += playerXSpeed;
		//	}
		//	else if (Camera.x > 0 && playerXSpeed < 0)
		//	{
		//		player->SetActualPosition(SCREEN_WIDTH / 2, playerYLogicalPos);
		//		Camera.x += playerXSpeed;
		//	}
		//}

		//background->setFromTextureDisplayPosition(Camera.x, Camera.y);



		///////////////////////////////////////////////////////////////////////////////////////
		///
		////////////////////////////////////////
		///
		///////////////////////////////////////////////////////////////////////////////////////


		player->SetActualPosition(player->GetActualPosition().GetX() + player->GetXSpeed(), player->GetActualPosition().GetY());

		if (
			(player->GetActualPosition().GetX() <= ((SCREEN_WIDTH / 2) + MARGIN))
			&&
			(player->GetActualPosition().GetX() >= ((SCREEN_WIDTH / 2) - MARGIN))
			)

		{
			if (background->getFromTextureDisplayPosition().GetX() + SCREEN_WIDTH < background->GetTextureWidth() && player->GetXSpeed() >= 0)
			{
				player->SetActualPosition(SCREEN_WIDTH / 2, player->GetActualPosition().GetY());
				background->setFromTextureDisplayPosition(background->getFromTextureDisplayPosition().GetX() + player->GetXSpeed(), background->getFromTextureDisplayPosition().GetY());
			}
			else if (background->getFromTextureDisplayPosition().GetX() > 0 && player->GetXSpeed() < 0)
			{
				player->SetActualPosition(SCREEN_WIDTH / 2, player->GetActualPosition().GetY());
				background->setFromTextureDisplayPosition(background->getFromTextureDisplayPosition().GetX() + player->GetXSpeed(), background->getFromTextureDisplayPosition().GetY());
			}
		}
	}
};