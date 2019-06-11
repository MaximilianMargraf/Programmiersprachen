#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include<math.h>

#include "List.hpp"

// test 2d vector
TEST_CASE ("test_default_constructors", "[DefaultConstructor]"){
	// test default constructor for empty list
	List<int> list;
	REQUIRE(list.empty());
	REQUIRE(list.size() == 0);
}

TEST_CASE ("add an element with push_front", "[ modifiers ]")
{
	List<int> list;
	list.push_front(42);
	REQUIRE(42==list.front());
	REQUIRE(42==list.back());
	REQUIRE(list.size() == 1);

	list.push_front(33);
	REQUIRE(33==list.front());
	REQUIRE(42==list.back());
	REQUIRE(list.size() == 2);
}

TEST_CASE ("add an element with push_back", "[modifiers]")
{
	List<int> list;
	list.push_back(55);
	REQUIRE(55==list.front());
	REQUIRE(55==list.back());
	REQUIRE(list.size() == 1);

	list.push_back(66);
	REQUIRE(55==list.front());
	REQUIRE(66==list.back());
	REQUIRE(list.size() == 2);
}

TEST_CASE ("delete an element with pop_front", "[modifiers]")
{
	List<int> list;
	list.push_front(55);
	list.pop_front();

	list.push_front(55);
	list.push_front(44);
	list.push_back(66);

	REQUIRE(44==list.front());
	list.pop_front();
	REQUIRE(55==list.front());
	list.pop_front();
	REQUIRE(66==list.front());
	list.pop_front();
	REQUIRE(list.empty());
}

TEST_CASE ("delete an element with pop_back", "[modifiers]")
{
	List<int> list;
	list.push_front(55);
	list.pop_back();

	list.push_front(55);
	list.push_front(44);
	list.push_back(66);

	REQUIRE(66==list.back());
	list.pop_back();
	REQUIRE(55==list.back());
	list.pop_back();
	REQUIRE(44==list.back());
	list.pop_back();
	REQUIRE(list.empty());
}

TEST_CASE ("should be empty after clearing", "[modifiers]")
{
	List<int> list;
	list.push_front(55);
	list.push_front(44);
	list.push_back(66);
	list.clear();
	REQUIRE(list.empty());
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
