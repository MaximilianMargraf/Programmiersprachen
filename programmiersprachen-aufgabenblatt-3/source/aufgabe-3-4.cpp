#include <iostream>
#include <set>
#include <string>

#include "circle.hpp"
#include "color.hpp"
#include "vec2.hpp"

int main(int argc, char* argv[])
{
  // create vector to store shapes
  std::multiset<Circle> setCirc;

  // create colors
  Color crimson{220.0f/255.0f, 20.0f/255.0f, 60.0f/255.0f};
  Color silver{192.0f/255.0f, 192.0f/255.0f, 192.0f/255.0f, "Silver"};
  Color darkOrchid{104.0f/255.0f, 34.0f/255.0f, 139.0f/255.0f, "Dark Orchid"};
  Color chartreuse{127.0f/255.0f,255.0f/255.0f,0.0f/255.0f, "Chartreuse"};

  // create circle
  Vec2 center1{500.0f, 400.0f};
  float rad1 = 100.0f;
  Circle circ1{center1, rad1, silver, "circleOne"};
  setCirc.insert(circ1);

  Vec2 center2{700.0f, 300.0f};
  float rad2 = 50.0f;
  Circle circ2{center2, rad2, darkOrchid, "circleTwo"};
  setCirc.insert(circ2);

  Vec2 center3{100.0f, 160.0f};
  float rad3 = 80.0f;
  Circle circ3{center3, rad3, chartreuse, "circleThree"};
  setCirc.insert(circ3);

  Vec2 center4{100.0f, 660.0f};
  float rad4 = 80.0f;
  Circle circ4{center4, rad4, crimson, "circleFour"};
  setCirc.insert(circ4);

  Vec2 center5{300.0f, 700.0f};
  float rad5 = 80.0f;
  Circle circ5{center5, rad5, silver, "circleFour"};
  setCirc.insert(circ5);

  std::cout <<"The names of the circles are: circleOne, circleTwo, circleThree, circleFour and circleFour"<<"\n";
  std::string search_name= "";
  std::cin >> search_name;

  for(Circle c : setCirc){
    if(c == (search_name)){
      std::cout<<"\n";
      print(c);
    }
  }

  return 0;
}