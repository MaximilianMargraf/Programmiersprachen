#define CATCH_CONFIG_RUNNER
#include <algorithm>
#include <catch.hpp>
#include <iostream>
#include <string>
#include <vector>

bool is_even(int);

template <class T, class F>
T filter(T t, F f){
	T v;
	for(auto& a : t){
		if(f(a)){
			v.push_back(a);
		}
	}
	return v;
}

TEST_CASE ("filter function template", "[filter]"){
	std::vector<int>v {1, 2, 3, 4, 5,6};
	std::vector<int>all_even = filter(v, is_even);

	auto lambda = [](int x) ->bool {return (x % 2 == 0);};

	// check if all elements in v_3 equal 10
	REQUIRE (std::all_of(all_even.begin(), all_even.end(), lambda));
}

int main (int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}

bool is_even(int n){
	return (n % 2 == 0);
}