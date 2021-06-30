#include <vector>
// #include "Vector_old.hpp"
#include "Vector.hpp"

#include <iostream>
#include <stack>


int main_m ()
{
  std::vector<int>::size_type sz;

  std::vector<int> foo;
  foo.push_back(0);
  foo.push_back(1);
  foo.push_back(2);
  foo.push_back(3);
  foo.push_back(4);
  foo.push_back(5);

  std::cout << foo.front() << std::endl;
  std::cout << foo.back() << std::endl;
  return 0;
}

int main ()
{
    main_m();

    std::cout << "_________________________\n\n";
 
  vector<int> foo;
  foo.push_back(0);
  foo.push_back(1);
  foo.push_back(2);
  foo.push_back(3);
  foo.push_back(4);
  foo.push_back(5);

  std::cout << foo.front() << std::endl;
  std::cout << foo.back() << std::endl;
 
  return 0;
}