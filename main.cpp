#include <map>
#include <stack>
#include <vector>

#include <iostream>

#include <iterator>
#include <typeinfo>

#include "utils/IteratorTraits.hpp"

#include "headers/Map.hpp"
#include "headers/Stack.hpp"
#include "headers/Vector.hpp"

int main()
{
    std::vector<int>::iterator v_it;
    std::map<int, int>::iterator m_it;

    // typedef std::iterator_traits<std::map<int, int>::iterator> traits;
    // if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
        // std::cout << "int* is a random-access iterator";
    // if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
    //     std::cout << "int* is a random-access iterator";
    // if (typeid(traits::iterator_category)==typeid(std::bidirectional_iterator_tag))
    //     std::cout << "intls;vkvkslmvlksdmvlksdmvlksdmvlksdvmdess iterator";
    
    
    typedef ft::iterator_traits<ft::vector<int>::iterator> ft_traits;
    if (typeid(ft_traits::iterator_category)==typeid(std::random_access_iterator_tag))
        std::cout << "int* is a random-access iterator";
    if (typeid(ft_traits::iterator_category)==typeid(std::bidirectional_iterator_tag))
        std::cout << "intls;vkvkslmvlksdmvlksdmvlksdmvlksdvmdess iterator";
    
    return 0;

}