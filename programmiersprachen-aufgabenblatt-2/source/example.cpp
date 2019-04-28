#include <cmath>
#include <GLFW/glfw3.h>
#include <utility>
#include <vector>

#include "circle.hpp"
#include "color.hpp"
#include "rectangle.hpp"
#include "vec2.hpp"
#include "window.hpp"

int main(int argc, char* argv[])
{
  // line thickness
  float lineThicc = 7.0f;

  // create vector to store shapes
  std::vector<Circle> vecCirc;
  std::vector<Rectangle> vecRec;

  // create colors
  Color crimson{220.0f/255.0f, 20.0f/255.0f, 60.0f/255.0f};
  Color silver{192.0f/255.0f, 192.0f/255.0f, 192.0f/255.0f};
  Color darkOrchid{104.0f/255.0f, 34.0f/255.0f, 139.0f/255.0f};
  Color chartreuse{127.0f/255.0f,255.0f/255.0f,0.0f/255.0f};

  // create circle
  Vec2 center1{500.0f, 400.0f};
  float rad1 = 100.0f;
  Circle circ1{center1, rad1, silver};
  vecCirc.push_back(circ1);

  Vec2 center2{700.0f, 300.0f};
  float rad2 = 50.0f;
  Circle circ2{center2, rad2, darkOrchid};
  vecCirc.push_back(circ2);

  // create rectangle
  Vec2 min_1{150.0f,432.0f};
  Vec2 max_1{272.0f, 241.0f};
  Rectangle rect1{min_1, max_1, crimson};
  vecRec.push_back(rect1);

  Vec2 min_2{500.0f,550.0f};
  Vec2 max_2{600.0f, 650.0f};
  Rectangle rect2{min_2, max_2, chartreuse};
  vecRec.push_back(rect2);

  // mouse position for is_inside
  Vec2 mP;

  // create window
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    // get mouse position
    auto mouse_position = win.mouse_position();
    mP.x = (float)std::get<0>(mouse_position);
    mP.y = (float)std::get<1>(mouse_position);

    // draw rectangles and circles
    for(Circle& c : vecCirc){
        if(c.is_inside(mP)){
            c.draw(win, lineThicc * 2);
        }
        else{
            c.draw(win, lineThicc);
        }
    }

    for(Rectangle& r : vecRec){
        if(r.is_inside(mP)){
            r.draw(win, lineThicc * 2);
        }
        else{
            r.draw(win, lineThicc);
        }
    }

    /*bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    //auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);
    */


    /*std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);
    */

    win.update();
  }

  return 0;
}
