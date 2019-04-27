#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include<math.h>

#include "vec2.hpp"

// test 2d vector
TEST_CASE ("describe_Vec2", "[Vec2]"){
	// def
	Vec2 vecA;
	// val
	Vec2 vecB{3.0f, 3.0f};

	REQUIRE(Approx(0.0f)==vecA.x);
	REQUIRE(Approx(0.0f)==vecA.y);
	REQUIRE(Approx(3.0f)==vecB.x);
	REQUIRE(Approx(3.0f)==vecB.y);
}

// test 2d vector addition
TEST_CASE ("describe_addition_Vec2", "[Vec2]"){
	// def
	Vec2 vecA;
	// val
	Vec2 vecB{3.0f, 3.0f};
	// val 2
	Vec2 vecC{5.5f,4.5f};

	vecA += vecB;
	vecB += vecC;

	REQUIRE(Approx(3.0f)==vecA.x);
	REQUIRE(Approx(3.0f)==vecA.y);
	REQUIRE(Approx(8.5f)==vecB.x);
	REQUIRE(Approx(7.5f)==vecB.y);
}

// test 2d vector subtraction
TEST_CASE ("describe_subtraction_Vec2", "[Vec2]"){
	// def
	Vec2 vecA;
	// val
	Vec2 vecB{3.0f, 3.0f};
	// val 2
	Vec2 vecC{5.5f,4.5f};

	vecC -= vecB;
	vecA -= vecB;

	REQUIRE(Approx(2.5f)==vecC.x);
	REQUIRE(Approx(1.5f)==vecC.y);
	REQUIRE(Approx(-3.0f)==vecA.x);
	REQUIRE(Approx(-3.0f)==vecA.y);
}

// test 2d vector multiplication
TEST_CASE ("describe_multiplication_Vec2", "[Vec2]"){
	// def
	Vec2 vecA;
	// val
	Vec2 vecB{5.5f,4.5f};

	float f = 3;

	vecB *= f;
	vecA *= f;

	REQUIRE(Approx(0.0f)==vecA.x);
	REQUIRE(Approx(0.0f)==vecA.y);
	REQUIRE(Approx(16.5f)==vecB.x);
	REQUIRE(Approx(13.5f)==vecB.y);
}

// test 2d vector division
TEST_CASE ("describe_division_Vec2", "[Vec2]"){
	// def
	Vec2 vecA;
	// val
	Vec2 vecB{6.0f,12.0f};
	// val 2
	Vec2 vecC{3.0f,3.0f};

	float d = 2;
	float e = 0;

	vecB /= d;
	vecA /= d;
	vecC /= e;

	REQUIRE(Approx(0.0f)==vecA.x);
	REQUIRE(Approx(0.0f)==vecA.y);
	REQUIRE(Approx(3.0f)==vecB.x);
	REQUIRE(Approx(6.0f)==vecB.y);
	REQUIRE(Approx(0.0f)==vecC.x);
	REQUIRE(Approx(0.0f)==vecC.y);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
