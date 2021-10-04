#include "Background.h"
#include "Game.h"
#include "TextureManager.h"

Background::Background(const LoaderParams* pParams)
	: SDLGameObject(pParams)
	, m_activeCycle_alt(false)
	, m_displayWidth(SCREEN_WIDTH)
	, m_displayWidth_alt(0)
	, m_onScreenDisplayPosition(0, 0)
	, m_onScreenDisplayPosition_alt(SCREEN_WIDTH, 0)
	, m_fromTextureDisplayPosition(m_actual_position.GetX(), m_actual_position.GetY())
	, m_fromTextureDisplayPosition_alt(0, 0)
{
	setScrollType(BACKGROUND_SCROLL::WIDTH_SCROLL);
}

Background::Background(const LoaderParams* pParams, int scrollSpeed)
	: SDLGameObject(pParams)
	, m_activeCycle_alt(false)
	, m_displayWidth(SCREEN_WIDTH)
	, m_displayWidth_alt(0)
	, m_onScreenDisplayPosition(0, 0)
	, m_onScreenDisplayPosition_alt(SCREEN_WIDTH, 0)
	, m_fromTextureDisplayPosition(m_actual_position.GetX(), m_actual_position.GetY())
	, m_fromTextureDisplayPosition_alt(0, 0)
{
	this->SetXSpeed(scrollSpeed);
	scrollSpeed > 0 ?
		this->setScrollType(BACKGROUND_SCROLL::INFINITE_SCROLL)
		: this->setScrollType(BACKGROUND_SCROLL::WIDTH_SCROLL);
}

void Background::Update()
{
	if (this->scrollType == INFINITE_SCROLL)
	{
		this->infiniteScroll_update();
	}
	else if (this->scrollType == WIDTH_SCROLL)
	{
		this->widthScroll_update();
	}
}

void Background::Draw()
{
	if (this->scrollType == INFINITE_SCROLL)
	{
		TheTextureManager->DrawInfiniteScroll(
			this->GetTextureId(),
			this->m_velocity.GetX(),
			this->m_fromTextureDisplayPosition.GetX(),
			this->m_fromTextureDisplayPosition_alt.GetX(),
			this->m_onScreenDisplayPosition.GetX(),
			this->m_onScreenDisplayPosition_alt.GetX(),
			this->m_displayWidth,
			this->m_displayWidth_alt,
			GAME->GetRenderer());
	}
	else if (this->scrollType == WIDTH_SCROLL)
	{
		TheTextureManager->DrawFromTo(this->m_textureID,
			this->getFromTextureDisplayPosition().GetX(),
			this->getFromTextureDisplayPosition().GetY(),
			SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
			GAME->GetRenderer(), this->m_scale, this->m_isFlipped ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
	}
}

void Background::infiniteScroll_update()
{
	int source1X = m_actual_position.GetX();
	int source2X = m_fromTextureDisplayPosition_alt.GetX();

	int destin1X = m_onScreenDisplayPosition.GetX();
	int destin2X = m_onScreenDisplayPosition_alt.GetX();

	int text1Width = m_displayWidth;
	int text2Width = m_displayWidth_alt;

	int scrollSpeed = GetXSpeed();

	if (m_activeCycle_alt == false)
	{
		m_actual_position.SetX(source1X + scrollSpeed);

		if (source1X > (m_width - SCREEN_WIDTH) && source1X <= m_width)
		{
			m_displayWidth -= scrollSpeed;
			m_displayWidth_alt += scrollSpeed;

			m_onScreenDisplayPosition_alt.SetX(destin2X - scrollSpeed);// Creeps up from right to left
		}

		if (source1X >= m_width)
		{
			m_activeCycle_alt = true;
			m_onScreenDisplayPosition.SetX(SCREEN_WIDTH);
			m_onScreenDisplayPosition_alt.SetX(0);
			m_actual_position.SetX(0);
		}
	}
	else
	{
		m_fromTextureDisplayPosition_alt.SetX(source2X + scrollSpeed);

		if (source2X > (m_width - SCREEN_WIDTH) && source2X <= m_width)
		{
			m_displayWidth_alt -= scrollSpeed;
			m_displayWidth += scrollSpeed;

			m_onScreenDisplayPosition.SetX(destin1X - scrollSpeed);
		}
		if (source2X >= m_width)
		{
			m_activeCycle_alt = false;
			m_onScreenDisplayPosition_alt.SetX(SCREEN_WIDTH);
			m_onScreenDisplayPosition.SetX(0);
			m_fromTextureDisplayPosition_alt.SetX(0);
		}
	}

	m_fromTextureDisplayPosition = m_actual_position;

}

void Background::widthScroll_update()
{

}

void Background::setScrollType(BACKGROUND_SCROLL st)
{
	this->scrollType = st;
}

void Background::setFromTextureDisplayPosition(float x, float y)
{
	this->m_fromTextureDisplayPosition.SetX(x);
	this->m_fromTextureDisplayPosition.SetY(y);
}

Vector2D Background::getFromTextureDisplayPosition()
{
	return m_fromTextureDisplayPosition;
}


void Background::Clean()
{

}