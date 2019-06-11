#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include<math.h>

#include "List.hpp"

// test 2d vector
TEST_CASE ("test_default_constructors", "[DefaultConstructor]"){
	// test default constructor for empty list
	List<int> list;
	REQUIRE(list.empty() == true);
	REQUIRE(list.size() == 0);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
