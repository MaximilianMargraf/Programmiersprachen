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

  // create clock circle
  Vec2 center1{400.0f, 400.0f};
  float rad1 = 370.0f;
  Circle circ1{center1, rad1, silver};
  vecCirc.push_back(circ1);

  // time elapsed since GLFW was initialized
  float time = 0.0f;
  float timeSec = 0.0f;
  float timeMin = 0.0f;
  float timeHou = 0.0f;

  // create window
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    // update time elapsed
    time = win.get_time();
    timeSec = time * (2 * M_PI / 60);
    timeMin = time * (2 * M_PI / 3600);
    timeHou = time * (2 * M_PI / 43200);

    // draw clock base and circles
    for(Circle& c : vecCirc){
        c.draw(win, lineThicc);
    }

    for(int i = 1; i <= 12; i++){
        float en1 = center1.x + rad1 * std::cos(i * (2*M_PI/ 12));
        float en2 = center1.x + rad1 * std::sin(i * (2*M_PI/ 12));
        float sta1 = center1.x + 350.0f * std::cos(i * (2*M_PI/ 12));
        float sta2 = center1.x + 350.0f * std::sin(i * (2*M_PI/ 12));
        win.draw_line(sta1, sta2, en1, en2, crimson.r, crimson.g, crimson.b, 2.0f);
    }

    // draw seconds pointer
    float x1 = center1.x + rad1 * std::sin(timeSec);
    float y1 = center1.x + rad1 * -std::cos(timeSec);
    win.draw_line(center1.x, center1.y, x1, y1, crimson.r, crimson.g, crimson.b, 2.0f);

    // draw minutes pointer
    float x2 = center1.x + rad1 * std::sin(timeMin);
    float y2 = center1.x + rad1 * -std::cos(timeMin);
    win.draw_line(center1.x, center1.y, x2, y2, darkOrchid.r, darkOrchid.g, darkOrchid.b, 2.0f);

    // draw minutes pointer
    float x3 = center1.x + rad1 * std::sin(timeHou);
    float y3 = center1.x + rad1 * -std::cos(timeHou);
    win.draw_line(center1.x, center1.y, x3, y3, chartreuse.r, chartreuse.g, chartreuse.b, 2.0f);

    // display time as text for checking
    std::string display_text = "Seconds: " + std::to_string(time);
    
    int text_offset_x = 10;
    int text_offset_y = 10;
    unsigned int font_size = 15;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    // display time as text for checking
    display_text = "Minutes: " + std::to_string(time/60);

    text_offset_y = 30;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);
    
    // display time as text for checking
    display_text = "Hours: " + std::to_string(time/360);

    text_offset_y = 50;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    win.update();
  }

  return 0;
}
