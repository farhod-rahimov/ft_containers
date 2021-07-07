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
  std::cout << it.first->first << " " << it.first->second << " " << it.second << std::endl;
  it = m.insert(ft::make_pair<int, int>(200, -100));
  std::cout << it.first->first << " " << it.first->second << " " << it.second << std::endl;
  it = m.insert(ft::make_pair<int, int>(300, -100));
  std::cout << it.first->first << " " << it.first->second << " " << it.second << std::endl;
  it = m.insert(ft::make_pair<int, int>(400, -100));
  std::cout << it.first->first << " " << it.first->second << " " << it.second << std::endl;
  it = m.insert(ft::make_pair<int, int>(500, -100));
  std::cout << it.first->first << " " << it.first->second << " " << it.second << std::endl;
  it = m.insert(ft::make_pair<int, int>(99, -100));
  std::cout << it.first->first << " " << it.first->second << " " << it.second << std::endl;
  it = m.insert(ft::make_pair<int, int>(80, -100));
  std::cout << it.first->first << " " << it.first->second << " " << it.second << std::endl;
  it = m.insert(ft::make_pair<int, int>(70, -100));
  std::cout << it.first->first << " " << it.first->second << " " << it.second << std::endl;
  it = m.insert(ft::make_pair<int, int>(60, -100));
  std::cout << it.first->first << " " << it.first->second << " " << it.second << std::endl;

  std::cout << "------------------------------------\n";
  
  ft::map<int, int> m2(m.begin(), m.end());
  for (ft::map<int, int>::iterator it2 = m2.begin(); it2 != m2.end(); it2++) {  
    std::cout << it2->first << " " << it2->second << std::endl;
  }
  
  std::cout << "------------333333333------------------\n";
  ft::map<int, int> m3(m2);
  
  for (ft::map<int, int>::iterator it2 = m3.begin(); it2 != m3.end(); it2++) {  
    std::cout << it2->first << " " << it2->second << std::endl;
  }
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