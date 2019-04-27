#include "circle.hpp"

Circle::Circle():
	position{0.0f, 0.0f},
	radius{1.0f}
	{}

Circle::Circle(Vec2 const& pos, float rad):
	position{pos},
	radius{rad}
	{
		if(radius < 0){
			radius = 0;
		}
	}

float Circle::circumference() const{
	return 2 * M_PI * radius;;
}