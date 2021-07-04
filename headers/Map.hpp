#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>

#include "RandomAccessIterator.hpp"
#include "RandomAccessReverseIterator.hpp"
#include "utils.hpp"

// !!!!!!!!!!!!!!!!! std::pair change to ft::pair !!!!!!!!!!!


namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair <const Key,T> > >
	class map {
		public:
				typedef 			Key													key_type;
				typedef 			T													mapped_type;
				typedef 			std::pair<const key_type, mapped_type>				value_type;

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
					static_cast<void>(alloc);
					
					// this->_allocator = alloc;
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
			// pair<iterator,bool> insert (const value_type& val) {
			void insert (const value_type& val) {
				static_cast<void>(val);
				if (this->_size == 0) {
					this->_root = new _BinaryTree;
					
					this->_root->value.first = val.first;
					this->_root->value.second = val.second;
					this->_root->lhs = nullptr;
					this->_root->rhs = nullptr;
				}
				else {

				}
				this->_size++;

				std::cout << "Second " << this->_root->value.second << "\n";
			};

			// iterator insert (iterator position, const value_type& val) {

			// };

			// template <class InputIterator>
			// void insert (InputIterator first, InputIterator last) {

			// };


		private:
				typedef struct s {
					value_type	value;
					struct s	*lhs;
					struct s	*rhs;
				}				_BinaryTree;

				allocator_type	_allocator;
				key_compare		_comp;
				size_type		_size;
				_BinaryTree	*	_root;
	};
};

#endif