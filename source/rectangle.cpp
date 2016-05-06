#include "rectangle.hpp"

Rectangle::Rectangle():
left_{0,1},
right_{1,0},
color_{0,0,0}{}

Rectangle::Rectangle(Point2D const& leftUpperPoint, Point2D const& rightLowerPoint, Color const& clr):
left_{leftUpperPoint},
right_{rightLowerPoint},
color_{clr}{}

Color Rectangle::getColor() const
{
	return color_;
}

Point2D Rectangle::getLeftPoint2D() const
{
	return left_;
}

Point2D Rectangle::getRightPoint2D() const
{
	return right_;
}