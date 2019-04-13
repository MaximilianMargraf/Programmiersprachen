#define CATCH_CONFIG_RUNNER
#include <catch.hpp>


int gcd (int a, int b)
{
	// Euklid
	int rest = 1;

	while (rest != 0)
	{
		rest = a % b;
		a = b;
		b = rest;
	}

	// take the value of b when rest = 0
	return a;
}


TEST_CASE ("describe_gcd", "[gcd]")
{
	REQUIRE (gcd (2 ,4) == 2);
	REQUIRE (gcd (9 ,6) == 3);
	REQUIRE (gcd (3 ,7) == 1);
}


int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
