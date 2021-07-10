#include <iostream>
#include "Map.hpp"
#include "utils.hpp"
#include "BidirectionalIteratorMap.hpp"

#include <map>

void m() {
  ft::map<int,int> mymap;
  for (int i = 100; i <= 4000; i+=100) {
    mymap.insert(ft::make_pair(i, i));
  }
  std::cout << "mymap size " << mymap.size() << std::endl;

  ft::map<int, int>::iterator c;
  ft::map<int, int>::iterator d;
  c = mymap.begin();
  d = mymap.begin();

  ft::map<int, int>::iterator con;

  con = mymap.begin();
  con++;
  std::cout << con->first;
}

int main ()
{
  m();
  // while (1)
  //   ;
  return 0;
}