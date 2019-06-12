#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <algorithm>
#include <vector>

#include "circle.hpp"
#include "List.hpp"

// test 2d vector
TEST_CASE ("test_default_constructors", "[DefaultConstructor]"){
	// test default constructor for empty list
	List<int> list;
	REQUIRE(list.empty());
	REQUIRE(list.size() == 0);
}

TEST_CASE ("add an element with push_front", "[ modifiers ]"){
	List<int> list;
	list.push_front(42);
	REQUIRE(42==list.front());
	REQUIRE(42==list.back());
	REQUIRE(list.size() == 1);

	list.push_front(33);
	REQUIRE(33==list.front());
	REQUIRE(42==list.back());
	REQUIRE(list.size() == 2);

	List<int> lost{2, 20};
	REQUIRE(2==lost.front());
	REQUIRE(20==lost.back());
}

TEST_CASE ("add an element with push_back", "[modifiers]"){
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

TEST_CASE ("delete an element with pop_front", "[modifiers]"){
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

TEST_CASE ("delete an element with pop_back", "[modifiers]"){
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

TEST_CASE ("should be empty after clearing", "[modifiers]"){
	List<int> list;
	list.push_front(55);
	list.push_front(44);
	list.push_back(66);
	list.clear();
	REQUIRE(list.empty());
}

TEST_CASE ("Test own iterator", "[iterator]"){
	List<Circle> circle_list;
	Circle c1 {1, "Number One"};
	Circle c2 {2, "Number Two"};
	Circle c3 {3, "Number Three"};
	Circle c4 {3, "Number Four"};
	circle_list.push_back(c1);
	circle_list.push_back(c2);
	circle_list.push_back(c3);
	circle_list.push_back(c4);

	auto c_it = circle_list.begin();

	// check if the dereferenced iterator equals the circle object.
	REQUIRE(*c_it == c1);
	REQUIRE(c_it->get_radius()==1);
	
	++c_it;
	REQUIRE(c_it->get_radius() == 2);

	auto c_if = c_it++;
	REQUIRE(*c_if == c2);
	REQUIRE(*c_it == c3);
	REQUIRE(c_if != c_it);
	c_if++;
	REQUIRE(c_if == c_it);
}

TEST_CASE("should be an empty range after default construction", "[iterator]"){
	List<int> list;
	auto b = list.begin();
	auto e = list.end();
	REQUIRE(b.node == nullptr);
	REQUIRE(e.node == nullptr);
}

TEST_CASE("provide access to the first element with begin", "[iterator]"){
	List<int> list;
	list.push_front(42);
	REQUIRE(42 == *list.begin());
}

TEST_CASE("test comparisons of 2 lists with different sizes", "[lists]"){
	List<int> list;
	list.push_front(42);

	List<int> lost;
	lost.push_front(44);
	lost.push_front(43);
	REQUIRE(list != lost);
}

TEST_CASE("test comparisons of 2 lists with same sizes and same values", "[lists]"){
	List<int> list;
	list.push_front(42);
	list.push_front(43);

	List<int> lost;
	lost.push_front(42);
	lost.push_front(43);
	REQUIRE(list == lost);
	lost.push_front(45);
	bool eq = (list==lost);
	REQUIRE(!eq);
}

TEST_CASE("test comparisons of 2 lists with same sizes and different values", "[lists]"){
	List<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);

	List<int> lost;
	lost.push_front(2);
	lost.push_front(3);
	lost.push_front(4);
	REQUIRE(list != lost);
	lost.push_front(5);
	bool eq = (list==lost);
	REQUIRE(!eq);
}

TEST_CASE("copy constructor", "[constructor]"){
	List<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	List<int> list2{list};
	REQUIRE(list == list2);
}

TEST_CASE("insert element at iterator position", "[iterator]"){
	List<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	auto c_it = list.begin();
	c_it++;
	c_it++;
	auto c_it2 = list.insert(c_it, 6);

	List<int> list2;
	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(6);
	list2.push_back(3);
	list2.push_back(4);
	REQUIRE(list == list2);
}

TEST_CASE("reverse list", "[reverse]"){
	List<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);

	// test function
	auto list3 = reverse(list);

	List<int> list2;
	list2.push_front(4);
	list2.push_front(3);
	list2.push_front(2);
	list2.push_front(1);

	// test method
	REQUIRE(list == list2);
	REQUIRE(list == list3);
}

/*TEST_CASE("std::copy", "[optional]"){
	List<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);

	std::vector<int> v;
	std::copy(list.begin(), list.end(), std::back_inserter(v));
	//std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	//std::cout << "\n";
}*/

TEST_CASE("move constructor", "[constructor]"){
	List<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	List<int> list2 = std::move(list);
	REQUIRE(0 == list.size());
	REQUIRE(list.empty());
	REQUIRE(4==list2.size());
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}