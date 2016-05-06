#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "circle.hpp"

/*struct Point2D
{
	float x, y;
};

struct Color
{
	float r, g, b;
};*/


class Rectangle
{
public:
	Rectangle();
	Rectangle(Point2D const& leftUpperPoint, Point2D const& rightLowerPoint, Color const& clr);


	Point2D getLeftPoint2D() const;
	Point2D getRightPoint2D() const;
	Color getColor() const;

private:
	Point2D left_;
	Point2D right_;
	Color color_;
};


#endif