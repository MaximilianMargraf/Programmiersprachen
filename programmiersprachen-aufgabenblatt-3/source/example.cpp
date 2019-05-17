#include <cmath>
#include <GLFW/glfw3.h>
#include <iostream>
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
  //Color crimson{220.0f/255.0f, 20.0f/255.0f, 60.0f/255.0f};
  Color silver{192.0f/255.0f, 192.0f/255.0f, 192.0f/255.0f, silver};
  Color darkOrchid{104.0f/255.0f, 34.0f/255.0f, 139.0f/255.0f, darkOrchid};
  Color chartreuse{127.0f/255.0f,255.0f/255.0f,0.0f/255.0f, chartreuse};

  // create circle
  Vec2 center1{500.0f, 400.0f};
  float rad1 = 100.0f;
  Circle circ1{center1, rad1, silver, "circleOne"};
  vecCirc.push_back(circ1);

  Vec2 center2{700.0f, 300.0f};
  float rad2 = 50.0f;
  Circle circ2{center2, rad2, darkOrchid, "circleTwo"};
  vecCirc.push_back(circ2);

  Vec2 center3{100.0f, 160.0f};
  float rad3 = 80.0f;
  Circle circ3{center3, rad3, chartreuse, "circleThree"};
  vecCirc.push_back(circ3);

  std::cout <<circ1<<"\n";

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
            c.draw(win, lineThicc * 1.5);
        }
        else{
            c.draw(win, lineThicc);
        }
    }

        // display time as text for checking
    std::string display_text = "Circle Names: circleOne, circleTwo, circleThree";
    
    int text_offset_x = 10;
    int text_offset_y = 10;
    unsigned int font_size = 15;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);


    win.update();
  }

  return 0;
}
