#include <vector>
// #include "Vector_old.hpp"
#include "Vector.hpp"

#include <iostream>
#include <stack>


int main_m ()
{
  std::vector<int> myvector (5);  // 5 default-constructed ints

  int i=0;

  std::vector<int>::reverse_iterator rit = myvector.rbegin();
  for (; rit!= myvector.rend(); ++rit)
    *rit = ++i;

  std::cout << "rbegin = " << *(rit = myvector.rbegin()) << std::endl;
  std::cout << "rend = " << *(rit = myvector.rend()) << std::endl;
  
  bool ret = myvector.rbegin() > myvector.rend();
  std::cout << "bool " << ret << std::endl;
  
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

int main ()
{
    main_m();

    std::cout << "_________________________\n\n";
 
  ft::vector<int> myvector (5);  // 5 default-constructed ints

  int i=0;

  ft::vector<int>::reverse_iterator rit = myvector.rbegin();
  for (; rit!= myvector.rend(); ++rit)
    *rit = ++i;
  
  std::cout << "rbegin = " << *(rit = myvector.rbegin()) << std::endl;
  std::cout << "rend = " << *(rit = myvector.rend()) << std::endl;

  bool ret = myvector.rbegin() > myvector.rend();
  std::cout << "bool " << ret << std::endl;

  std::cout << "myvector contains:";
  for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}