#define CATCH_CONFIG_RUNNER
#include <algorithm>
#include <catch.hpp>
#include <iostream>
#include <string>
#include <vector>

TEST_CASE ("vector add elements", "[vector]"){
	std::vector<int>v_1{1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int>v_2{9, 8, 7, 6, 5, 4, 3, 2, 1};
	std::vector<int>v_3(9);

	auto lambda = [](int x, int y) ->int {return (x + y);};
	auto delta = [](int i)-> bool {return(i==10);};

	std::transform(v_1.begin(), v_1.end(), v_2.begin(), v_3.begin(), lambda);

	// check if all elements in v_3 equal 10
	REQUIRE (std::all_of(v_3.begin(), v_3.end(), delta));
}

int main (int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}