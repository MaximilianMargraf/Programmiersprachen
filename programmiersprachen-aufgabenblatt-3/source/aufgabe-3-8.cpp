#define CATCH_CONFIG_RUNNER
#include <algorithm>
#include <catch.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "circle.hpp"
#include "color.hpp"
#include "vec2.hpp"

void fill_vector(std::vector<Circle>&);

// functor
struct Smaller_Radius{
	bool operator() (Circle c1, Circle c2) const
	{
		return (c1 < c2);
	}
};

TEST_CASE ("Circle sort via lambda function", "[Circle]"){
	//srand(time(NULL));
	std::vector<Circle> v;
	fill_vector(v);

	std::sort(v.begin(), v.end(), Smaller_Radius());

	// check if container is sorted correctly
	REQUIRE(std::is_sorted(v.begin(), v.end()));
}

int main (int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}

// fill a vector with 10 random circles
void fill_vector(std::vector<Circle>& l){
	float r;

	for(int i = 0; i < 10; i++){
		// generate random number between 0 and 100
		r = rand() % 101;

		// circle name
		std::string n = "Circle " + std::to_string(i);

		// create circle
		Circle c {r, n};
		l.push_back(c);
	}
}