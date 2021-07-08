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

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  std::pair<char,int> highest = *mymap.end();          // last element

  std::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );

  return 0;
}

int main ()
{
  main_m();
  ft::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  ft::pair<char,int> highest = *mymap.end();          // last element

  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );

  return 0;
}