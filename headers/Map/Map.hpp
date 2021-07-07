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
				
				typedef 			ft::BidirectionalIteratorMap<value_type>			iterator;
				typedef 			ft::BidirectionalIteratorMap<value_type const>		const_iterator;
				typedef 			ft::BidirectionalIteratorMap<value_type>			reverse_iterator;
				typedef 			ft::BidirectionalIteratorMap<value_type const>		const_reverse_iterator;

				typedef 			std::ptrdiff_t										difference_type;
				typedef 			size_t												size_type;

		// INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION  //
				
				explicit map (const key_compare& comp = key_compare(), 
							const allocator_type& alloc = allocator_type()) {
					this->_allocator = alloc;
					this->_comp = comp;
					this->_size = 0;
					this->_root = new BinaryTree<value_type>;
					this->_root->_value->first = key_type();
					this->_root->_value->second = mapped_type();
				};

		// ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS //

				iterator begin() {
					BinaryTree<value_type> *tmp = this->_root;

					while (tmp && tmp->_lh && this->_comp(tmp->_lh->_value->first, tmp->_value->first)) {
						tmp = tmp->_lh;
					}
					return (iterator(tmp->_value, tmp->_parent));
				};

				iterator end() {
					BinaryTree<value_type> *tmp = this->_root;

					while (tmp && tmp->_rh && this->_comp(tmp->_value->first, tmp->_rh->_value->first)) {
						tmp = tmp->_rh;
					}
					return (iterator(tmp->_value, tmp->_parent));
				};

		// MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS //

				pair<iterator,bool> insert (const value_type& val) {
					if (this->_size == 0) {
						this->_root = new BinaryTree<value_type>(val, nullptr);
						this->_size += 1;
						return (ft::make_pair(this->_root->_value, true));
					}

					// std::cout << this->_root->_value->first << std::endl;
					// std::cout << this->_root->_value->second << std::endl;
					
					BinaryTree<value_type> *tmp = this->_root;

					while (tmp) {
						if (this->_comp(val.first, tmp->_value->first) && tmp->_lh)
							tmp = tmp->_lh;
						else if (this->_comp(val.first, tmp->_value->first) && !tmp->_lh) {
							tmp->_lh = new BinaryTree<value_type>(val, tmp);
							tmp = tmp->_lh;
							break;
						}
						else if (this->_comp(tmp->_value->first, val.first) && tmp->_rh)
							tmp = tmp->_rh;
						else if (this->_comp(tmp->_value->first, val.first) && !tmp->_rh) {
							tmp->_rh = new BinaryTree<value_type>(val, tmp);
							tmp = tmp->_rh;
							break;
						}
						else
							return (ft::make_pair(tmp->_value, false));
					}
					this->_size += 1;
					return (ft::make_pair(tmp->_value, true));
				};

				// iterator insert (iterator position, const value_type& val) {

				// };

				// void insert (iterator first, iterator last) {

				// };

		// ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS //

				mapped_type& operator[] (const key_type& k) {
					iterator start = this->begin();
					// std::cout << this->_root->_value->second << std::endl;
					// std::cout << this->_root->_value->first << std::endl;

					for ( ; start != this->end(); start++) {
						if (start->first == k) {
							break ;
						}
					}
					return (start->second);
				};


	private:
				allocator_type	        				_allocator;
				key_compare		        				_comp;
				size_type		        				_size;
				BinaryTree<value_type>					*_root;
	};

};

#endif