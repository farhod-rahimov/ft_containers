#include <iostream>
#include "Map.hpp"
#include "utils.hpp"
#include "BidirectionalIteratorMap.hpp"

#include <map>

void m() {
  ft::map<int,int> mymap;
  mymap.insert(ft::make_pair(100, 100));
  mymap.insert(ft::make_pair(200, 200));
  mymap.insert(ft::make_pair(300, 300));
  mymap.insert(ft::make_pair(400, 400));
  mymap.insert(ft::make_pair(500, 500));
  mymap.insert(ft::make_pair(600, 600));
  mymap.insert(ft::make_pair(700, 700));
  mymap.insert(ft::make_pair(800, 800));
  mymap.insert(ft::make_pair(900, 900));
  mymap.insert(ft::make_pair(1000, 1000));
  mymap.insert(ft::make_pair(1100, 1100));
  mymap.insert(ft::make_pair(1200, 1200));
  mymap.insert(ft::make_pair(1300, 1300));
  mymap.insert(ft::make_pair(1400, 1400));
  mymap.insert(ft::make_pair(1500, 1500));
  mymap.insert(ft::make_pair(1600, 1600));
  mymap.insert(ft::make_pair(1700, 1700));
  mymap.insert(ft::make_pair(1800, 1800));
  mymap.insert(ft::make_pair(1900, 1900));
  mymap.insert(ft::make_pair(2000, 2000));
  mymap.insert(ft::make_pair(2100, 2100));
  mymap.insert(ft::make_pair(2200, 2200));
  mymap.insert(ft::make_pair(2300, 2300));
  mymap.insert(ft::make_pair(2400, 2400));
  mymap.insert(ft::make_pair(2500, 2500));
  mymap.insert(ft::make_pair(2600, 2600));
  mymap.insert(ft::make_pair(2700, 2700));
  mymap.insert(ft::make_pair(2800, 2800));
  mymap.insert(ft::make_pair(2900, 2900));
  mymap.insert(ft::make_pair(3000, 3000));
  std::cout << "mymap size " << mymap.size() << std::endl;

  mymap.clear();
  mymap.insert(ft::make_pair(3000, 3000));
  std::cout << "mymap size " << mymap.size() << std::endl;
}

int main ()
{
  m();
  while (1)
    ;
  return 0;
}