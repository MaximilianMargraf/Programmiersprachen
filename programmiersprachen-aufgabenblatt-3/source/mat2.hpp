#ifndef MAT2_HPP
#define MAT2_HPP

#include "vec2.hpp"

// define a 2d vector
struct Mat2{
	// matrix layout :
	// e_00 e_01
	// e_10 e_11

	// def constructor
	Mat2();

	// val constructor
	Mat2(float x1, float y1,float x2, float y2);

	// variables
	float e_00;
	float e_01;
	float e_10;
	float e_11;

	// functions
	float det() const;
	void setMat2(float x1, float y1,float x2, float y2);

	// *= operator for 2d matrix
	Mat2& operator *=(Mat2 const& m);
};

// no member functions, instead free functions
Mat2 operator *(Mat2 const& m1, Mat2 const& m2);
Mat2 operator *(float f, Mat2 const& m2);
Vec2 operator *(Mat2 const& m, Vec2 const& v);
Vec2 operator *(Vec2 const& v, Mat2 const& m);
Mat2 inverse (Mat2 const& m);
Mat2 transpose (Mat2 const& m);
Mat2 make_rotation_mat2 (float phi);

#endif //MAT2_HPP