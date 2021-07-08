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

  std::cout << m[800] << std::endl;

  s.insert(std::make_pair<int, int>(100, 100));
  s.insert(std::make_pair<int, int>(200, 200));
  s.insert(std::make_pair<int, int>(300, 300));
  s.insert(std::make_pair<int, int>(400, 400));
  s.insert(std::make_pair<int, int>(500, 500));
  s.insert(std::make_pair<int, int>(600, 600));
  s.insert(std::make_pair<int, int>(700, 700));
  s.insert(std::make_pair<int, int>(800, 800));

  std::cout << m[800] << std::endl;

  ft::map<int, int> m2;
  m2.insert(m.begin(), ft::make_pair<int, int>(100, 100));
  std::cout << m2[200] << std::endl;

}