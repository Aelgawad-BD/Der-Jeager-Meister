#include "Player.h"
#include "InputHandler.h"
#include "configurations.h"

Player::Player(const LoaderParams* pParams) : Character(pParams)
{
	this->m_scale = 1.5f;
}

void Player::Update()
{
	this->m_velocity.SetX(0);
	this->m_velocity.SetY(0);

	this->HandleInput();

	m_currentFrame = int(((SDL_GetTicks() / 65) % NO_OF_FRAMES_PER_ROW));

	SDLGameObject::Update();
}

void Player::Draw()
{
	SDLGameObject::Draw();
}

void Player::HandleInput()
{
	static bool attack_actionEnabled = true;

	if (attack_actionEnabled == false && m_currentFrame < FRAME_8)
	{
		return;
	}

	attack_actionEnabled = true;

	InputHandler* inpt_hndlr = INPT_HNDLR;

	int lft_nlg_x = inpt_hndlr->GetXDirectionValue();
	int left_nlg_y = inpt_hndlr->GetYDirectionValue();
	bool attack = inpt_hndlr->GetFireButtonValue();

	if (lft_nlg_x > 0 || lft_nlg_x < 0)
	{
		this->m_velocity.SetX(lft_nlg_x * 6);
		m_currentRow = ANIMATION_ROW::RUNNING;

		if (lft_nlg_x < 0)
			m_isFlipped = true;
		else
			m_isFlipped = false;
	}
	/*
	else if (left_nlg_y > 0 || left_nlg_y < 0)
	{
		this->m_velocity.SetY(left_nlg_y);
		m_currentRow = ANIMATION_ROW::IDLE;
	}
	*/
	else if (attack && attack_actionEnabled)
	{
		m_currentRow = ANIMATION_ROW::ATTACK;
		m_currentFrame = 0;
		attack_actionEnabled = false;
	}
	else
	{
		m_currentRow = ANIMATION_ROW::IDLE;
	}

}

void Player::Clean()
{
}