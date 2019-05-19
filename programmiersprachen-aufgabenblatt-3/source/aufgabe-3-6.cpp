#define CATCH_CONFIG_RUNNER
#include <algorithm>
#include <catch.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "circle.hpp"
#include "color.hpp"
#include "vec2.hpp"

// test 2d vector
TEST_CASE ("describe_CircleSort", "[Circle]"){
    // create vector to store shapes
  std::vector<Circle> sorted_circles;

  // create colors
  Color crimson{220.0f/255.0f, 20.0f/255.0f, 60.0f/255.0f};
  Color silver{192.0f/255.0f, 192.0f/255.0f, 192.0f/255.0f, "Silver"};
  Color darkOrchid{104.0f/255.0f, 34.0f/255.0f, 139.0f/255.0f, "Dark Orchid"};
  Color chartreuse{127.0f/255.0f,255.0f/255.0f,0.0f/255.0f, "Chartreuse"};

  // create circle
  Vec2 center1{500.0f, 400.0f};
  float rad1 = 100.0f;
  Circle circ1{center1, rad1, silver, "circleOne"};
  sorted_circles.push_back(circ1);

  Vec2 center2{700.0f, 300.0f};
  float rad2 = 50.0f;
  Circle circ2{center2, rad2, darkOrchid, "circleTwo"};
  sorted_circles.push_back(circ2);

  Vec2 center3{100.0f, 160.0f};
  float rad3 = 80.0f;
  Circle circ3{center3, rad3, chartreuse, "circleThree"};
  sorted_circles.push_back(circ3);

  Vec2 center4{100.0f, 660.0f};
  float rad4 = 90.0f;
  Circle circ4{center4, rad4, crimson, "circleFour"};
  sorted_circles.push_back(circ4);

  Vec2 center5{300.0f, 700.0f};
  float rad5 = 99.0f;
  Circle circ5{center5, rad5, silver, "circleFour"};
  sorted_circles.push_back(circ5);

  std::sort(sorted_circles.begin(), sorted_circles.end());

  for(Circle c : sorted_circles){
    print(c);
  }

  REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}