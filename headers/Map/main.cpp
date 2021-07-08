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
  // main_m();
  ft::map<char,int> mymap;
  std::map<char,int> mymap2;
  // char c;

  mymap ['a']=101;
  mymap2 ['a']=101;
  mymap ['b']=200;
  mymap2 ['b']=200;
  mymap ['c']=202;
  mymap2 ['c']=202;
  mymap ['f']=303;
  mymap2 ['f']=303;

  ft::map<char, int>::iterator it = mymap.lower_bound ('b');
  std::map<char, int>::iterator it2 = mymap2.lower_bound ('b');
  std::cout << it->first;
  std::cout << it2->first;

  return 0;
}