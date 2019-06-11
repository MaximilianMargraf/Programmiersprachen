#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <iostream>
#include<math.h>
#include <string>

#include "color.hpp"
#include "vec2.hpp"

class Circle{
	public:
		Circle();
		Circle(Color const& color);
		Circle(float rad);
		Circle(Vec2 const& pos);
		Circle(float rad, Color const& color);
		Circle(float rad, std::string name);
		Circle(Vec2 const& pos, float rad);
		Circle(Vec2 const& pos, Color const& color);
		Circle(Vec2 const& pos, float rad, Color const& color);
		Circle(Vec2 const& pos, float rad, Color const& color, std::string name);

		bool is_inside(Vec2 const& vec) const;
		float circumference() const;
		float get_radius() const;

		friend std::ostream& operator<< (std::ostream& os, Circle const& circle);
		friend bool operator == (Circle const& c1, std::string const& s);
		friend bool operator ==(Circle const& c1, Circle const& c2);
		friend bool operator !=(Circle const& c1, Circle const& c2);
		friend bool operator <(Circle const& c1, Circle const& c2);
		friend bool operator >(Circle const& c1, Circle const& c2);

	private:
		Color color;
		float radius;
		Vec2 position;
		std::string name;
};

void print(Circle const& c);

#endif // CIRCLE_HPP