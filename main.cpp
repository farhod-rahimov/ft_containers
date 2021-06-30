#include <vector>
#include "Vector_old.hpp"

#include <iostream>
#include <stack>


int main_m ()
{
    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(-3);
    v.push_back(4);

    // Vector<int>::iterator it(v.begin());
    std::vector<int>::iterator it = v.begin();
    std::vector<int>::iterator ite = v.end();
    it[0] = 25;
    std::cout << it[3] << std::endl;
  return 0;
}

int main ()
{
    main_m();
    std::cout << "_________________________\n\n";

    Vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(-3);
    v.push_back(4);

    // Vector<int>::iterator it(v.begin());
    Vector<int>::iterator it = v.begin();
    Vector<int>::iterator ite = v.end();

    it[0] = 25;
    std::cout << it[3] << std::endl;


  return 0;
}