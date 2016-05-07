#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "circle.hpp"
#include "window.hpp"

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

	float circumference() const;
	//Methode sind Member Funktionen von einer Classe
	//Funktionen sind stand-alone 

	void draw(Window& win);

private:
	Point2D left_;
	Point2D right_;
	Color color_;
};


#endif