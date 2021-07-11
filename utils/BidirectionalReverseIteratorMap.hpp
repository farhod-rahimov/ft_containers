#ifndef BIDIRECTIONAL_REVERSE_ITERATOR_MAP_HPP
#define BIDIRECTIONAL_REVERSE_ITERATOR_MAP_HPP

#include "utils.hpp"

namespace ft {

    template < class Key, class T, class Alloc = std::allocator<ft::pair <Key const,T> > >
	class BidirectionalReverseIteratorMap {
	public:
			typedef 			Key													key_type;
			typedef 			T													mapped_type;
			typedef 			ft::pair<key_type const, mapped_type>				value_type;
			typedef 			Alloc												allocator_type;
			typedef typename	allocator_type::pointer								pointer;
			typedef 			std::bidirectional_iterator_tag						iterator_category;

	// ----------------------------------------------------------------------------------------------------------- //

			BidirectionalReverseIteratorMap() {
				this->_binary_tree = nullptr;
			};
			
			virtual ~BidirectionalReverseIteratorMap() {};
			
			BidirectionalReverseIteratorMap(BinaryTree<Key const, T> & src) {
				this->_binary_tree = &src;
			};
			
			BidirectionalReverseIteratorMap(BidirectionalReverseIteratorMap const & src) {
				*this = src;
			};
			
			BidirectionalReverseIteratorMap & operator = (BidirectionalReverseIteratorMap const & src) {
				if (this != &src) {
					this->_binary_tree = src._binary_tree;
                }
				return (*this);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			bool operator == (BidirectionalReverseIteratorMap const & src) const {
				return (this->_binary_tree->_value == src._binary_tree->_value);
			};

			bool operator != (BidirectionalReverseIteratorMap const & src) const {
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

			friend BidirectionalReverseIteratorMap operator ++ (BidirectionalReverseIteratorMap & it) {
				it++;
				return (it);
			};

			BidirectionalReverseIteratorMap & operator ++ (int)
			{
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
				*this = BidirectionalReverseIteratorMap(*tmp);
				return (*this);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			friend BidirectionalReverseIteratorMap operator -- (BidirectionalReverseIteratorMap & it) {
				it--;
				return (it);
			};
			
			BidirectionalReverseIteratorMap & operator -- (int) {
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
				*this = BidirectionalReverseIteratorMap(*tmp);
				return (*this);
			};

	private:
		BinaryTree<Key const, T>		*_binary_tree;
	};

    template < class Key, class T, class Alloc = std::allocator<ft::pair <Key const,T> > >
	class BidirectionalReverseIteratorMapConst {
	public:
			typedef 			Key													key_type;
			typedef 			T													mapped_type;
			typedef 			ft::pair<key_type const, mapped_type>				value_type;
			typedef 			Alloc												allocator_type;
			typedef typename	allocator_type::pointer								pointer;
			typedef 			std::bidirectional_iterator_tag						iterator_category;

	// ----------------------------------------------------------------------------------------------------------- //

			BidirectionalReverseIteratorMapConst() {
				this->_binary_tree = nullptr;
			};
			
			virtual ~BidirectionalReverseIteratorMapConst() {};
			
			BidirectionalReverseIteratorMapConst(BinaryTree<Key const, T> & src) {
				this->_binary_tree = &src;
			};
			
			BidirectionalReverseIteratorMapConst(BidirectionalReverseIteratorMapConst const & src) {
				*this = src;
			};
			
			BidirectionalReverseIteratorMapConst & operator = (BidirectionalReverseIteratorMapConst const & src) {
				if (this != &src) {
					this->_binary_tree = src._binary_tree;
                }
				return (*this);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			bool operator == (BidirectionalReverseIteratorMapConst const & src) const {
				return (this->_binary_tree->_value == src._binary_tree->_value);
			};

			bool operator != (BidirectionalReverseIteratorMapConst const & src) const {
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

			friend BidirectionalReverseIteratorMapConst operator ++ (BidirectionalReverseIteratorMapConst & it) {
				it++;
				return (it);
			};

			BidirectionalReverseIteratorMapConst & operator ++ (int)
			{
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
				*this = BidirectionalReverseIteratorMapConst(*tmp);
				return (*this);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			friend BidirectionalReverseIteratorMapConst operator -- (BidirectionalReverseIteratorMapConst & it) {
				it--;
				return (it);
			};
			
			BidirectionalReverseIteratorMapConst & operator -- (int) {
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
				*this = BidirectionalReverseIteratorMapConst(*tmp);
				return (*this);
			};

	private:
		BinaryTree<Key const, T>		*_binary_tree;
	};
};

#endif