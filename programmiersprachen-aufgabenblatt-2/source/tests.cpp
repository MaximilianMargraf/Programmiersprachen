#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include<math.h>

#include "vec2.hpp"

// test 2d vector
TEST_CASE ("describe_Vec2", "[Vec2]"){
	// def
	Vec2 vecA;
	// val
	Vec2 vecB{3.0, 3.0};

	REQUIRE(Approx(0.0f)==vecA.x);
	REQUIRE(Approx(0.0f)==vecA.y);
	REQUIRE(Approx(3.0f)==vecB.x);
	REQUIRE(Approx(3.0f)==vecB.y);
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
