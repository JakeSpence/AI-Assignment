#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	Vector2 operator + (Vector2 rhs);
	Vector2 operator - (Vector2 rhs);
	Vector2 operator * (Vector2 rhs);
	Vector2 operator * (float scalier);
	Vector2 operator / (float scalier);
	operator float*();

	void operator += (Vector2 rhs);

	float Magnitude();
	float Distance(Vector2 rhs);
	void Normalise();

	float Dot(Vector2 rhs);
	float Angle(Vector2 rhs);

	float GetX();
	float GetY();

	void SetX(float x);
	void SetY(float y);

private:
	float m_x;
	float m_y;
};

Vector2 operator * (float scalier, Vector2& rhs);