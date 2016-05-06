#ifndef CIRCLE.HPP
#define CIRCLE_HPP
#include "color.hpp"

class Circle
{
public:
	Circle(float r, Color const& clr);

	Color getColor() const;
	float getRadius() const;

	void setColor (float red, float green, float blue);
	void setRadius (float r);


private:
	Color color_;
//	point2D center_;
	float radius_;

};

#endif