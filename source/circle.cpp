#include "circle.hpp"
#include "window.hpp"
//#include "color.hpp"
//#include "point2d.hpp"
#include <cmath>
#include <math.h>



float Pi = 4.0*atan(1.0);

Circle::Circle():
center_{1,1},
radius_{1.0},
color_{0,0,0}{}

Circle::Circle(Point2D const& ctr, float r, Color const& clr):
center_{ctr},
radius_{r},
color_{clr}{}

Color Circle::getColor() const
{
	return color_;
}

Point2D Circle::getPoint2D() const
{
	return center_;
}

float Circle::getRadius() const
{
	return radius_;
}


void Circle::setColor (Color const& clr)
{
	color_ = clr;
}

void Circle::setPoint2D (Point2D const& ctr)
{
	center_ = ctr;
}

void Circle::setRadius(float r)
{
	radius_ = r;
}

float Circle::circumference() const
{
	return 2*M_PI*radius_;
}

void Circle::draw(Window& win)
{

	for(float i = 0.0; i<= 2* M_PI; i += 0.001)
	{
		win.draw_point(radius_*cos(i)+center_.x,
						radius_*sin(i)+center_.y,
						  color_.r, color_.g, color_.b);
	}

}