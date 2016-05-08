#include "window.hpp"
#include "circle.hpp"
#include "mat2.hpp"
#include "vec2.hpp"
#include <utility>
#include <cmath>

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.is_key_pressed(GLFW_KEY_ESCAPE)) {
      win.close();
    }


    //auto t = win.get_time();



    Circle clock1{{0.5,0.5},0.3,{0,0,0}};
    clock1.draw(win);
    clock1.drawClock(win);


    Vec2 sek((make_rotation_mat2(2*M_PI*((win.get_time()-15)*(-1)/60))) *
                         Vec2(clock1.getRadius(),0) + clock1.convert(clock1.getPoint2D()));
    win.draw_line(clock1.getPoint2D().x, clock1.getPoint2D().y, sek.x, sek.y, 1, 0, 0);


    Vec2 min((make_rotation_mat2(2*M_PI*((win.get_time()-3600/4)*(-1)/3600))) *
                         Vec2(clock1.getRadius()-0.05,0) + clock1.convert(clock1.getPoint2D()));
    win.draw_line(clock1.getPoint2D().x, clock1.getPoint2D().y, min.x, min.y, 0, 0, 1);


    Vec2 hour((make_rotation_mat2(2*M_PI*((win.get_time()-(3600*60/4))*(-1)/(3600*60)))) *
                         Vec2(clock1.getRadius()-0.15,0) + clock1.convert(clock1.getPoint2D()));
    win.draw_line(clock1.getPoint2D().x, clock1.getPoint2D().y, hour.x, hour.y, 0, 1, 0);

    win.update();

  }

  return 0;
}
