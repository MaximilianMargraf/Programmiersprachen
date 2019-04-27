#include "circle.hpp"

Circle::Circle():
	position{0.0f, 0.0f},
	radius{1.0f}
	{}

Circle::Circle(Vec2 const& pos, float rad):
	position{pos},
	radius{rad}
	{}