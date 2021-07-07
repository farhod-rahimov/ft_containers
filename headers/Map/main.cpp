#include <iostream>
#include "Map.hpp"
#include "utils.hpp"
#include "BidirectionalIteratorMap.hpp"

#include <map>

int main()
{
  ft::map<int, int> m;

  // std::cout << m.insert(ft::make_pair<int, int>(100, -100)) << std::endl;
  std::cout << m.insert(ft::make_pair<int, int>(20, -100)) << std::endl;
  std::cout << m.insert(ft::make_pair<int, int>(30, -100)) << std::endl;
  // std::cout << m.insert(ft::make_pair<int, int>(40, -100)) << std::endl;

  // std::cout << m.insert(ft::make_pair<int, int>(100, -100)) << std::endl;
  std::cout << m.insert(ft::make_pair<int, int>(20, -100)) << std::endl;
  std::cout << m.insert(ft::make_pair<int, int>(30, -100)) << std::endl;
  // std::cout << m.insert(ft::make_pair<int, int>(40, -100)) << std::endl;
}