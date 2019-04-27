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

void Vec2::setY(float Y_){
	y = y_;
}

float Vec2::getX(){
	return x;
}

float Vec2::getY(){
	return y;


#endif // VEC2_HPP