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
					// this->_root = nullptr;
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
					this->_root = new _BinaryTree(val);
					
					this->_root->lhs = nullptr;
					this->_root->rhs = nullptr;
				}
				else {

				}
				this->_size++;

				std::cout << "First " << this->_root->value.first << "\n";
				std::cout << "Second " << this->_root->value.second << "\n";
			};

			// iterator insert (iterator position, const value_type& val) {

			// };

			// template <class InputIterator>
			// void insert (InputIterator first, InputIterator last) {

			// };


		private:
				class _BinaryTree {
					public:
							_BinaryTree() {};
							
							_BinaryTree(value_type const & src) : value(src) {};
							
							~_BinaryTree() {
								delete lhs;
								delete rhs;
							};
							
							_BinaryTree(_BinaryTree const &src) {
								*this = src;
							};

							_BinaryTree &operator=(_BinaryTree const &src) {
								this->value = src.value;
								this->lhs = src->lhs;
								this->rhs = src->rhs;
							};

							value_type	value;
							_BinaryTree	*lhs;
							_BinaryTree	*rhs;
				};

				allocator_type	_allocator;
				key_compare		_comp;
				size_type		_size;
				_BinaryTree		*_root;
	};
};

#endif