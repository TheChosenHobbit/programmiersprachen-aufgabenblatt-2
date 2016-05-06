#include "mat2.hpp"
#include <cmath>

//float Pi = 4.0*atan(1.0);

Mat2::Mat2():
w{1},
x{1},
y{1},
z{1} {} //kein Destruktor notwendig da hier zB keine geoeffnete Datei benutzt wurde

Mat2::Mat2(float a, float b, float c, float d):
w{a},
x{b},
y{c},
z{d} {}

float Mat2::det() const
{
	return w*z - x*y;
}

Mat2& Mat2::operator*=(Mat2 const& m)
{
	w *= m.w;
	x *= m.x;
	y *= m.y;
	z *= m.z;
	return *this;
}


Mat2 operator*(Mat2 const& m1, Mat2 const& m2)
{
	Mat2 matrix;
	matrix.w = m1.w * m2.w;
	matrix.x = m1.x * m2.x;
	matrix.y = m1.y * m2.y;
	matrix.z = m1.z * m2.z;
	return matrix;
}

Vec2 operator*(Mat2 const& m, Vec2 const& v)
{
	Vec2 v1;
	v1.x = m.w*v.x + m.x*v.y;
	v1.y = m.y*v.x + m.z*v.y;
	return v1;
}


Vec2 operator*(Vec2 const& v, Mat2 const& m)
{
	Vec2 v1;
	v1.x = m.w*v.x + m.x*v.y;
	v1.y = m.y*v.x + m.z*v.y;
	return v1;
}

Mat2 inverse(Mat2 const& m){
	Mat2 m1;
	m1.w = m.z;
	m1.x = -m.x;
	m1.y = -m.y;
	m1.z = m.w;
	return m1;
}

Mat2 transpose(Mat2 const m){
	Mat2 m1;
	m1.w = m.w;
	m1.x = m.y;
	m1.y = m.x;
	m1.z = m.z;
	return m1;
}

Mat2 make_rotation_mat2(float phi){
	Mat2 m1;
	m1.w = cos(phi) /* * Pi / 180.0*/ ;
	m1.x = -sin(phi) /* * Pi / 180.0*/ ;
	m1.y = sin(phi);
	m1.z = cos(phi);
	return m1;
}