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

  ft::pair<ft::map<int, int>::iterator, bool> pr;
  // std::cout << sit->first;
  // std::cout << sit->second;

  pr = mymap.insert(ft::make_pair<int, int>(50, -50));
  // std::cout << pr.first->first << " "  << pr.first->second << " "  << pr.second << "\n";

  pr = mymap.insert(ft::make_pair<int, int>(40, -60));
  // std::cout << pr.first->first << " "  << pr.first->second << " "  << pr.second << "\n";
  pr = mymap.insert(ft::make_pair<int, int>(40, -60));
  // std::cout << pr.first->first << " "  << pr.first->second << " "  << pr.second << "\n";

  // ft::map<int, int>::iterator it = mymap.begin();
  // std::cout << it->first << std::endl;;
  // std::cout << it->second << std::endl;;

  // it++;
  // std::cout << it->first << std::endl;;
  // std::cout << it->second << std::endl;;

  // it++;
  // std::cout << it->first << std::endl;;
  // std::cout << it->second << std::endl;;
  //   it++;
  // std::cout << it->first << std::endl;;
  // std::cout << it->second << std::endl;;

  // it++;
  // std::cout << it->first << std::endl;;
  // std::cout << it->second << std::endl;;


  std::cout << mymap[50];
  std::cout << mymap[40];

  // std::cout << mit->second;
}