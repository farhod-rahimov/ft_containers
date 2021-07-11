#include "../headers/Map.hpp"
#include "../headers/Stack.hpp"
#include "../headers/Vector.hpp"

#include <iostream>
#include <typeinfo>
#include "../utils/IteratorTraits.hpp"

void iterator_traits()
{
    typedef ft::iterator_traits<ft::vector<int>::iterator> ft_traits_vector;
    typedef ft::iterator_traits<ft::map<int, int>::iterator> ft_traits_map;

    if (typeid(ft_traits_vector::iterator_category)==typeid(std::random_access_iterator_tag))
        std::cout << "Yes, ft::vector's iterator type is RANDOM_ACCESS_ITERATOR\n";
    
    if (typeid(ft_traits_map::iterator_category)==typeid(std::bidirectional_iterator_tag))
        std::cout << "Yes, ft::map's iterator type is BIDIRECTIONAL_ITERATOR\n";
}

int main()
{
    std::cout << "The output should be\nYes, ft::vector's iterator type is RANDOM_ACCESS_ITERATOR\n";
    std::cout << "Yes, ft::map's iterator type is BIDIRECTIONAL_ITERATOR\n";
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "My output\n";
    iterator_traits();
}
