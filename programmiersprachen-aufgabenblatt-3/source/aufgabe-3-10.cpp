# include <cstdlib> // std :: rand ()
# include <vector> // std :: vector < >
# include <list> // std :: list < >
# include <iostream> // std :: cout
# include <iterator> // std :: ostream_iterator < >
# include <algorithm> // std :: reverse , std :: generate

std::list<unsigned int> create_u_i_list();

int main (){
	// code from task 3.2
	std::list<unsigned int> rand_list;
	rand_list = create_u_i_list();

	// vector to copy list to
	std::vector<unsigned int> v;

	// copy list to vector with back inserter, an iterator for insertion at the end of a container
	std::copy(std::cbegin(rand_list), std::cend(rand_list), std::back_inserter(v));

	for(unsigned int i:v){
		std::cout<<i<<", ";
	}
	std::cout<<"\n\n";
	for(unsigned int i:rand_list){
		std::cout<<i<<", ";
	}

	std::cout<<rand_list.size() <<" = "<<v.size()<<"\n";

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