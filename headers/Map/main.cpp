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
  mymap.clear();
  std::cout << mymap.insert(ft::make_pair(3000, 3000)).first->first << std::endl;
  std::cout << "mymap size " << mymap.size() << std::endl;

  ft::map<int, int>::iterator c;
  ft::map<int, int>::iterator d;
  c = mymap.begin();
  d = mymap.begin();

  // std::map<int, int> m;
  // for (int i = 100; i <= 4000; i+=100) {
  //   m.insert(std::make_pair(i, i));
  // }
  // std::map<int, int>::const_iterator p;
  // std::map<int, int>::iterator q;
  // p = m.begin();
  // q = m.begin();
  // std::cout << "6546546    " << p->first << " " << p->second << std::endl;
  // p->second = 123;
  // q->second = 123;
  // std::cout << "6546546    " << p->first << " " << p->second;

}

int main ()
{
  m();
  // while (1)
  //   ;
  return 0;
}