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

// define operators for 2d vectors
Vec2& Vec2::operator += (Vec2 const& vec){
	x += vec.x;
	y += vec.y;
}

Vec2& Vec2::operator -= (Vec2 const& vec){
	x -= vec.x;
	y -= vec.y;
}

Vec2& Vec2::operator *= (float m){
	x *= m;
	y *= m;
}

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
	Vec2 w {u.x + v.x, u.y + v.y};
	return w;
}

Vec2 operator-(Vec2 const& u, Vec2 const& v){
	Vec2 w {u.x - v.x, u.y - v.y};
	return w;
}

Vec2 operator*(Vec2 const& v, float f){
	Vec2 w {v.x * f, v.y * f};
	return w;
}

Vec2 operator/(Vec2 const& v, float f){
	float x_;
	float y_;

	// catch division by 0
	if(f != 0){
		x_ = v.x/f;
		y_ = v.y/f;
	}
	else{
		x_ = 0.0f;
		y_ = 0.0f;
	}
	Vec2 w {x_,y_};
	return w;
}

Vec2 operator*(float f, Vec2 const& v){
	Vec2 w {v.x * f, v.y * f};
	return w;
}