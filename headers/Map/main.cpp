#include <iostream>
#include "Map.hpp"
#include "utils.hpp"
#include "BidirectionalIteratorMap.hpp"

#include <map>

// int main()
// {
//   ft::map<int, int> mymap;

//   ft::pair<int, int> pr;

//   for (int i = 0; i < 50; i++) {
//     mymap.insert(ft::make_pair<int, int>(i, i));
//   }

//   for (ft::map<int, int>::iterator start = mymap.begin(); start != mymap.end(); start++) {
//     std::cout << start->first << " " << start->second << std::endl;
//   }
// }

int main()
{
  ft::map<int, int> mymap;
  std::map<int, int> smap;

  // std::map<int, int>::iterator sit = smap.begin();
  // std::cout << sit->first;
  // std::cout << sit->second;

  ft::map<int, int>::iterator mit = mymap.begin();
  ft::map<int, int>::iterator mit2;
  std::cout << mit->first;
  std::cout << mit->second;
  mit2 = mit;

  // std::cout << mit->second;
}