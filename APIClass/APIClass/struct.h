#pragma once

struct Vec2
{
public : 
	float x;
	float y;

public :
	Vec2() :
		x(0.f),
		y(0.f)
	{

	}

	Vec2(float _x, float _y) :
		x(_x),
		y(_y)
	{

	}

	Vec2(UINT _x, UINT _y) :
		x((float)_x),
		y((float)_y)
	{

	}
	~Vec2()
	{

	}


public:

	void Normalize()
	{
		float Dist = sqrtf(x * x + y * y);
		x /= Dist;
		y /= Dist;
	}

	Vec2 operator + (Vec2 _other)
	{
		return Vec2(x + _other.x, y + _other.y);
	}

	Vec2 operator += (Vec2 _other)
	{
		return Vec2(x += _other.x, y += _other.y);
	}

	Vec2 operator - (Vec2 _other)
	{
		return Vec2(x - _other.x, y - _other.y);
	}

	Vec2 operator -= (Vec2 _other)
	{
		return Vec2(x -= _other.x, y -= _other.y);
	}

};

struct tEvent
{
	EVENT_TYPE	eType;
	DWORD_PTR	wParam;
	DWORD_PTR	lParam;
};