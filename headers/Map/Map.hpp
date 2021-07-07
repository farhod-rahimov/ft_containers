#ifndef MAP_HPP
# define  MAP_HPP

#include <memory>

#include "BidirectionalIteratorMap.hpp"
#include "utils.hpp"

namespace ft {
    // template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair <const Key,T> > >
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair <Key,T> > >
    class map {
	public:
				typedef 			Key													key_type;
				typedef 			T													mapped_type;
				typedef 			ft::pair<key_type, mapped_type>						value_type;
				// typedef 			ft::pair<const key_type, mapped_type>				value_type;

				typedef 			Compare												key_compare;
				// typedef 			ft::map::value_comp									value_compare;
				
				typedef 			Alloc 												allocator_type;
				typedef typename	allocator_type::reference 							reference;
				typedef typename	allocator_type::const_reference 					const_reference;
				typedef typename	allocator_type::pointer 							pointer;
				typedef typename	allocator_type::const_pointer 						const_pointer;
				
				// typedef 			ft::BidirectionalIteratorMap<value_type>			iterator;
				// typedef 			ft::BidirectionalIteratorMap<value_type const>		const_iterator;
				// typedef 			ft::BidirectionalIteratorMap<value_type>			reverse_iterator;
				// typedef 			ft::BidirectionalIteratorMap<value_type const>		const_reverse_iterator;

				typedef 			std::ptrdiff_t										difference_type;
				typedef 			size_t												size_type;

        // INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION  //
				
				explicit map (const key_compare& comp = key_compare(), 
							const allocator_type& alloc = allocator_type()) {
					this->_allocator = alloc;
					this->_comp = comp;
					this->_size = 0;
					this->_root = new BinaryTree<value_type>;
                    this->_root->setLastElementFlag();
				};

		// MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS //

    
    private:
                allocator_type	        				_allocator;
				key_compare		        				_comp;
				size_type		        				_size;
				BinaryTree<value_type>					*_root;
    };
};

#endif