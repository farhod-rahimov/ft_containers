#include <vector>
#include "Vector.hpp"

#include <iostream>
#include <stack>

int main_m ()
{
  std::vector<int> myvector (10);
  std::vector<int>::iterator it;
  
  for (int s = 0; s < 10; s++)
    myvector[s] = s;
    
  std::cout << "size " << myvector.size() << " cap " << myvector.capacity() << std::endl;
  myvector.push_back(123);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::vector<int>::iterator first = myvector.begin() + 4;
  std::vector<int>::iterator last = myvector.end() - 1;


  std::cout << "size " << myvector.size() << " cap " << myvector.capacity() << std::endl;

  std::cout << *myvector.erase(last - 3) << std::endl;
  std::cout << "size " << myvector.size() << " cap " << myvector.capacity() << std::endl;

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
  
  return 0;
}

int main ()
{
    main_m();
    std::cout << "_________________________\n\n";

  Vector<int> myvector (10);
  Vector<int>::iterator it;
  
  for (int s = 0; s < 10; s++)
    myvector[s] = s;
    
  std::cout << "size " << myvector.size() << " cap " << myvector.capacity() << std::endl;
  myvector.push_back(123);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  Vector<int>::iterator first = myvector.begin() + 4;
  Vector<int>::iterator last = myvector.end() - 1;


  std::cout << "size " << myvector.size() << " cap " << myvector.capacity() << std::endl;

  std::cout << *myvector.erase(last - 3) << std::endl;
  std::cout << "size " << myvector.size() << " cap " << myvector.capacity() << std::endl;

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';


  return 0;
}