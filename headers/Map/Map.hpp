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
				
				typedef 			ft::BidirectionalIteratorMap<Key, T>				iterator;
				typedef 			ft::BidirectionalIteratorMap<Key, T const>			const_iterator;
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
					this->_root = new BinaryTree<key_type, mapped_type>;
					this->_root->setLastElementFlag();
					this->_root->_lh = this->_root->createFirstElemet(this->_root);
				};

				map (iterator first, iterator last, const key_compare& comp = key_compare(), 
						const allocator_type& alloc = allocator_type()) {
					this->_allocator = alloc;
					this->_comp = comp;
					this->_size = 0;
					this->_root = new BinaryTree<key_type, mapped_type>;
					this->_root->setLastElementFlag();
					this->_root->_lh = this->_root->createFirstElemet(this->_root);
					
					for (; first != last; first++) {
						this->insert(*first);
					}
				};
				
				map (const map & src) {
					this->_root = nullptr;
					*this = src;
				};
			
				map & operator = (const map & src) {
				if (this != &src) {
					if (this->_root != nullptr)
						delete this->_root;
					this->_allocator = src._allocator;
					this->_comp = src._comp;
					this->_size = 0;
					this->_root = new BinaryTree<key_type, mapped_type>;
					this->_root->setLastElementFlag();
					this->_root->_lh = this->_root->createFirstElemet(this->_root);
					
					for (iterator it = src.begin(); it != src.end(); it++) {
						this->insert(*it);
					}
				}
				return (*this);
			};

		// ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS //
				
				iterator begin() const {
					BinaryTree<key_type, mapped_type> *tmp = this->_root;

					while (tmp && tmp->_lh && !tmp->_lh->isFirstElement()) {
						tmp = tmp->_lh;
					}
					return (iterator(*tmp));
				};

				iterator end() const {
					BinaryTree<key_type, mapped_type> *tmp = this->_root;

					while (!tmp->isLastElement()) {
						tmp = tmp->_rh;
					}
					return (iterator(*tmp));
				};

		// MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS //
				
				ft::pair<iterator,bool> insert (const value_type& val) {
					if (this->_size == 0) {
						this->_root->_value->first = val.first;
						this->_root->_value->second = val.second;
						this->_root->removeLastElementFlag();
						this->_root->_rh = this->_root->createLastElemet(this->_root);
						this->_root->_lh = this->_root->createFirstElemet(this->_root);
						this->_size++;
						return (ft::make_pair<iterator, bool>((*this->_root), true));
					}

					BinaryTree<key_type, mapped_type> *tmp = this->_root;

					while (tmp) {
						if (this->_comp(val.first, tmp->_value->first) && tmp->_lh && !tmp->_lh->isFirstElement()) {
							tmp = tmp->_lh;
						}
						else if (this->_comp(val.first, tmp->_value->first) && tmp->_lh && tmp->_lh->isFirstElement()) {
							tmp->_lh->removeFirstElementFlag();
							tmp->_lh->_value->first = val.first;
							tmp->_lh->_value->second = val.second;
							tmp->_lh->_lh = tmp->createFirstElemet(tmp->_lh);
							break ;
						}
						else if (this->_comp(val.first, tmp->_value->first) && !tmp->_lh) {
							tmp->_lh = new BinaryTree<key_type, mapped_type>(val, tmp);
							break ;
						}
						else if (this->_comp(tmp->_value->first, val.first) && tmp->_rh && !tmp->_rh->isLastElement()) {
							tmp = tmp->_rh;
						}
						else if (this->_comp(tmp->_value->first, val.first) && tmp->_rh && tmp->_rh->isLastElement()) {
							tmp->_rh->removeLastElementFlag();
							tmp->_rh->_value->first = val.first;
							tmp->_rh->_value->second = val.second;
							tmp->_rh->_rh = tmp->createLastElemet(tmp->_rh);
							break ;
						}
						else if (this->_comp(tmp->_value->first, val.first) && !tmp->_rh ) {
							tmp->_rh = new BinaryTree<key_type, mapped_type>(val, tmp);
							break ;
						}
						else {
							return (ft::make_pair<iterator, bool>(*tmp, false));
						}
					}
					this->_size++;
					return (ft::make_pair<iterator, bool>(*tmp, true));
				};

	private:
				allocator_type	        				_allocator;
				key_compare		        				_comp;
				size_type		        				_size;
				BinaryTree<key_type, mapped_type>		*_root;
	};
};

#endif