#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "vec2.hpp"

class Rectangle{
	public:
		Rectangle();
		Rectangle(Vec2 const& min_, Vec2 const& max_);
		float circumference() const;

	private:
		Vec2 min_;
		Vec2 max_;
};

#endif // RECTANGLE_HPP