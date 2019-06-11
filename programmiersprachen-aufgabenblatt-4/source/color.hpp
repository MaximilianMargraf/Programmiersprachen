#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>

struct Color{
	// default color, greyish
	float r = 115.0f/255.0f;
	float g = 115.0f/255.0f;
	float b = 115.0f/255.0f;
	std::string name = "";
};

#endif // COLOR_HPP