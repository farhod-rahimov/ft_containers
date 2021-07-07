#include <iostream>
#include "Map.hpp"
#include "utils.hpp"
#include "BidirectionalIteratorMap.hpp"

#include <map>

int main()
{
  ft::map<int, int> m;
  ft::pair<ft::map<int, int>::iterator, bool> it;
  it = m.insert(ft::make_pair<int, int>(100, -100));

  std::cout << it.first->first << " " << it.first->second << std::endl;
  std::cout << it.second << std::endl;

  // ft::map<int, int>::iterator it;

  // std::cout << "------------\n";
  // it = m.begin();
  // for (; it != m.end(); it++) {
  //   std::cout << it->first << " " << it->second << std::endl;
  // }
  // std::cout << "------------\n";
  // it = m.end();
  // for (; it != m.begin(); it--) {
  //   std::cout << it->first << " " << it->second << std::endl;
  // }
  // std::cout << it->first << " " << it->second << std::endl;
}