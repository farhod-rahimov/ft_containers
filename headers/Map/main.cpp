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
  m.insert(ft::make_pair<int, int>(200, 200));
  m.insert(ft::make_pair<int, int>(300, 300));
  m.insert(ft::make_pair<int, int>(400, 400));
  m.insert(ft::make_pair<int, int>(500, 500));
  m.insert(ft::make_pair<int, int>(600, 600));
  m.insert(ft::make_pair<int, int>(700, 700));
  m.insert(ft::make_pair<int, int>(800, 800));

  std::cout << m[900] << std::endl;


}