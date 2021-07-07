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

  ft::map<int, int>::iterator it;

  std::cout << "------------\n";
  it = m.begin();
  for (; it != m.end(); it++) {
    std::cout << it->first << " " << it->second << std::endl;
  }
  std::cout << "------------\n";
  it = m.end();
  for (; it != m.begin(); it--) {
    std::cout << it->first << " " << it->second << std::endl;
  }
  std::cout << it->first << " " << it->second << std::endl;
}