#include "circle.hpp"

Circle::Circle():
	position{0.0f, 0.0f},
	radius{1.0f},
	color{}
	{}

Circle::Circle(Color const& color):
	position{0.0f, 0.0f},
	radius{1.0f},
	color{color}
	{}

Circle::Circle(float rad):
	position{0.0f, 0.0f},
	radius{radius},
	color{}
	{}

Circle::Circle(Vec2 const& pos):
	position{pos},
	radius{1.0f},
	color{}
	{}

Circle::Circle(float rad, Color const& color):
	position{0.0f, 0.0f},
	radius{rad},
	color{color}
	{}

Circle::Circle(Vec2 const& pos, float rad):
	position{pos},
	radius{rad},
	color{}
	{}

Circle::Circle(Vec2 const& pos, Color const& color):
	position{pos},
	radius{1.0f},
	color{color}
	{}


Circle::Circle(Vec2 const& pos, float rad, Color const& color_):
	position{pos},
	radius{rad},
	color{color_}
	{
		if(radius < 0){
			radius = 0;
		}
	}

float Circle::circumference() const{
	return 2 * M_PI * radius;;
}