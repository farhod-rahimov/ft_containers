#include <iostream>
#include "Map.hpp"
#include "utils.hpp"
#include "BidirectionalIteratorMap.hpp"

#include <map>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

void constructor() {
  std::map<char,int> first;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;

  std::map<char,int> second (first.begin(),first.end());

  std::map<char,int> third (second);

  std::map<char,int,classcomp> fourth;                 // class as Compare

  bool(*fn_pt)(char,char) = fncomp;
  std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

  for (std::map<char, int>::iterator it = first.begin(); it != first.end(); it++) {
    std::cout << it->first << std::endl;
  }
  std::cout << "-------------\n";
   for (std::map<char, int>::iterator it = second.begin(); it != second.end(); it++) {
    std::cout << it->first << std::endl;
  }
  std::cout << "-------------\n";
   for (std::map<char, int>::iterator it = third.begin(); it != third.end(); it++) {
    std::cout << it->first << std::endl;
  }
  std::cout << "-------------\n";
   for (std::map<char, int>::iterator it = fourth.begin(); it != fourth.end(); it++) {
    std::cout << it->first << std::endl;
  }
}

void operator_eq() {
  std::map<char,int> first;
  std::map<char,int> second;

  first['x']=8;
  first['y']=16;
  first['z']=32;

  second=first;                // second now contains 3 ints
  first=std::map<char,int>();  // and first is now empty

  std::cout << "Size of first: " << first.size() << '\n';
  std::cout << "Size of second: " << second.size() << '\n';
}

void begin() {
  std::map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

void rbegin() {
  std::map<char,int> mymap;

  mymap['x'] = 100;
  mymap['y'] = 200;
  mymap['z'] = 300;

  // show content:
  std::map<char,int>::reverse_iterator rit;
  for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
    std::cout << rit->first << " => " << rit->second << '\n';
}

int main ()
{
  // constructor();
  // operator_eq();
  // begin();
  rbegin();
  // while (1)
  //   ;
  return 0;
}