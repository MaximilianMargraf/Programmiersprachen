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

// define operator * for 2d matrix
Mat2 operator*(Mat2 const& matA, Mat2 const& matB){
	Mat2 matC = matA;
	matC *= matB;
	return matC;
}