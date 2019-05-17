#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <time.h>

// function declaration
std::list<unsigned int> create_u_i_list();
std::map<unsigned int, unsigned int> app_numb_list(std::set<unsigned int>, std::list<unsigned int>);
std::set<unsigned int> elements_u_i_list(std::list<unsigned int>);
std::set<unsigned int> n_elements_u_i_list(std::set<unsigned int>);
unsigned int count_element(unsigned int, std::list<unsigned int>);
void print_u_i_list(std::list<unsigned int>);
void print_u_i_map(std::map<unsigned int, unsigned int>);
void print_u_i_set(std::set<unsigned int>);

// awesome main function
int main(int argc, char *argv[]){
	std::list<unsigned int> rand_list;
	std::set<unsigned int> list_elements;
	std::set<unsigned int> not_list_elements;
	std::map<unsigned int, unsigned int> app_map;

	// initialize random seed
	srand(time(NULL));

	// fill list
	rand_list = create_u_i_list();
	print_u_i_list(rand_list);

	// fill set with elements of list
	list_elements = elements_u_i_list(rand_list);
	print_u_i_set(list_elements);

	// check for elements that are not in the list
	not_list_elements = n_elements_u_i_list(list_elements);
	print_u_i_set(not_list_elements);

	// fill map
	app_map = app_numb_list(list_elements, rand_list);
	print_u_i_map(app_map);

	return 0;
}

// create a 100 values long list with random unsigned int values
std::list<unsigned int> create_u_i_list(){
	std::list<unsigned int> l;
	// fill list with random values
	for(int i = 0; i < 100; i++){
		// generate random number between 0 and 100
		unsigned int r = rand() % 101;
		// add random number to end of list
		l.push_back(r);
	}
	return l;
}

// count how often element appears in list
unsigned int count_element(unsigned int e, std::list<unsigned int> l){
	unsigned int counter = 0;
	for(unsigned int i : l){
		if(e == i){
			counter += 1;
		}
	}
	return counter;
}

std::map<unsigned int, unsigned int> app_numb_list(std::set<unsigned int> s, std::list<unsigned int> l){
	std::map<unsigned int, unsigned int> m;
	for(unsigned int i : s){
		m.insert(std::pair<unsigned int, unsigned int>(i, count_element(i, l)));
	}
	return m;
}

// create a set with all elements in the list
std::set<unsigned int> elements_u_i_list(std::list<unsigned int> l){
	std::set<unsigned int> s;
	// for each element in the list, make an entry
	for(unsigned int i : l){
		s.insert(i);
	}
	return s;
}

// create a set with all elements that are not in the set
std::set<unsigned int> n_elements_u_i_list(std::set<unsigned int> l){
	std::set<unsigned int> s;
	// for each missing element in the set, make an entry
	for(unsigned int i = 0; i <= 100; i++){
		if(l.find(i)==l.end()){
			s.insert(i);
		}
	}
	return s;
}

// print an unsigned int list
void print_u_i_list(std::list<unsigned int> l){
	std::cout<<"Elements in the list: \n";
	for (unsigned int i : l)
	{
		std::cout<<i<<", ";
	}
	std::cout<<"Number of elements: "<< l.size() <<"\n";
}

// print an unsigned int map
void print_u_i_map(std::map<unsigned int, unsigned int> l){
	std::map<unsigned int, unsigned int>::iterator itr;
	std::cout<<"Elements in the map: \n";
	unsigned int counter = 0;
	for (itr = l.begin(); itr != l.end(); itr++)
	{
		std::cout<<itr->first<<", "<<itr->second<<"\n";
		counter += itr->second;
	}
	std::cout<<"All numbers appear in total a "<< counter <<" times\n";
}

// print an unsigned int set
void print_u_i_set(std::set<unsigned int> l){
	std::cout<<"Elements in the set: \n";
	for (unsigned int i : l){
		std::cout << i <<", "; 
	}
	std::cout<<"Number of elements: "<< l.size() <<"\n";
}