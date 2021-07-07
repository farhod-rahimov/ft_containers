#include <iostream>
#include "Map.hpp"
#include "utils.hpp"
#include "BidirectionalIteratorMap.hpp"

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
  ft::BidirectionalIteratorMap<int> it;

  it++;
  ++it;
  it--;
  --it;
}