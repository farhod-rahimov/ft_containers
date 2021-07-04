#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout

#include "utils.hpp"
#include "Map.hpp"

int main () {

  ft::map<char, int> mymap;

  // ft::pair<char, int> pr('a', 100);
  
  mymap.insert ( std::pair<char,int>('a',100) );

  return 0;
}