#ifndef VECTOR_HPP
# define VECTOR_HPP

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
					this->_root = nullptr;
				};
				
				// template <class InputIterator>
				// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), 
				// 	const allocator_type& alloc = allocator_type()) {

				// };
				
				// map (const map& x) {

				// };

		// ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS //

			iterator begin() {
				_BinaryTree *tmp = new _BinaryTree(*this->_root);

				while (tmp->lhs) {
					tmp = tmp->lhs;
				}
				return (iterator(tmp->value, tmp->parent));
			};


			iterator end() {
				return (nullptr);
			};

		
		// MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS //
			
				ft::pair<iterator,bool> insert (const value_type& val) {
					if (this->_size == 0) {
						this->_root = new _BinaryTree(val, nullptr);
						this->_size++;
						return (ft::make_pair(&(this->_root->value), true));
					}

					_BinaryTree *tmp = this->_root;

					while (tmp)
					{
						if (this->_comp(val.first, tmp->value.first) && tmp->lhs)
							tmp = tmp->lhs;
						else if (this->_comp(val.first, tmp->value.first) && !tmp->lhs) {
							tmp->lhs = new _BinaryTree(val, tmp);
							tmp = tmp->lhs;
							break ;
						}
						else if (this->_comp(tmp->value.first, val.first) && tmp->rhs)
							tmp = tmp->rhs;
						else if (this->_comp(tmp->value.first, val.first) && !tmp->rhs) {
							tmp->rhs = new _BinaryTree(val, tmp);
							tmp = tmp->rhs;
							break ;
						}
						else
							return (ft::make_pair(&(tmp->value), false));
					}
					this->_size++;
					return (ft::make_pair(&(tmp->value), true));
				};

				iterator insert (iterator position, const value_type& val) {
					static_cast<void>(position);
					return (this->insert(val).first);
				};

				void insert (iterator first, iterator last) {
					while (first != last)
					{
						this->insert(*first++);
					}
				};

		// ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS //

				mapped_type& operator[] (const key_type& k) {
					for (iterator start = this->begin(); start != this->end(); start++) {
						if (start->_binary_tree->value->first == k) {
							return (start->_binary_tree->value->second);
						}
					}
					return (mapped_type());
				};

		private:
				typedef struct _s {
				public:
					_s(value_type const & src, _s * parent) : value(src) {
						this->parent = parent;
						this->lhs = nullptr;
						this->rhs = nullptr;
					};
					_s(_s const & src) {
						if (this != &src) {
							this->parent = src.parent;
							this->lhs = src.lhs;
							this->rhs = src.rhs;
						}
					};
					~_s() {
						delete lhs;
						delete rhs;
					};
					value_type	value;
					struct _s	*parent;
					struct _s	*lhs;
					struct _s	*rhs;
				} 				_BinaryTree;

				allocator_type	_allocator;
				key_compare		_comp;
				size_type		_size;
				_BinaryTree		*_root;
	};
};

#endif