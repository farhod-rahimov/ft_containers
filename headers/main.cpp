#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout

#include "utils.hpp"
#include "Map.hpp"

int main () {

  ft::map<char, int> mymap;

  ft::pair<ft::map<char, int>::iterator, bool> pr;
  
  pr = mymap.insert ( ft::pair<char,int>('a',100) );
  std::cout << "First inserted_val " << pr.first->first << ", second inserted_val " << pr.first->second << \
  " and it is inserted " << pr.second << "\n";

  pr = mymap.insert ( ft::pair<char,int>('b',200) );
  std::cout << "First inserted_val " << pr.first->first << ", second inserted_val " << pr.first->second << \
  " and it is inserted " << pr.second << "\n";

  pr = mymap.insert ( ft::pair<char,int>('c',300) );
  std::cout << "First inserted_val " << pr.first->first << ", second inserted_val " << pr.first->second << \
  " and it is inserted " << pr.second << "\n";

  std::cout << "\n---FALSE TESTS--- \n\n";

  pr = mymap.insert ( ft::pair<char,int>('a',100) );
  std::cout << "First inserted_val " << pr.first->first << ", second inserted_val " << pr.first->second << \
  " and it is inserted " << pr.second << "\n";

  pr = mymap.insert ( ft::pair<char,int>('b',200) );
  std::cout << "First inserted_val " << pr.first->first << ", second inserted_val " << pr.first->second << \
  " and it is inserted " << pr.second << "\n";

  pr = mymap.insert ( ft::pair<char,int>('c',300) );
  std::cout << "First inserted_val " << pr.first->first << ", second inserted_val " << pr.first->second << \
  " and it is inserted " << pr.second << "\n";

  return 0;
}