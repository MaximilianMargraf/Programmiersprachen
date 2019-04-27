#include "vec2.hpp"

// def constructor
Vec2::Vec2():
	x{0.0f},
	y{0.0f}
	{}

// val constructor
Vec2::Vec2(float x_, float y_):
	x{x_},
	y{y_}
	{}

// vec constructor
Vec2::Vec2(Vec2 const& vec):
	x{vec.x},
	y{vec.y}
	{}

void Vec2::setX(float x_){
	x = x_;
}

void Vec2::setY(float y_){
	y = y_;
}

float Vec2::getX(){
	return x;
}

float Vec2::getY(){
	return y;
}

// define += operator for 2d vector
Vec2& Vec2::operator += (Vec2 const& vec){
	x += vec.x;
	y += vec.y;
}

// define -= operator for 2d vector
Vec2& Vec2::operator -= (Vec2 const& vec){
	x -= vec.x;
	y -= vec.y;
}

// define *= operator for 2d vector
Vec2& Vec2::operator *= (float m){
	x *= m;
	y *= m;
}

// define /= operator for 2d vector
Vec2& Vec2::operator /= (float d){
	if(d == 0)
	{
		x = 0.0f;
		y = 0.0f;
	}
	else{
		x /= d;
		y /= d;
	}
}


// define free operator functions, with new vector as return
Vec2 operator+(Vec2 const& u, Vec2 const& v){
	Vec2 w = u;
	w += v;
	return w;
}

Vec2 operator-(Vec2 const& u, Vec2 const& v){
	Vec2 w = u;
	w -= v;
	return w;
}

Vec2 operator*(Vec2 const& v, float f){
	Vec2 w = v;
	w *= f;
	return w;
}

Vec2 operator/(Vec2 const& v, float f){
	Vec2 w = v;
	w /= f;
	return w;
}

Vec2 operator*(float f, Vec2 const& v){
	Vec2 w = v;
	w *= f;
	return w;
}