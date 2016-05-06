#include "circle.hpp"
#include "color.hpp"


Circle::Cirlce(float r, Color const& clr):
radius_{r},
color_{clr}{}

Color Circle::getColor() const
{
	return color_;
}

float Circle::getRadius() const
{
	return radius_;
}

void Circle::setColor (float red, float green, float blue)
{
	Color.r = red;
	Color.g = green;
	Color.b = blue;
}

void Circle::setRadius(float r)
{
	radius_ = r;
}