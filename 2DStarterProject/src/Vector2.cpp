#include "Vector2.h"
#include <math.h>


Vector2::Vector2()
{
	m_x = 0;
	m_y = 0;
}

Vector2::Vector2(float x, float y)
{
	m_x = x;
	m_y = y;
}

Vector2::~Vector2()
{
}

Vector2 Vector2::operator + (Vector2 rhs)
{
	Vector2 V;
	V.m_x = m_x + rhs.m_x;
	V.m_y = m_y + rhs.m_y;
	return V;
}

Vector2 Vector2::operator - (Vector2 rhs)
{
	Vector2 V;
	V.m_x = m_x - rhs.m_x;
	V.m_y = m_y - rhs.m_y;
	return V;
}

Vector2 Vector2::operator*(Vector2 rhs)
{
	Vector2 V;
	V.m_x = m_x * rhs.m_x;
	V.m_y = m_y * rhs.m_y;
	return V;
}

Vector2 Vector2::operator * (float scalier)
{
	Vector2 V;
	V.m_x = m_x * scalier;
	V.m_y = m_y * scalier;
	return V;
}

Vector2 operator * (float scalier, Vector2& rhs)
{
	Vector2 V;
	V.SetX(rhs.GetX() * scalier);
	V.SetY(rhs.GetY() * scalier);
	return V;
}

Vector2 Vector2::operator / (float scalier)
{
	Vector2 V;
	V.m_x = m_x / scalier;
	V.m_y = m_y / scalier;
	return V;
}

float Vector2::Magnitude()
{
	float mag;
	mag = sqrt((m_x * m_x) + (m_y * m_y));
	return mag;
}

float Vector2::Distance(Vector2 rhs)
{
	return (*this-rhs).Magnitude();
}

void Vector2::Normalise()
{
	float mag = Magnitude();
	m_x = m_x / mag;
	m_y = m_y / mag;
}

float Vector2::Dot(Vector2 rhs)
{
	float answer;
	answer = ((m_x * rhs.m_x) + (m_y * rhs.m_y));
	return answer;
}

float Vector2::Angle(Vector2 rhs)
{
	Normalise();
	rhs.Normalise();
	float f = Dot(rhs);
	return acos(f);
}

Vector2::operator float*()
{
	return (float*)this;
}

void Vector2::operator+=(Vector2 rhs)
{
	m_x = m_x + rhs.GetX();
	m_y = m_y + rhs.GetY();
}

float Vector2::GetX()
{
	return m_x;
}

float Vector2::GetY()
{
	return m_y;
}

void Vector2::SetX(float x)
{
	m_x = x;
}

void Vector2::SetY(float y)
{
	m_y = y;
}