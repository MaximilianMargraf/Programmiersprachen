#include "rectangle.hpp"

Rectangle::Rectangle():
	min_{0.0f, 0.0f},
	max_{1.0f, 1.0f},
	color{}
	{}

Rectangle::Rectangle(Vec2 const& min):
	min_{min},
	max_{1.0f, 1.0f},
	color{}
	{}

Rectangle::Rectangle(Color const& color):
	min_{0.0f, 0.0f},
	max_{1.0f, 1.0f},
	color{color}
	{}

Rectangle::Rectangle(Vec2 const& min, Color const& color):
	min_{min},
	max_{1.0f, 1.0f},
	color{}
	{}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max):
	min_{min},
	max_{max},
	color{}
	{}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& color_):
	min_{min},
	max_{max},
	color{color_}
	{
		if(min_.x > max_.x){
			float tmp = min_.x;
			min_.x = max_.x;
			max_.x = tmp;
		}

		if(min_.y > max_.y){
			float tmp = min_.y;
			min_.y = max_.y;
			max_.y = tmp;
		}
	}

float Rectangle::circumference() const{
	float circ = (max_.x - min_.x) * (max_.y - min_.y);
	if(circ < 0){
		circ *= -1;
	}
	return circ;
}


void Rectangle::draw(Window const& window) const{
	window.draw_line(min_.x, min_.y, max_.x, min_.y, color.r, color.g, color.b);
	window.draw_line(min_.x, min_.y, min_.x, max_.y, color.r, color.g, color.b);
	window.draw_line(max_.x, min_.y, max_.x, max_.y, color.r, color.g, color.b);
	window.draw_line(min_.x, max_.y, max_.x, max_.y, color.r, color.g, color.b);
}

void Rectangle::draw(Window const& window, float line) const{
	window.draw_line(min_.x, min_.y, max_.x, min_.y, color.r, color.g, color.b, line);
	window.draw_line(min_.x, min_.y, min_.x, max_.y, color.r, color.g, color.b, line);
	window.draw_line(max_.x, min_.y, max_.x, max_.y, color.r, color.g, color.b, line);
	window.draw_line(min_.x, max_.y, max_.x, max_.y, color.r, color.g, color.b, line);
}

bool Rectangle::is_inside(Vec2 const& vec) const{
	if(vec.x <= max_.x && vec.x >= min_.x && vec.y <= max_.y && vec.y >= min_.y){
		return true;
	}
	else{
		return false;
	}
}