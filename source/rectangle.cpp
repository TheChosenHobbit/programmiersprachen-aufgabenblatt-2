#include "rectangle.hpp"
#include "window.hpp"
#include <cmath>

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

float Rectangle::circumference() const
{
	return 2* fabs((right_.x-left_.x)) + 2* fabs((left_.y - right_.y)); 
}

void Rectangle::draw(Window& win)
{
	win.draw_line(left_.x, left_.y,
				 right_.x, left_.y,
				color_.r, color_.g, color_.b);

	win.draw_line(right_.x, left_.y,
				 right_.x, right_.y,
				color_.r, color_.g, color_.b);

	win.draw_line(left_.x, right_.y,
				 right_.x, right_.y,
				color_.r, color_.g, color_.b);

	win.draw_line(left_.x, right_.y,
				 left_.x, left_.y,
				color_.r, color_.g, color_.b);
}

void Rectangle::draw(Window& win, Color clr)
{
	win.draw_line(left_.x, left_.y,
				 right_.x, left_.y,
				clr.r, clr.g, clr.b);

	win.draw_line(right_.x, left_.y,
				 right_.x, right_.y,
				clr.r, clr.g, clr.b);

	win.draw_line(left_.x, right_.y,
				 right_.x, right_.y,
				clr.r, clr.g, clr.b);

	win.draw_line(left_.x, right_.y,
				 left_.x, left_.y,
				clr.r, clr.g, clr.b);
}

bool Rectangle::is_inside(Point2D point)
{
	if (right_.x < left_.x || right_.y < left_.y)
	{
		if(point.x > right_.x && point.x < left_.x && point.y > left_.y && point.y < right_.y)
		{
			return true;
		}
	}


	if(point.x < right_.x && point.x > left_.x && point.y < left_.y && point.y > right_.y)
	{
		return true;
	} else {
		return false;
	}
}