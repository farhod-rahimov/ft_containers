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

  std::cout << "size = " << foo.size() << " capacity = " << foo.capacity() << std::endl;

  std::cout << *(foo.erase(foo.begin() + 1), foo.end() - 2) << std::endl;

  std::cout << "my vector contains: " << std::endl;
  for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << "size = " << foo.size() << " capacity = " << foo.capacity() << std::endl;
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

  std::cout << "size = " << foo.size() << " capacity = " << foo.capacity() << std::endl;

  std::cout << *(foo.erase(foo.begin() + 1), foo.end() - 2) << std::endl;

  std::cout << "my vector contains: " << std::endl;
  for (vector<int>::iterator it = foo.begin(); it != foo.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << "size = " << foo.size() << " capacity = " << foo.capacity() << std::endl;
  
  // while (1) ;
  return 0;
}