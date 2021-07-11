#ifndef BIDIRECTIONAL_ITERATOR_MAP_HPP
#define BIDIRECTIONAL_ITERATOR_MAP_HPP

#include "utils.hpp"

namespace ft {

    template < class Key, class T, class Alloc = std::allocator<ft::pair <Key const, T> > >
	class BidirectionalIteratorMap {
	public:
			typedef 			std::ptrdiff_t										difference_type;
			typedef 			Key													key_type;
			typedef 			T													mapped_type;
			typedef 			ft::pair<key_type const, mapped_type>				value_type;
			typedef 			Alloc												allocator_type;
			typedef typename	allocator_type::pointer								pointer;
			typedef typename	allocator_type::reference							reference;
			typedef 			std::bidirectional_iterator_tag         			iterator_category;

	// ----------------------------------------------------------------------------------------------------------- //

			BidirectionalIteratorMap() {
				this->_binary_tree = nullptr;
			};
			
			virtual ~BidirectionalIteratorMap() {};
			
			BidirectionalIteratorMap(BinaryTree<Key const, T> & src) {
				this->_binary_tree = &src;
			};
			
			BidirectionalIteratorMap(BidirectionalIteratorMap const & src) {
				*this = src;
			};
			
			BidirectionalIteratorMap & operator = (BidirectionalIteratorMap const & src) {
				if (this != &src) {
					this->_binary_tree = src._binary_tree;
                }
				return (*this);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			bool operator == (BidirectionalIteratorMap const & src) const {
				return (this->_binary_tree->_value == src._binary_tree->_value);
			};

			bool operator != (BidirectionalIteratorMap const & src) const {
				return (this->_binary_tree->_value != src._binary_tree->_value);
			};

	// ----------------------------------------------------------------------------------------------------------- //
			
			value_type & operator * (void) {
				return(*this->_binary_tree->_value);
			};

			value_type *operator -> (void) {
				return(this->_binary_tree->_value);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			friend BidirectionalIteratorMap operator ++ (BidirectionalIteratorMap & it) {
				it++;
				return (it);
			};

			BidirectionalIteratorMap & operator ++ (int)
			{
				BinaryTree<Key const, T> *tmp(this->_binary_tree);

				if (tmp->isLastElement()) {
					return (*this);
				}
				else if (tmp->_rh && !tmp->_rh->isLastElement()) {
					tmp = tmp->_rh;
					while (tmp->_lh && !tmp->_lh->isFirstElement()) {
						tmp = tmp->_lh;
					}
				}
				else if (tmp->isFirstElement()) {
					if (tmp->_rh->isLastElement())
						tmp = tmp->_rh;
					else
						tmp = tmp->_parent;
				}
				else {
					while (	tmp->_value->first <= this->_binary_tree->_value->first && 
							tmp->_parent && !tmp->_parent->isFirstElement() && 
							!tmp->_parent->isLastElement()) {
						tmp = tmp->_parent;
					}
					if (tmp->_value->first <= this->_binary_tree->_value->first) {
						while (tmp->_parent != nullptr) {
							tmp = tmp->_parent;
						}
						while (!tmp->isLastElement()) {
							tmp = tmp->_rh;
						}
					}
				}
				*this = BidirectionalIteratorMap(*tmp);
				return (*this);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			friend BidirectionalIteratorMap operator -- (BidirectionalIteratorMap & it) {
				it--;
				return (it);
			};
			
			BidirectionalIteratorMap & operator -- (int) {
				BinaryTree<Key const, T> *tmp(this->_binary_tree);


				if (tmp->isFirstElement()) {
					return (*this);
				}
				else if (tmp->_lh && !tmp->_lh->isFirstElement()) {
					tmp = tmp->_lh;
					while (tmp->_rh && !tmp->_rh->isLastElement()) {
						tmp = tmp->_rh;
					}
				}
				else if (tmp->isLastElement()) {
					tmp = tmp->_parent;
				}
				else {
					while (	tmp->_value->first >= this->_binary_tree->_value->first && 
							tmp->_parent && !tmp->_parent->isLastElement() && 
							!tmp->_parent->isFirstElement()) {
						tmp = tmp->_parent;
					}
					if (tmp->_value->first >= this->_binary_tree->_value->first) {
						while (tmp->_parent != nullptr) {
							tmp = tmp->_parent;
						}
						while (!tmp->isFirstElement()) {
							tmp = tmp->_lh;
						}
					}
				}
				*this = BidirectionalIteratorMap(*tmp);
				return (*this);
			};

	private:
		BinaryTree<Key const, T>		*_binary_tree;
	};

    template < class Key, class T, class Alloc = std::allocator<ft::pair <Key const,T> > >
	class BidirectionalIteratorMapConst {
	public:

			typedef 			std::ptrdiff_t										difference_type;
			typedef 			Key													key_type;
			typedef 			T													mapped_type;
			typedef 			ft::pair<key_type const, mapped_type>				value_type;
			typedef 			Alloc												allocator_type;
			typedef typename	allocator_type::pointer								pointer;
			typedef typename	allocator_type::reference							reference;
			typedef 			std::bidirectional_iterator_tag         			iterator_category;

	// ----------------------------------------------------------------------------------------------------------- //

			BidirectionalIteratorMapConst() {
				this->_binary_tree = nullptr;
			};
			
			virtual ~BidirectionalIteratorMapConst() {};
			
			BidirectionalIteratorMapConst(BinaryTree<Key const, T> & src) {
				this->_binary_tree = &src;
			};
			
			BidirectionalIteratorMapConst(BidirectionalIteratorMapConst const & src) {
				*this = src;
			};
			
			BidirectionalIteratorMapConst & operator = (BidirectionalIteratorMapConst const & src) {
				if (this != &src) {
					this->_binary_tree = src._binary_tree;
                }
				return (*this);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			bool operator == (BidirectionalIteratorMapConst const & src) const {
				return (this->_binary_tree->_value == src._binary_tree->_value);
			};

			bool operator != (BidirectionalIteratorMapConst const & src) const {
				return (this->_binary_tree->_value != src._binary_tree->_value);
			};

	// ----------------------------------------------------------------------------------------------------------- //
			
			value_type & operator * (void) {
				return(*this->_binary_tree->_value);
			};

			value_type *operator -> (void) {
				return(this->_binary_tree->_value);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			friend BidirectionalIteratorMapConst operator ++ (BidirectionalIteratorMapConst & it) {
				it++;
				return (it);
			};

			BidirectionalIteratorMapConst & operator ++ (int)
			{
				BinaryTree<Key const, T> *tmp(this->_binary_tree);

				if (tmp->isLastElement()) {
					return (*this);
				}
				else if (tmp->_rh && !tmp->_rh->isLastElement()) {
					tmp = tmp->_rh;
					while (tmp->_lh && !tmp->_lh->isFirstElement()) {
						tmp = tmp->_lh;
					}
				}
				else if (tmp->isFirstElement()) {
					if (tmp->_rh->isLastElement())
						tmp = tmp->_rh;
					else
						tmp = tmp->_parent;
				}
				else {
					while (	tmp->_value->first <= this->_binary_tree->_value->first && 
							tmp->_parent && !tmp->_parent->isFirstElement() && 
							!tmp->_parent->isLastElement()) {
						tmp = tmp->_parent;
					}
					if (tmp->_value->first <= this->_binary_tree->_value->first) {
						while (tmp->_parent != nullptr) {
							tmp = tmp->_parent;
						}
						while (!tmp->isLastElement()) {
							tmp = tmp->_rh;
						}
					}
				}
				*this = BidirectionalIteratorMapConst(*tmp);
				return (*this);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			friend BidirectionalIteratorMapConst operator -- (BidirectionalIteratorMapConst & it) {
				it--;
				return (it);
			};
			
			BidirectionalIteratorMapConst & operator -- (int) {
				BinaryTree<Key const, T> *tmp(this->_binary_tree);


				if (tmp->isFirstElement()) {
					return (*this);
				}
				else if (tmp->_lh && !tmp->_lh->isFirstElement()) {
					tmp = tmp->_lh;
					while (tmp->_rh && !tmp->_rh->isLastElement()) {
						tmp = tmp->_rh;
					}
				}
				else if (tmp->isLastElement()) {
					tmp = tmp->_parent;
				}
				else {
					while (	tmp->_value->first >= this->_binary_tree->_value->first && 
							tmp->_parent && !tmp->_parent->isLastElement() && 
							!tmp->_parent->isFirstElement()) {
						tmp = tmp->_parent;
					}
					if (tmp->_value->first >= this->_binary_tree->_value->first) {
						while (tmp->_parent != nullptr) {
							tmp = tmp->_parent;
						}
						while (!tmp->isFirstElement()) {
							tmp = tmp->_lh;
						}
					}
				}
				*this = BidirectionalIteratorMapConst(*tmp);
				return (*this);
			};

	private:
		BinaryTree<Key const, T>		*_binary_tree;
	};
};

#endif