#ifndef MAT2_HPP
#define MAT2_HPP

class Mat2
{
public:
	Mat2();

	Mat2(float a, float b, float c, float d);

	float w;
	float x;
	float y;
	float z;

	Mat2& operator*=(Mat2 const& m);
};

Mat2 operator*(Mat2 const& m1, Mat2 const& m2);

#endif