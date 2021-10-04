#pragma once
#include <math.h>

class Vector2D
{
private:
	float m_x;
	float m_y;

public:

	Vector2D(float x, float y);

	float GetX();
	float GetY();

	void SetX(float x);
	void SetY(float y);

	float getLength();

	Vector2D operator+(const Vector2D& v2) const;

	Vector2D operator-(const Vector2D& v2) const;

	Vector2D& operator/=(float scalar);

	void normalize();

	Vector2D operator*(float scalar);

	Vector2D& operator*=(float scalar);

	Vector2D operator/(float scalar);

};

