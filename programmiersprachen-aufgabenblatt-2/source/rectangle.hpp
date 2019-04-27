#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "color.hpp"
#include "vec2.hpp"


class Rectangle{
	public:
		Rectangle();
		Rectangle(Vec2 const& min_);
		Rectangle(Color const& color);
		Rectangle(Vec2 const& min_, Color const& color);
		Rectangle(Vec2 const& min_, Vec2 const& max_);
		Rectangle(Vec2 const& min_, Vec2 const& max_, Color const& color);
		float circumference() const;

	private:
		Color color;
		Vec2 min_;
		Vec2 max_;
};

#endif // RECTANGLE_HPP