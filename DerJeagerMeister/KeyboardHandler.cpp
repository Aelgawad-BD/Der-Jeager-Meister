#include "KeyboardHandler.h"
#include <SDL.h>

KeyboardHandler::KeyboardHandler()
{
	// Not Used
	this->keyStates = SDL_GetKeyboardState(NULL);

}

void KeyboardHandler::update()
{
	this->right_keyState = false;
	this->down_keyState = false;
	this->left_keyState = false;
	this->up_keyState = false;

	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_LEFT:
				left_keyState = true;
				break;

			case SDLK_UP:
				up_keyState = true;
				break;

			case SDLK_RIGHT:
				right_keyState = true;
				break;

			case SDLK_DOWN:
				down_keyState = true;
				break;

			case SDLK_RETURN:
				//case SDLK_ESCAPE:
				if (select_keyEnabled)
				{
					select_keyState = true;
					select_keyEnabled = false;
				}
				break;
			}
		}

		if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_RETURN:
				//case SDLK_ESCAPE:
				select_keyEnabled = true;
				select_keyState = false;
				break;
			}
		}

	}

}


void KeyboardHandler::clean()
{

}

float KeyboardHandler::GetXDirectionValue()
{
	//if (currentDirectionKeyStates[2])
	//	return 1.0f;
	//else if (currentDirectionKeyStates[0])
	//	return -1.0f;
	//else
	//	return 0.0f;

	if (keyStates[SDL_SCANCODE_RIGHT] == 1)
		return 1.0f;
	else if (keyStates[SDL_SCANCODE_LEFT] == 1)
		return -1.0f;
	else
		return 0.0f;
}

float KeyboardHandler::GetYDirectionValue()
{

	if (down_keyState == 1)
		return 1.0f;
	else if (up_keyState == 1)
		return -1.0f;
	else
		return 0.0f;
}

bool KeyboardHandler::GetFireButtonValue()
{
	return keyStates[SDL_SCANCODE_SPACE];
}

bool KeyboardHandler::GetSelectValue()
{
	// The reason I set it off with every read is because
	//  if it is left true it eould behave as if some one kept holding 
	//  the return (Enter) key forever, even when they are not

	// Handling the case where someone is holding the return 
	// key indefininetly is handeled in the key press event (update())

	// So far, this problem is only relevant to pressing return in menu items

	bool temp = select_keyState;
	select_keyState = false;
	return temp;
}