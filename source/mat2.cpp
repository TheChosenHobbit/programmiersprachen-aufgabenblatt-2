#include "mat2.hpp"

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