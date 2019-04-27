#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include<math.h>

#include "vec2.hpp"
#include "mat2.hpp"

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

// test 2d vector addition
TEST_CASE ("describe_free_op_add_Vec2", "[Vec2]"){
	// def
	Vec2 vecA;
	// val
	Vec2 vecB{6.0f,12.0f};
	// val 2
	Vec2 vecC{3.0f,3.0f};

	vecA = vecB+vecC;

	REQUIRE(Approx(9.0f)==vecA.x);
	REQUIRE(Approx(15.0f)==vecA.y);
}

// test 2d vector subtraction
TEST_CASE ("describe_free_op_sub_Vec2", "[Vec2]"){
	// def
	Vec2 vecA;
	// val
	Vec2 vecB{6.0f,12.0f};
	Vec2 vecC{3.0f,3.0f};

	vecA = vecB-vecC;

	REQUIRE(Approx(3.0f)==vecA.x);
	REQUIRE(Approx(9.0f)==vecA.y);
}

// test 2d vector multiplication
TEST_CASE ("describe_free_op_mul_Vec2", "[Vec2]"){
	// def
	Vec2 vecA;
	Vec2 vecB;
	Vec2 vecC;
	// val
	Vec2 vecD{6.0f,12.0f};

	float f = 2.0f;
	float o= 0.0f;

	vecA = vecD*f;
	vecB = f*vecD;
	vecC = vecD*o;

	REQUIRE(Approx(12.0f)==vecA.x);
	REQUIRE(Approx(24.0f)==vecA.y);
	REQUIRE(Approx(12.0f)==vecB.x);
	REQUIRE(Approx(24.0f)==vecB.y);
	REQUIRE(Approx(0.0f)==vecC.x);
	REQUIRE(Approx(0.0f)==vecC.y);
}

// test 2d vector division
TEST_CASE ("describe_free_op_div_Vec2", "[Vec2]"){
	// def
	Vec2 vecA;
	Vec2 vecB;
	// val
	Vec2 vecC{6.0f,12.0f};

	float f = 2.0f;
	float o= 0.0f;

	vecA = vecC/f;
	vecB = vecC/o;

	REQUIRE(Approx(3.0f)==vecA.x);
	REQUIRE(Approx(6.0f)==vecA.y);
	REQUIRE(Approx(0.0f)==vecB.x);
	REQUIRE(Approx(0.0f)==vecB.y);
}

// test 2d matrix constructors
TEST_CASE ("describe_Ḿat2", "[Mat2]"){
	// def
	Mat2 matA;
	// val
	Mat2 matB{2.0f, 3.0f, 4.0f, 5.0f};

	REQUIRE(Approx(1.0f)==matA.e_00);
	REQUIRE(Approx(0.0f)==matA.e_01);
	REQUIRE(Approx(0.0f)==matA.e_10);
	REQUIRE(Approx(1.0f)==matA.e_11);
	REQUIRE(Approx(2.0f)==matB.e_00);
	REQUIRE(Approx(3.0f)==matB.e_01);
	REQUIRE(Approx(4.0f)==matB.e_10);
	REQUIRE(Approx(5.0f)==matB.e_11);
}

// test 2d matrix multiplikation
TEST_CASE ("describe_multiplikation_Ḿat2", "[Mat2]"){
	// def
	Mat2 matA;
	// val
	Mat2 matB{2.0f, 3.0f, 4.0f, 5.0f};
	Mat2 matC{0.0f, 0.0f, 0.0f, 0.0f};

	matA *= matB;
	matC *= matB;
	Mat2 matD = matB * matB;

	REQUIRE(Approx(2.0f)==matA.e_00);
	REQUIRE(Approx(3.0f)==matA.e_01);
	REQUIRE(Approx(4.0f)==matA.e_10);
	REQUIRE(Approx(5.0f)==matA.e_11);
	REQUIRE(Approx(0.0f)==matC.e_00);
	REQUIRE(Approx(0.0f)==matC.e_01);
	REQUIRE(Approx(0.0f)==matC.e_10);
	REQUIRE(Approx(0.0f)==matC.e_11);
	REQUIRE(Approx(16.0f)==matD.e_00);
	REQUIRE(Approx(21.0f)==matD.e_01);
	REQUIRE(Approx(28.0f)==matD.e_10);
	REQUIRE(Approx(37.0f)==matD.e_11);
}

// test 2d matrix multiplikation
TEST_CASE ("describe_free_op_mul_Ḿat2", "[Mat2]"){
	// def
	Mat2 matA;
	// val
	Mat2 matB{2.0f, 3.0f, 4.0f, 5.0f};
	Mat2 matC{0.0f, 0.0f, 0.0f, 0.0f};

	Mat2 matD = matA * matB;
	Mat2 matE = matC * matB;
	Mat2 matF = matB * matB;

	REQUIRE(Approx(2.0f)==matD.e_00);
	REQUIRE(Approx(3.0f)==matD.e_01);
	REQUIRE(Approx(4.0f)==matD.e_10);
	REQUIRE(Approx(5.0f)==matD.e_11);
	REQUIRE(Approx(0.0f)==matE.e_00);
	REQUIRE(Approx(0.0f)==matE.e_01);
	REQUIRE(Approx(0.0f)==matE.e_10);
	REQUIRE(Approx(0.0f)==matE.e_11);
	REQUIRE(Approx(16.0f)==matF.e_00);
	REQUIRE(Approx(21.0f)==matF.e_01);
	REQUIRE(Approx(28.0f)==matF.e_10);
	REQUIRE(Approx(37.0f)==matF.e_11);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
