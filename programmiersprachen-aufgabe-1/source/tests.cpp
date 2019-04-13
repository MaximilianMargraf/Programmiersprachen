#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <string>
#include <math.h>

// 1.8 greatest common divider
int gcd(int a, int b)
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
int checksum(int a)
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


// 1.10 add all number from 1 to 1000, which are dividable by 3 !or! 5
int sum_multiples()
{
	int sum = 0;
	
	for (int i = 1; i <= 1000; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}

	return sum;
}


TEST_CASE ("describe_sum_multiples", "[sum_multiples]")
{
	REQUIRE (sum_multiples() == 234168);
}


// 1.11 calculation of the "after ," part of a float


// 1.12 volume and surface of a cylinder
float surface_cylinder(float radius, float height)
{
	return 2 * M_PI * pow(radius, 2) + 2 * M_PI * radius * height;
}

float volume_cylinder(float radius, float height)
{
	return M_PI * pow(radius, 2) * height;
}

TEST_CASE ("describe_surface_cylinder", "[surface_cylinder]")
{
	REQUIRE (surface_cylinder(5, 10) == Approx(471.23889));
	REQUIRE (surface_cylinder(0, 10) == Approx(0));
}

TEST_CASE ("describe_volume_cylinder", "[volume_cylinder]")
{
	REQUIRE (volume_cylinder(5, 10) == Approx(785.398));
	REQUIRE (volume_cylinder(0, 10) == Approx(0));
}

// 1.13 factorial of an int

// 1.14 is prime

// mile to kilometers


int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
