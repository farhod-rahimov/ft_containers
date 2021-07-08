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
  ft::map<int,int> mymap;

  mymap[1]=1;
  mymap[2]=2;
  mymap[3]=3;
  mymap[4]=4;
  mymap[5]=5;
  mymap[6]=6;
  mymap[7]=7;
  mymap[8]=8;
  mymap[9]=9;
  mymap[10]=10;
  mymap[11]=11;
  mymap[12]=12;
  mymap[13]=13;
  mymap[14]=14;
  mymap[15]=15;
  mymap[16]=16;
  mymap[17]=17;
  mymap[18]=18;
  mymap[19]=19;
  mymap[20]=20;
  mymap[21]=21;
  mymap[22]=22;
  mymap[23]=23;
  mymap[24]=24;
  mymap[25]=25;
  mymap[26]=26;
  mymap[27]=27;
  mymap[28]=28;
  mymap[29]=29;
  mymap[30]=30;

  ft::map<int, int>::iterator it = mymap.begin();
  for (int i = 0; i < 0; i++)
    it++;

  std::cout << "searching for " << it->first << " before erasing" << std::endl;
  std::cout << mymap.find(it->first)->first << std::endl;
  mymap.erase(it);
  std::cout << "searching for " << it->first << " after erasing" << std::endl;
  std::cout << mymap.find(it->first)->first << std::endl;

  return 0;
}