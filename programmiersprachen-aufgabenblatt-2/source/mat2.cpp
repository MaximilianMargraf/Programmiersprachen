#include <math.h>

#include "mat2.hpp"

	// matrix layout :
	// e_00 e_01
	// e_10 e_11

Mat2::Mat2():
	e_00{1.0f},
	e_01{0.0f},
	e_10{0.0f},
	e_11{1.0f}
	{}

Mat2::Mat2(float x1, float y1,float x2, float y2):
	e_00{x1},
	e_01{y1},
	e_10{x2},
	e_11{y2}
	{}

void Mat2::setMat2(float x1, float y1,float x2, float y2){
	e_00 = x1;
	e_01 = y1;
	e_10 = x2;
	e_11 = y2;
}

// define *= operator for 2d matrix
Mat2& Mat2::operator *= (Mat2 const& mat){
	float m_00 = e_00 * mat.e_00 + e_01 * mat.e_10;
	float m_01 = e_00 * mat.e_01 + e_01 * mat.e_11;
	float m_10 = e_10 * mat.e_00 + e_11 * mat.e_10;
	float m_11 = e_10 * mat.e_01 + e_11 * mat.e_11;
	setMat2(m_00, m_01, m_10, m_11);
}

// calculate determinante
float Mat2::det() const{
	// Sarrus
	return e_00 * e_11 - e_10 * e_01;
}

// define operator * for 2d matrix
Mat2 operator*(Mat2 const& matA, Mat2 const& matB){
	Mat2 matC = matA;
	matC *= matB;
	return matC;
}

// matrix multiplication with vector
Vec2 operator *(Mat2 const& m, Vec2 const& v){
	Vec2 n{m.e_00 * v.x + m.e_01 * v.y, m.e_10 * v.x + m.e_11 * v.y};
	return n;
}

Vec2 operator *(Vec2 const& v, Mat2 const& m){
	Vec2 n = m*v;
	return n;
}

// matrix multiplicator with float
Mat2 operator *(float f, Mat2 const& m){
	Mat2 n{m.e_00 * f, m.e_01 * f, m.e_10 * f, m.e_11 * f};
	return n;
}

// inverse matrix
Mat2 inverse (Mat2 const& m){
	Mat2 tmp{m.e_11, -m.e_01, -m.e_10, m.e_00};
	Mat2 n = (1.0f/m.det())*tmp;
	return n;
}

// transposed
Mat2 transpose (Mat2 const& m){
	Mat2 n{m.e_00, m.e_10, m.e_01, m.e_11};
	return n;
}

// rotation matrix based on phi
Mat2 make_rotation_mat2(float phi)
{
	Mat2 n(cos(phi), (-1)*sin(phi), sin(phi), cos(phi));
	return n;
}