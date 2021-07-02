#include <vector>
// #include "Vector_old.hpp"
#include "Vector.hpp"

#include <iostream>
#include <stack>


int main_m ()
{
  std::vector<int>::size_type sz;

  std::vector<int> bar;
  bar.push_back(0);
  bar.push_back(1);
  bar.push_back(2);
  bar.push_back(3);
  bar.push_back(4);
  bar.push_back(5);

  std::vector<int> foo;
  foo.push_back(1019);
  foo.push_back(2019);
  foo.push_back(3019);

  std::cout << "size = " << foo.size() << " capacity = " << foo.capacity() << std::endl;

  // foo.insert(foo.begin() + 1, 0, 54);
  foo.insert(foo.begin() + 1, bar.begin(), bar.end());

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
 
  vector<int> bar;
  bar.push_back(0);
  bar.push_back(1);
  bar.push_back(2);
  bar.push_back(3);
  bar.push_back(4);
  bar.push_back(5);

  vector<int> foo;
  foo.push_back(1019);
  foo.push_back(2019);
  foo.push_back(3019);

  std::cout << "size = " << foo.size() << " capacity = " << foo.capacity() << std::endl;

  // foo.insert(foo.begin() + 1, 0, 54);
  foo.insert(foo.begin() + 1, bar.begin(), bar.end());

  std::cout << "my vector contains: " << std::endl;
  for (vector<int>::iterator it = foo.begin(); it != foo.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << "size = " << foo.size() << " capacity = " << foo.capacity() << std::endl;
  
  // while (1) ;
  return 0;
}