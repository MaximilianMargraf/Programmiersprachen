#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>

bool is_multiple_of_3(unsigned int);
bool is_not_multiple_of_3(unsigned int);

void fill_u_i_vector(std::vector<unsigned int>&);
void print(std::vector<unsigned int>&);

TEST_CASE("filter alle vielfache von drei", "[erase]"){
	std::vector<unsigned int> v;
	fill_u_i_vector(v);

	// erase() itself would only delete one element and then move all following elements
	// one element forward. With remove_if, we can hurry this up. All elements
	// that do fit the criteria are moved to the end of the container. remove()
	// then returns an iterator pointing to the first of these elements, wich can easily
	// be deleted with a single call to erase.
	v.erase(
		std::remove_if(v.begin(), v.end(), is_not_multiple_of_3),
		v.end());

	// test it
	REQUIRE (std::all_of(v.begin(), v.end(), is_multiple_of_3));
}

int main (int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}

// fill a vector with 100 random unsigned int values
void fill_u_i_vector(std::vector<unsigned int>& l){
	for(int i = 0; i < 100; i++){
		// generate random number between 0 and 100
		unsigned int r = rand() % 101;
		// add random number to end of vector
		l.push_back(r);
	}
}

bool is_not_multiple_of_3(unsigned int i){
	if(i % 3 == 0){
		return false;
	}
	else{
		return true;
	}
}

bool is_multiple_of_3(unsigned int i){
	if(i % 3 == 0){
		return true;
	}
	else{
		return false;
	}
}

void print(std::vector<unsigned int>& v){
	for(unsigned int i : v){
		std::cout<<i<<" ";
	}
	std::cout<<"\n";
}