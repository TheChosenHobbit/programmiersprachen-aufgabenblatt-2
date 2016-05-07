#include "window.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include <utility>
#include <cmath>
#include <vector>

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.is_key_pressed(GLFW_KEY_ESCAPE)) {
      win.close();
    }

    std::vector<Circle> circles = {};
    std::vector<Rectangle> rectangles {};

    circles.push_back({{0.4,0.4},0.3,{0,1,1}});
    circles.push_back({{0.5,0.5},0.1,{0,1,0}});

    rectangles.push_back({{0.25,0.75},{0.75,0.25},{1,0,0}});
    rectangles.push_back({{0.1,0.8},{0.7,0.2},{1,0,1}});

    auto t = win.get_time();
    float x1{0.5f + 0.5f * std::sin(t)};
    float y1{0.5f + 0.5f * std::cos(t)};

    float x2{0.5f + 0.5f * std::sin(2.0f*t)};
    float y2{0.5f + 0.5f * std::cos(2.0f*t)};

    float x3{0.5f + 0.5f * std::sin(t-10.f)};
    float y3{0.5f + 0.5f * std::cos(t-10.f)};

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto m = win.mouse_position();
    win.draw_line(0.1f, 0.1f, 0.8f,0.1f, 1.0,0.0,0.0);

    win.draw_line(0.0f, m.second, 0.01f, m.second, 0.0, 0.0, 0.0);
    win.draw_line(0.99f, m.second,1.0f, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0.0f, m.first, 0.01f, 0.0, 0.0, 0.0);
    win.draw_line(m.first, 0.99f,m.first, 1.0f, 0.0, 0.0, 0.0);

    //Rectangle r{{0.25,0.75},{0.75,0.25},{1,0,0}};
    //r.draw(win);

    Color blue{0,0,1};
    Point2D maus{m.first, m.second};

    for(Rectangle n : rectangles) {
        n.draw(win);
        if (n.is_inside(maus))
        {
            n.draw(win,blue);
        }
    }
    /*
    if (r.is_inside(maus) == true)
    {
        r.draw(win, blue);
    }*/

    //Rectangle r1{{0.75,0.25},{0.25,0.75},{1,0,1}};
    //r1.draw(win);

    //fun
    //Rectangle r{{x1,y1},{x2,y2},{0,0,1}};
    //r.draw(win);

    for(Circle n : circles) {
        n.draw(win);
        if (n.is_inside(maus))
        {
            n.draw(win,blue);
        }
    }
/*
    Circle c{{0.5,0.5},0.1,{0,1,0}};
    c.draw(win);

    if (c.is_inside(maus) == true)
    {
        c.draw(win, blue);
    }
*/
    win.update();

  }

  return 0;
}
