# include <cstdlib> // std :: rand ()
# include <vector> // std :: vector < >
# include <list> // std :: list < >
# include <iostream> // std :: cout
# include <iterator> // std :: ostream_iterator < >
# include <algorithm> // std :: reverse , std :: generate

int main (){
	//vector with random numbers
	std::vector < int > v_0 (10);

	// fill with random numbers
	for ( auto & v : v_0 ) {
		v = std :: rand ();
	}

	// copy all elements within v_0 into the outstream with iterator to the beginning of the given container
	std::copy(std::cbegin(v_0), std::cend(v_0),
	// for each element int type objects are being written in the output stream
	std::ostream_iterator<int>( std::cout, "\n"));

	// construct a list via a vector over the iteration from begin to end
	std::list<int> l_0 (std::cbegin(v_0), std::cend(v_0));

	// construct a second list from the first list via iteration
	std::list<int> l_1 (std::cbegin(l_0), std::cend(l_0));

	// reverse the second list
	std::reverse (std::begin(l_1), std::end(l_1));

	//like the first function just with a list
	std::copy(std::cbegin(l_1), std::cend(l_1),
	std::ostream_iterator<int>( std::cout, "\n"));

	// sort l1, smallest to largest is default
	l_1.sort();
	// copy with an iterator pointing to the first element in the list contine
	std::copy(l_1.cbegin(),l_1.cend(),
	std::ostream_iterator<int>(std::cout, "\n"));

	// in the given range (indicated by iterators) call a generator function object
	std::generate(std::begin(v_0), std::end(v_0), std::rand);
	
	// copy list into the ostream iterator
	std::copy(v_0.crbegin(), v_0.crend(),
	std::ostream_iterator<int>(std::cout, "\n"));

	return 0;
}