#include <iostream>
#include "Map.hpp"
#include "utils.hpp"
#include "BidirectionalIteratorMap.hpp"

#include <map>

// int main()
// {
//   // ft::map<int, int> m1;
//   // m1.insert(ft::make_pair<int, int>(100, 100));
//   // m1.insert(ft::make_pair<int, int>(200, 200));
//   // m1.insert(ft::make_pair<int, int>(300, 300));
//   // m1.insert(ft::make_pair<int, int>(400, 400));


//   // ft::map<int, int> m2;
//   // m2.insert(ft::make_pair<int, int>(500, 500));
//   // m2.insert(ft::make_pair<int, int>(600, 600));

//   // std::cout << "m1 contains:\n";
//   // for (ft::map<int,int>::iterator it = m1.begin(); it!=m1.end(); ++it)
//   //   std::cout << it->first << " => " << it->second << '\n'; 
//   // std::cout << "size " << m1.size() << std::endl;

//   //   std::cout << "\nm2 contains:\n";
//   // for (ft::map<int,int>::iterator it = m2.begin(); it!=m2.end(); ++it)
//   //   std::cout << it->first << " => " << it->second << '\n';
//   // std::cout << "size " << m2.size() << std::endl;

//   // m1.swap(m2);

//   // std::cout << "\nm1 contains:\n";
//   // for (ft::map<int,int>::iterator it = m1.begin(); it!=m1.end(); ++it)
//   //   std::cout << it->first << " => " << it->second << '\n'; 
//   // std::cout << "size " << m1.size() << std::endl;

//   //   std::cout << "\nm2 contains:\n";
//   // for (ft::map<int,int>::iterator it = m2.begin(); it!=m2.end(); ++it)
//   //   std::cout << it->first << " => " << it->second << '\n';

//   // std::cout << "size " << m2.size() << std::endl;

// }

int main_m ()
{
  std::map<char,int> mymap;
  char c;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
  {
    std::cout << c;
    if (mymap.count(c)>0)
      std::cout << " is an element of mymap.\n";
    else 
      std::cout << " is not an element of mymap.\n";
  }

  return 0;
}

int main ()
{
  int psize;
  ft::map<char,int> mymap;
  ft::pair<char,int> * p;

  // allocate an array of 5 elements using mymap's allocator:
  p = mymap.get_allocator().allocate(5);

  // assign some values to array
  psize = sizeof(ft::map<char,int>::value_type)*5;

  std::cout << "The allocated array has a size of " << psize << " bytes.\n";

  mymap.get_allocator().deallocate(p,5);

  return 0;
}