#include <iostream>

#include "../utils/EnableIf.hpp"
#include "../utils/IsIntegral.hpp"

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename ft::enable_if<ft::is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}

// 2. the second template argument is only valid if T is an integral type:
template < class T>
typename ft::enable_if<ft::is_integral<T>::value,bool>::type
    is_even (T i) {return !bool(i%2);}

int main() {

  short int i = 1;    // code does not compile if type of i is not integral

  std::cout << "The output should be\ni is odd: true\ni is even: false\n";
  std::cout << "--------------------------------------------------------------------\n";
  std::cout << "My output\n";
  std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(i) << std::endl;
  std::cout << "i is even: " << is_even(i) << std::endl;
//   std::cout << "i is odd: " << is_odd(1.25) << std::endl;             // error while compiling
//   std::cout << "i is even: " << is_even(2.25) << std::endl;           // error while compiling

  return 0;
}
