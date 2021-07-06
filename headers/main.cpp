#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout

#include "utils.hpp"
#include "Map.hpp"

#include <map>

// int main () {

//   ft::map<char, int> mymap;

//   ft::pair<ft::map<char, int>::iterator, bool> pr;
//   ft::map<char, int>::iterator start;
//   ft::map<char, int>::iterator end;
  
//   pr = mymap.insert ( ft::pair<char,int>('a',100) );
//   // std::cout << "First inserted_val " << pr.first->first << ", second inserted_val " << pr.first->second << \
//   // " and it is inserted " << pr.second << "\n";

//   start = pr.first;

//   pr = mymap.insert ( ft::pair<char,int>('b',200) );
//   // std::cout << "First inserted_val " << pr.first->first << ", second inserted_val " << pr.first->second << \
//   // " and it is inserted " << pr.second << "\n";

//   pr = mymap.insert ( ft::pair<char,int>('c',300) );
//   // std::cout << "First inserted_val " << pr.first->first << ", second inserted_val " << pr.first->second << \
//   // " and it is inserted " << pr.second << "\n";
  
//   end = pr.first;

//   // std::cout << "\n---FALSE TESTS--- \n\n";

//   pr = mymap.insert ( ft::pair<char,int>('a',100) );
//   // std::cout << "First inserted_val " << pr.first->first << ", second inserted_val " << pr.first->second << \
//   // " and it is inserted " << pr.second << "\n";

//   pr = mymap.insert ( ft::pair<char,int>('b',200) );
//   // std::cout << "First inserted_val " << pr.first->first << ", second inserted_val " << pr.first->second << \
//   // " and it is inserted " << pr.second << "\n";

//   pr = mymap.insert ( ft::pair<char,int>('c',300) );
//   // std::cout << "First inserted_val " << pr.first->first << ", second inserted_val " << pr.first->second << \
//   // " and it is inserted " << pr.second << "\n";

//   ft::map<char,int> m;

//   m.insert(start, end);

//   return 0;
// }


int main ()
{
  std::map<int,char> mymap;

  mymap.insert (std::pair<int,char>(200, 'a'));
  mymap.insert (std::pair<int,char>(100, 'a'));
  mymap.insert (std::pair<int,char>(1500, 'a'));
  mymap.insert (std::pair<int,char>(987, 'a'));
  mymap.insert (std::pair<int,char>(2000, 'a'));
  mymap.insert (std::pair<int,char>(1700, 'a'));
  mymap.insert (std::pair<int,char>(3000, 'a'));
  mymap.insert (std::pair<int,char>(1750, 'a'));
  mymap.insert (std::pair<int,char>(1600, 'a'));
  mymap.insert (std::pair<int,char>(1000, 'a'));
  mymap.insert (std::pair<int,char>(400, 'a'));
  mymap.insert (std::pair<int,char>(600, 'a'));
  mymap.insert (std::pair<int,char>(300, 'a'));
  mymap.insert (std::pair<int,char>(350, 'a'));
  mymap.insert (std::pair<int,char>(250, 'a'));
  mymap.insert (std::pair<int,char>(340, 'a'));
  mymap.insert (std::pair<int,char>(360, 'a'));
  mymap.insert (std::pair<int,char>(120, 'a'));
  mymap.insert (std::pair<int,char>(50, 'a'));
  mymap.insert (std::pair<int,char>(1, 'a'));
  mymap.insert (std::pair<int,char>(60, 'a'));
  mymap.insert (std::pair<int,char>(55, 'a'));
  mymap.insert (std::pair<int,char>(65, 'a'));
  mymap.insert (std::pair<int,char>(57, 'a'));
  mymap.insert (std::pair<int,char>(53, 'a'));
  mymap.insert (std::pair<int,char>(54, 'a'));
  mymap.insert (std::pair<int,char>(51, 'a'));


  // showing contents:
  std::cout << "mymap contains:\n";
  for (std::map<int, char>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}