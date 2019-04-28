#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include<math.h>

#include "color.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include "window.hpp"

class Circle{
	public:
		Circle();
		Circle(Color const& color);
		Circle(float rad);
		Circle(Vec2 const& pos);
		Circle(float rad, Color const& color);
		Circle(Vec2 const& pos, float rad);
		Circle(Vec2 const& pos, Color const& color);
		Circle(Vec2 const& pos, float rad, Color const& color);

		bool is_inside(Vec2 const& vec) const;
		float circumference() const;
		void draw(Window const& window) const;
		void draw(Window const& window, float line) const;

	private:
		Color color;
		float radius;
		Vec2 position;
};

#endif // CIRCLE_HPP