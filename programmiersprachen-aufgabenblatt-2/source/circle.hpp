#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"

class Circle{
	public:
		Circle();
		Circle(Vec2 const& pos, float rad);

	private:
		Vec2 position;
		float radius;
};

#endif // CIRCLE_HPP