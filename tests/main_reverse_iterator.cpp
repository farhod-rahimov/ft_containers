#include "../utils/ReverseIterator.hpp"
#include "../headers/Map.hpp"
#include "../headers/Vector.hpp"

#include <iostream>

void constructor() {
	ft::vector<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;
																												 // ? 0 1 2 3 4 5 6 7 8 9 ?
	iter_type from (myvector.begin());                     //   ^
																												 //         ------>
	iter_type until (myvector.end());                      //                       ^
																												 //
	ft::reverse_iterator<iter_type> rev_until (from);     // ^
																												 //         <------
	ft::reverse_iterator<iter_type> rev_from (until);     //                     ^

	std::cout << "myvector:";
	while (rev_from != rev_until)
		std::cout << ' ' << *rev_from++;
	std::cout << '\n';
};

int main()
{
		std::cout << "The output should be\nmyvector: 9 8 7 6 5 4 3 2 1 0\n";
		std::cout << "--------------------------------------------------------------------\n";
		std::cout << "My output\n";
		constructor();
}