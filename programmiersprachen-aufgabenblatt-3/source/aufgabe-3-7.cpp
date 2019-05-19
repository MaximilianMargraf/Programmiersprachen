#define CATCH_CONFIG_RUNNER
#include <algorithm>
#include <catch.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "circle.hpp"
#include "color.hpp"
#include "vec2.hpp"

/*
Why use lambdas?
A lambda expression is a syntactic shortcut for a functor
Thus, like functors, lambdas can contain a state and are therefore
customizeable.
*/

void fill_vector(std::vector<Circle>&);

TEST_CASE ("Circle sort via lambda function", "[Circle]"){
	//srand(time(NULL));
	std::vector<Circle> v;
	fill_vector(v);

	// [] - the capture "clause". Specifies which outside variables are available for the lambda funtion,
	// and wether they should be captured by value or reference

	// () - optional parameter list to give to the lambda function

	// -> - returnTypeDelcaration. Most compilers can deduce this by the return statement,
	// however it makes the code easier to understand and clarifies the function of lambda

	// {} - like a normal function, the code in the {} returns a value. It can access
	// captured variables and the paramters

	// auto lambda = [capture clause](optional parameters) -> returnType {lambda body};

	auto lambda = [](Circle c1, Circle c2){ return (c1 < c2);};

	// use of lambda function to compare circles
	std::sort(v.begin(), v.end(), lambda);
	//alternatively
	//std::sort(v.begin(), v.end(), [](Circle c1, Circle c2) { return (c1 < c2);});

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