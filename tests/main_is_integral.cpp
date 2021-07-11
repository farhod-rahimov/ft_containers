#include <iostream>

#include "../utils/IsIntegral.hpp"

int main() {
  std::cout << "The output should be\nis_integral:\nchar: true\nint: true\nfloat: false\n";
  std::cout << "--------------------------------------------------------------------\n";
  std::cout << "My output\n";
  std::cout << std::boolalpha;
  std::cout << "is_integral:" << std::endl;
  std::cout << "char: " << ft::is_integral<char>::value << std::endl;
  std::cout << "int: " << ft::is_integral<int>::value << std::endl;
  std::cout << "float: " << ft::is_integral<float>::value << std::endl;
}