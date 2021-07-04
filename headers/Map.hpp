#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>

#include "RandomAccessIterator.hpp"
#include "RandomAccessReverseIterator.hpp"
#include "utils.hpp"

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair <const Key,T> > >
	class map {
		public:
				typedef 			Key													key_type;
				typedef 			T													mapped_type;
				typedef 			ft::pair<const key_type, mapped_type>				value_type;

				typedef 			Compare												key_compare;
				// typedef 			ft::map::value_comp									value_compare;
				
				typedef 			Alloc 												allocator_type;
				typedef typename	allocator_type::reference 							reference;
				typedef typename	allocator_type::const_reference 					const_reference;
				typedef typename	allocator_type::pointer 							pointer;
				typedef typename	allocator_type::const_pointer 						const_pointer;
				
				typedef 			ft::RandomAccessIterator<value_type>				iterator;
				typedef 			ft::RandomAccessIterator<value_type const>			const_iterator;
				typedef 			ft::RandomAccessReverseIterator<value_type>			reverse_iterator;
				typedef 			ft::RandomAccessReverseIterator<value_type const>	const_reverse_iterator;

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
		
		// MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS //
			
			ft::pair<iterator,bool> insert (const value_type& val) {
				if (this->_size == 0) {
					this->_root = new _BinaryTree(val);
					this->_size++;
					return (ft::make_pair(&(this->_root->value), true));
				}

				_BinaryTree *tmp = this->_root;

				while (tmp)
				{
					if (this->_comp(val.first, tmp->value.first) && tmp->lhs)
						tmp = tmp->lhs;
					else if (this->_comp(val.first, tmp->value.first) && !tmp->lhs) {
						tmp->lhs = new _BinaryTree(val);
						tmp = tmp->lhs;
						break ;
					}
					else if (this->_comp(tmp->value.first, val.first) && tmp->rhs)
						tmp = tmp->rhs;
					else if (this->_comp(tmp->value.first, val.first) && !tmp->rhs) {
						tmp->rhs = new _BinaryTree(val);
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
					std::cout << "First " << first->first << " second " << first->second << std::endl;
					first++;
					std::cout << "First " << first->first << " second " << first->second << std::endl;
					break ;
				}
			};

		private:
				typedef struct _s {
				public:
					_s(value_type const & src) : value(src) {
						this->lhs = nullptr;
						this->rhs = nullptr;
					};
					~_s() {
						delete lhs;
						delete rhs;
					};
					value_type	value;
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