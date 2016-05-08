#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "window.hpp"
#include "vec2.hpp"
//#include "color.hpp"
//#include "point2d.hpp"


struct Point2D
{
	float x, y;
};

struct Color
{
	float r, g, b;
};


class Circle
{
public:
	Circle();
	Circle(Point2D const& ctr, float r, Color const& clr);

	Color getColor() const;
	Point2D getPoint2D() const;
	float getRadius() const;

	void setColor (Color const& clr);
	void setPoint2D (Point2D const& ctr);
	void setRadius (float r);

	float circumference() const;

	void draw(Window& win);
	void draw(Window& win, Color clr);
	void drawClock(Window& win);

	bool is_inside(Point2D point);

	Vec2 convert(Point2D point);

private:
	Point2D center_;
	float radius_;
	Color color_;
};



#endif