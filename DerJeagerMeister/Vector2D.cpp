#include "Vector2D.h"




Vector2D::Vector2D(float x, float y) : m_x(x), m_y(y) {}

float Vector2D::GetX()
{
	return this->m_x;
}

float Vector2D::GetY()
{
	return this->m_y;
}

void Vector2D::SetX(float x)
{
	this->m_x = x;
}

void Vector2D::SetY(float y)
{
	this->m_y = y;
}


float Vector2D::getLength()
{
	return sqrt(((double)m_x * m_x) + ((double)m_y * m_y));
}

// OPerator Overloaders

Vector2D Vector2D::operator+(const Vector2D& v2) const
{
	return Vector2D(this->m_x + v2.m_x, this->m_y + v2.m_y);
}

Vector2D Vector2D::operator-(const Vector2D& v2) const
{
	return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
}

Vector2D Vector2D::operator*(float scalar)
{
	return Vector2D(m_x * scalar, m_y * scalar);
}

Vector2D& Vector2D::operator*=(float scalar)
{
	m_x *= scalar;
	m_y *= scalar;

	return *this;
}

Vector2D Vector2D::operator/(float scalar)
{
	return Vector2D(m_x / scalar, m_y / scalar);
}

Vector2D& Vector2D::operator/=(float scalar)
{
	m_x /= scalar;
	m_y /= scalar;

	return *this;
}

void Vector2D::normalize()
{
	float l = getLength();
	if (l > 0) // we never want to attempt to divide by 0
	{
		(*this) *= 1 / l;
	}
}