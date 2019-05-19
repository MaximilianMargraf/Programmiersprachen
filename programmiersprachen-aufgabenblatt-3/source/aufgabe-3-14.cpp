#define CATCH_CONFIG_RUNNER
#include <algorithm>
#include <catch.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "circle.hpp"

void fill_vector(std::vector<Circle>&);

TEST_CASE ("vector add elements", "[vector]"){
	std::vector<Circle> v;
	std::vector<Circle> w;
	fill_vector(v);

	// check if radius > 4.0f
	auto lambda = [](Circle c) ->bool {return (c > 4.0f);};

	// copy all circles from v to w that satisfy lambda
	std::copy_if(v.begin(), v.end(), std::back_inserter(w), lambda);
	
	// check if all elements in w > 3
	auto delta = [](Circle c) ->bool {return (c > 3.0f);};
	REQUIRE (std::all_of(w.begin(), w.end(), delta));
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
		r = rand() % 11;

		// circle name
		std::string n = "Circle " + std::to_string(i);

		// create circle
		Circle c {r, n};
		l.push_back(c);
	}
}