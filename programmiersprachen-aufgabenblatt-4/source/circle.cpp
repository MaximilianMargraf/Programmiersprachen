#include "circle.hpp"

Circle::Circle():
	position{0.0f, 0.0f},
	radius{1.0f},
	color{},
	name{""}
	{}

Circle::Circle(Color const& color):
	position{0.0f, 0.0f},
	radius{1.0f},
	color{color},
	name{""}
	{}

Circle::Circle(float rad):
	position{0.0f, 0.0f},
	radius{rad},
	color{},
	name{""}
	{}

Circle::Circle(Vec2 const& pos):
	position{pos},
	radius{1.0f},
	color{},
	name{""}
	{}

Circle::Circle(float rad, Color const& color):
	position{0.0f, 0.0f},
	radius{rad},
	color{color},
	name{""}
	{}

Circle::Circle(float rad, std::string name_):
	position{0.0f, 0.0f},
	radius{rad},
	color{},
	name{name_}
	{}

Circle::Circle(Vec2 const& pos, float rad):
	position{pos},
	radius{rad},
	color{},
	name{""}
	{}

Circle::Circle(Vec2 const& pos, Color const& color):
	position{pos},
	radius{1.0f},
	color{color},
	name{""}
	{}


Circle::Circle(Vec2 const& pos, float rad, Color const& color_):
	position{pos},
	radius{rad},
	color{color_},
	name{""}
	{
		if(radius < 0){
			radius = 0;
		}
	}

Circle::Circle(Vec2 const& pos, float rad, Color const& color_, std::string name_):
	position{pos},
	radius{rad},
	color{color_},
	name{name_}
	{
		if(radius < 0){
			radius = 0;
		}
	}

float Circle::circumference() const{
	return 2 * M_PI * radius;
}

float Circle::get_radius() const{
	return radius;
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

void print(Circle const& c){
	std::cout<<c;
}

bool operator== (Circle const& c1, std::string const& s){
	if(c1.name.compare(s)){
		return false;
	}
	else{
		return true;
	}
}

bool operator== (Circle const& c1, Circle const& c2){
	if(c1.radius == c2.radius){
		return true;
	}
	else{
		return false;
	}
}

bool operator!= (Circle const& c1, Circle const& c2){
	if(c1.radius != c2.radius){
		return true;
	}
	else{
		return false;
	}
}

bool operator< (Circle const& c1, Circle const& c2){
	if(c1.radius < c2.radius){
		return true;
	}
	else{
		return false;
	}
}

bool operator> (Circle const& c1, Circle const& c2){
	if(c1.radius > c2.radius){
		return true;
	}
	else{
		return false;
	}
}

std::ostream& operator<< (std::ostream& os, Circle const& c){
	os <<	"Name: "<<c.name<<
			"\nCoordinates: X "<<c.position.x<<", Y "<<c.position.y<<
			"\nRadius: "<<c.radius<<
			"\nColor: Name "<<c.color.name <<", R "<<c.color.r<<", G "<<c.color.g<<", B "<<c.color.b<<"\n";
	return os;
}