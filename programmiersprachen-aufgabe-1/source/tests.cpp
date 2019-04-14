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
float fract(float tofrac)
{
	int h = tofrac;
	float c = h - tofrac;
	return c * (-1);
}


TEST_CASE ("describe_fract", "[fract]")
{
	REQUIRE (fract(1.45) == Approx(0.45));
	REQUIRE (fract(2) == Approx(0));
	REQUIRE (fract(-10.78695032356) == Approx(-0.78695032356));
	REQUIRE (fract(0.0023) == Approx(0.0023));
}


// 1.12 volume and surface of a cylinder
float surface_cylinder(float radius, float height)
{
	if (radius < 0 || height < 0)
	{
		return 0.0;
	}
	
	else
	{
		return 2 * M_PI * pow(radius, 2) + 2 * M_PI * radius * height;
	}
}


float volume_cylinder(float radius, float height)
{
	if (radius < 0 || height < 0)
	{
		return 0.0;
	}
	
	else
	{
		return M_PI * pow(radius, 2) * height;
	}
}


TEST_CASE ("describe_surface_cylinder", "[surface_cylinder]")
{
	REQUIRE (surface_cylinder(5, 10) == Approx(471.23889));
	REQUIRE (surface_cylinder(0, 10) == Approx(0));
	REQUIRE (surface_cylinder(2, -3) == Approx(0));
}


TEST_CASE ("describe_volume_cylinder", "[volume_cylinder]")
{
	REQUIRE (volume_cylinder(5, 10) == Approx(785.398));
	REQUIRE (volume_cylinder(0, 10) == Approx(0));
	REQUIRE (volume_cylinder(2, -3) == Approx(0));
}


// 1.13 factorial of an int
int factorial(int a)
{
	if (a ==0)
	{
		return 1;
	}

	int product = 1;

	for(int i = 1; i <= a; i++)
	{
		product = product * i;
	}

	return product;
}


TEST_CASE ("describe_factorial", "[factorial]")
{
	REQUIRE (factorial(0) == 1);
	REQUIRE (factorial(1) == 1);
	REQUIRE (factorial(3) == 6);
	REQUIRE (factorial(10) == 3628800);
}


// 1.14 is prime
bool is_prime(int a)
{
	if ( a == 0 || a == 1)
	{
		return false;
	}

	for(int i = 2; i < a; i++)
	{
		if (a % i == 0)
		{
			return false;
		}
	}

	return true;
}


TEST_CASE ("describe_is_prime", "[is_prime]")
{
	REQUIRE (is_prime(0) == false);
	REQUIRE (is_prime(1) == false);
	REQUIRE (is_prime(2) == true);
	REQUIRE (is_prime(3) == true);
	REQUIRE (is_prime(10) == false);
	REQUIRE (is_prime(15) == false);
	REQUIRE (is_prime(97) == true);
}


// 1.15 mile to kilometers
double mile_to_kilometer(double miles)
{
	return 1.609344 * miles;
}


TEST_CASE ("describe_mile_to_kilometer", "[mile_to_kilometer]")
{
	REQUIRE (mile_to_kilometer(0) == Approx(0));
	REQUIRE (mile_to_kilometer(1) == Approx(1.609344));
	REQUIRE (mile_to_kilometer(3) == Approx(4.828032));
	REQUIRE (mile_to_kilometer(15) == Approx(24.14016));
}



int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
