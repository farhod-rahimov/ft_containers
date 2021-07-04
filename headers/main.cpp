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
  std::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( std::pair<char,int>('a',100) );
  mymap.insert ( std::pair<char,int>('z',200) );

  std::pair<std::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( std::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }

  // second insert function version (with hint position):
  std::map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
  mymap.insert (it, std::pair<char,int>('g',400));  // no max efficiency inserting
  mymap.insert (it, std::pair<char,int>('f',400));  // no max efficiency inserting
  mymap.insert (it, std::pair<char,int>('h',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  std::map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('f'));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

it = anothermap.begin();
++it;
  std::cout << it->first;

  return 0;
}