#include <vector>
#include "Vector.hpp"

#include <iostream>


// int main_m ()
// {
//     std::vector<int> a;

//     a.push_back(1);
//     a.push_back(2);

//     std::vector<int>::iterator it1 = a.begin();
//     std::vector<int>::iterator it1 = a.begin();
//     std::cout << *it1 << " " << *it2 << "\n";
//     *it1 = 21;

//     std::cout << &it1 << " " << &it2 << "\n";
//     std::cout << *it1 << " " << *it2 << "\n";

//     if (it1 == it2) std::cout << "YES\n"; else std::cout << "NO\n";

//   return 0;
// }

int main_m ()
{
    std::vector<int> a;
    a.push_back(1);
    a.push_back(2);

    std::vector<int>::iterator it1 = a.begin();
    std::vector<int>::iterator it2 = it1;

    std::cout << &it1 << " " << &it2 << std::endl;
    it1++;
    std::cout << *it1 << " " << *it2 << std::endl;

    return (0);
}

int main ()
{
    main_m();

    std::cout << "_________________________\n\n";

    Vector<int>::iterator it1;
    Vector<int>::iterator it2 = it1;
    
    // if (it1 == it2) std::cout << "YES\n"; else std::cout << "NO\n";
    // if (it1 != it2) std::cout << "YES\n"; else std::cout << "NO\n";



    std::cout << *it1 << " " << &it2 << std::endl;
    it1++;
    std::cout << *it1 << " " << &it2 << std::endl;
}