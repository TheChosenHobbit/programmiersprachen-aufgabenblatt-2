#include "vec2.hpp"

Vec2::Vec2():
x{0},
y{0} {} //kein Destruktor notwendig da hier zB keine geoeffnete Datei benutzt wurde

Vec2::Vec2(float a, float b):
x{a},
y{b} {}

Vec2& Vec2::operator+=(Vec2 const& v)
{
	x += v.x;
	y += v.y;

	return *this;
}

Vec2& Vec2::operator-=(Vec2 const& v)
{
	x -= v.x;
	y -= v.y;

	return *this;
}

Vec2& Vec2::operator*=(float v)
{
	x *= v;
	y *= v;
	return *this;
}

Vec2& Vec2::operator/(float v)
{
	x /= v;
	y = y/v;
	return *this;
}


Vec2 operator+(Vec2 const& u, Vec2 const& v)
{
	Vec2 Vector;
	Vector.x = u.x + v.x;
	Vector.y = u.y + v.y;
	return Vector;
}

Vec2 operator-(Vec2 const& u, Vec2 const& v)
{
	Vec2 Vector;
	Vector.x = u.x - v.x;
	Vector.y = u.y - v.y;
	return Vector;
}


Vec2 operator*(Vec2 const& u, float s)
{
	Vec2 Vector;
	Vector.x = u.x * s;
	Vector.y = u.y * s;
	return Vector;
}

Vec2 operator/(Vec2 const& u, float s)
{
	Vec2 Vector;
	Vector.x = u.x / s;
	Vector.y = u.y / s;
	return Vector;
}

Vec2 operator*(float s, Vec2 const& v)
{
	Vec2 Vector;
	Vector.x = v.x * s;
	Vector.y = v.y * s;
	return Vector;
}