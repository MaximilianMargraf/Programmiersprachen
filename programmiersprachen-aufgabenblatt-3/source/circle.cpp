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

void Circle::draw(Window const& window) const{
	// make 360 small lines for clock
	for (int i = 1; i <= 360; ++i) {
		Vec2 start ((make_rotation_mat2(2 * M_PI * i / 360)) * Vec2(radius, 0) + position);
		Vec2 end ((make_rotation_mat2(2 * M_PI * (i + 1) / 360)) * Vec2(radius, 0) + position);
		window.draw_line(start.x, start.y, end.x, end.y, color.r, color.g, color.b);
	}
}

void Circle::draw(Window const& window, float line) const{
	// make 360 small lines for clock
	for (int i = 1; i <= 360; ++i) {
		Vec2 start ((make_rotation_mat2(2 * M_PI * i / 360)) * Vec2(radius, 0) + position);
		Vec2 end ((make_rotation_mat2(2 * M_PI * (i + 1) / 360)) * Vec2(radius, 0) + position);
		window.draw_line(start.x, start.y, end.x, end.y, color.r, color.g, color.b, line);
	}
}

bool Circle::is_inside(Vec2 const& vec) const{
	float distance = abs(sqrt(pow(vec.x - position.x,2) + pow(vec.y - position.y,2)));
	if(distance <= radius){
		return true;
	}
	else{
		return false;
	}
}