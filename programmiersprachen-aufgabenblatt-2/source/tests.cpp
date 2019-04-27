#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include<math.h>

#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

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

// test 2d matrix vector multiplikation
TEST_CASE ("describe_free_op_mat_vec_Mat2", "[Mat2]"){
	// val
	Vec2 vecA{3.0f, 4.0f};
	Mat2 matA{2.0f, 3.0f, 4.0f, 5.0f};

	Vec2 vecB = vecA * matA;
	Vec2 vecC = matA * vecA;

	REQUIRE(Approx(18.0f)==vecC.x);
	REQUIRE(Approx(32.0f)==vecC.y);
	REQUIRE(Approx(18.0f)==vecB.x);
	REQUIRE(Approx(32.0f)==vecB.y);
}

// test 2d matrix determinante
TEST_CASE ("describe_det_Mat2", "[Mat2]"){
	Mat2 matA;
	// val
	Mat2 matB{2.0f, 3.0f, 4.0f, 5.0f};
	Mat2 matC{-4.0f, 20.0f, 111.0f, 13.0f};

	REQUIRE(Approx(1.0f)==matA.det());
	REQUIRE(Approx(-2.0f)==matB.det());
	REQUIRE(Approx(-2272.0f)==matC.det());
}

// test 2d matrix inverse
TEST_CASE ("describe_free_inv_Mat2", "[Mat2]"){
	Mat2 matA;
	// val
	Mat2 matB{4.0f, 7.0f, 2.0f, 6.0f};

	Mat2 matD = inverse(matA);
	Mat2 matE = inverse(matB);

	REQUIRE(Approx(1.0f)==matD.e_00);
	REQUIRE(Approx(0.0f)==matD.e_01);
	REQUIRE(Approx(0.0f)==matD.e_10);
	REQUIRE(Approx(1.0f)==matD.e_11);
	REQUIRE(Approx(0.6f)==matE.e_00);
	REQUIRE(Approx(-0.7f)==matE.e_01);
	REQUIRE(Approx(-0.2f)==matE.e_10);
	REQUIRE(Approx(0.4f)==matE.e_11);
}

// test 2d matrix transposed
TEST_CASE ("describe_free_trans_Mat2", "[Mat2]"){
	Mat2 matA;
	// val
	Mat2 matB{4.0f, 7.0f, 2.0f, 6.0f};

	Mat2 matD = transpose(matA);
	Mat2 matE = transpose(matB);

	REQUIRE(Approx(1.0f)==matD.e_00);
	REQUIRE(Approx(0.0f)==matD.e_01);
	REQUIRE(Approx(0.0f)==matD.e_10);
	REQUIRE(Approx(1.0f)==matD.e_11);
	REQUIRE(Approx(4.0f)==matE.e_00);
	REQUIRE(Approx(2.0f)==matE.e_01);
	REQUIRE(Approx(7.0f)==matE.e_10);
	REQUIRE(Approx(6.0f)==matE.e_11);
}

// test 2d rotation matrix
TEST_CASE ("describe_free_rot_Mat2", "[Mat2]"){
	Mat2 matA = make_rotation_mat2(20.0f);
	Mat2 matB = make_rotation_mat2(90.0f);

	REQUIRE(Approx(0.40808f)==matA.e_00);
	REQUIRE(Approx(-0.91295f)==matA.e_01);
	REQUIRE(Approx(0.91295f)==matA.e_10);
	REQUIRE(Approx(0.40808f)==matA.e_11);
	REQUIRE(Approx(-0.44807f)==matB.e_00);
	REQUIRE(Approx(-0.894f)==matB.e_01);
	REQUIRE(Approx(0.894f)==matB.e_10);
	REQUIRE(Approx(-0.44807f)==matB.e_11);
}

// test color
TEST_CASE ("describe_Color", "[Color]"){
	Color grey;

	REQUIRE(Approx(115.0f/255.0f)==grey.r);
	REQUIRE(Approx(115.0f/255.0f)==grey.g);
	REQUIRE(Approx(115.0f/255.0f)==grey.b);
}

// test circle
TEST_CASE ("describe_Circle", "[Circle]"){
	Color grey;

	Circle c1;
	float cir1 = c1.circumference();

	Vec2 tmp{4.5f, 10.1f};
	Circle c2{tmp, 4.0f, grey};
	float cir2 =c2.circumference();

	REQUIRE(Approx(6.28319f)==cir1);
	REQUIRE(Approx(25.13274f)==cir2);
}

// test rectangle
TEST_CASE ("describe_Rectangle", "[Rectangle]"){
	Rectangle r1;
	float c1 = r1.circumference();

	Vec2 tmp1{4.5f, 5.1f};
	Vec2 tmp2{7.9f, 9.8f};
	Rectangle r2{tmp1, tmp2};
	float c2 = r2.circumference();

	Vec2 tmp3{8.7f, 10.1f};
	Vec2 tmp4{7.9f, 9.8f};
	Rectangle r3{tmp3, tmp4};

	float c3 = r3.circumference();

	REQUIRE(Approx(1.0f)==c1);
	REQUIRE(Approx(15.98f)==c2);
	REQUIRE(Approx(0.24f)==c3);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
