#include <vector>
#include "Vector.hpp"

#include <iostream>
#include <stack>

#define nl std::cout << std::endl;

int main_m ()
{
  std::vector<int> myvector(3, 100);
  myvector.push_back(101);
  myvector.push_back(102);

  

  std::vector<int> myvector2(myvector.begin(), myvector.end());

  for (int i = 0; i < myvector.size(); i++) {
    std::cout << myvector[i] << " ";
  }
  for (std::vector<int>::iterator start = myvector.begin(); start != myvector.end(); start++) {
    std::cout << *start << " ";
  }

  nl;
  for (std::vector<int>::iterator start = myvector2.begin(); start != myvector2.end(); start++) {
    std::cout << *start << " ";
  }
  nl;

  return 0;
}

int main ()
{
    main_m();
    std::cout << "_________________________\n\n";

  Vector<int> myvector(3, 100);
  myvector.push_back(101);
  myvector.push_back(102);

  

  Vector<int> myvector2(myvector.begin(), myvector.end());

  for (int i = 0; i < myvector.size(); i++) {
    std::cout << myvector[i] << " ";
  }
  for (Vector<int>::iterator start = myvector.begin(); start != myvector.end(); start++) {
    std::cout << *start << " ";
  }

  nl;
  for (Vector<int>::iterator start = myvector2.begin(); start != myvector2.end(); start++) {
    std::cout << *start << " ";
  }
  nl;

  return 0;
}