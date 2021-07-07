#include <iostream>
#include "Map.hpp"
#include "utils.hpp"
#include "BidirectionalIteratorMap.hpp"

#include <map>

int main()
{
  ft::map<int, int> m;
  std::map<int, int> s;

  m.insert(ft::make_pair<int, int>(100, 100));
  m.insert(ft::make_pair<int, int>(200, 100));
  m.insert(ft::make_pair<int, int>(300, 100));
  m.insert(ft::make_pair<int, int>(400, 100));
  m.insert(ft::make_pair<int, int>(500, 100));
  m.insert(ft::make_pair<int, int>(600, 100));
  m.insert(ft::make_pair<int, int>(700, 100));
  m.insert(ft::make_pair<int, int>(800, 100));

  std::cout << m[800] << std::endl;


}