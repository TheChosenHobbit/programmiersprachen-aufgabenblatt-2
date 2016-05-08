#include "circle.hpp"
#include "window.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
//#include "color.hpp"
//#include "point2d.hpp"
#include <cmath>
#include <math.h>

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
	for (int i = 1; i<(360+1); ++i)
	{
        Vec2 start((make_rotation_mat2(2*M_PI*i/360)) * Vec2(getRadius(),0) + convert(getPoint2D()));
        Vec2 end((make_rotation_mat2(2*M_PI*(i+1)/360)) * Vec2(getRadius(),0) + convert(getPoint2D()));
        win.draw_line(start.x, start.y, end.x, end.y, color_.r, color_.g, color_.b);
    }
/*
	for(float i = 0.0; i<= 2* M_PI; i += 0.001)
	{
		win.draw_point(radius_*cos(i)+center_.x,
						radius_*sin(i)+center_.y,
						  color_.r, color_.g, color_.b);
	}
	*/
}

void Circle::draw(Window& win, Color clr)
{
	for (int i = 1; i<(360+1); ++i)
	{
        Vec2 start((make_rotation_mat2(2*M_PI*i/360)) * Vec2(getRadius(),0) + convert(getPoint2D()));
        Vec2 end((make_rotation_mat2(2*M_PI*(i+1)/360)) * Vec2(getRadius(),0) + convert(getPoint2D()));
        win.draw_line(start.x, start.y, end.x, end.y, clr.r, clr.g, clr.b);
    }
/*
	for(float i = 0.0; i<= 2* M_PI; i += 0.001)
	{
		win.draw_point(radius_*cos(i)+center_.x,
						radius_*sin(i)+center_.y,
						  clr.r, clr.g, clr.b);
	}
	*/
}

void Circle::drawClock(Window& win)
{
	for (int i = 1; i<(12+1); ++i)
		{
        Vec2 start((make_rotation_mat2(2*M_PI*i/12)) * Vec2(getRadius(),0) + convert(getPoint2D()));
        Vec2 end((make_rotation_mat2(2*M_PI*(i)/12)) * Vec2(getRadius()-0.05,0) + convert(getPoint2D()));
        win.draw_line(start.x, start.y, end.x, end.y, color_.r, color_.g, color_.b);
        /*win.draw_point(radius_*cos(i)+center_.x,
						radius_*sin(i)+center_.y,
						  color_.r, color_.g, color_.b);*/
    }

    for (int i = 1; i<(60+1); ++i)
	{
        Vec2 start((make_rotation_mat2(2*M_PI*i/60)) * Vec2(getRadius(),0) + convert(getPoint2D()));
        Vec2 end((make_rotation_mat2(2*M_PI*(i)/60)) * Vec2(getRadius()-0.01,0) + convert(getPoint2D()));
        win.draw_line(start.x, start.y, end.x, end.y, color_.r, color_.g, color_.b);
    }


}

bool Circle::is_inside(Point2D point)
{

	if(sqrt( (point.x-center_.x)*(point.x-center_.x) + (point.y-center_.y)*(point.y-center_.y)  ) < radius_ )
	{
		return true;
	}
	else return false;
}

Vec2 Circle::convert(Point2D point)
{
	Vec2 v;
	v.x = point.x;
	v.y = point.y;
	return v;
}