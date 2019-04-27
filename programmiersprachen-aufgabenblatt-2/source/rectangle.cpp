#include "rectangle.hpp"

Rectangle::Rectangle():
	min_{0.0f, 0.0f},
	max_{1.0f, 1.0f}
	{}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max):
	min_{min},
	max_{max}
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
