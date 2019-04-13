#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <string>

// 1.8 greatest common divider
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


// 1.9 digit sum
int checksum (int a)
{
	int sum = 0;
	std::string str = std::to_string(a);

	if (a >= 0)
	{
		for(int i = 0; i < str.length(); i++)
		{
			sum += str[i] - 48;
		}
	}

	// negative case
	else
	{
		for(int i = 1; i < str.length(); i++)
		{
			sum -= str[i] - 48;	
		}
	}

	return sum;
}


TEST_CASE ("describe_checksum", "[checksum]")
{
	REQUIRE (checksum (115692) == 24);
	REQUIRE (checksum (-23) == -5);
	REQUIRE (checksum (0) == 0);
}


int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
