#ifndef BIDIRECTIONAL_ITERATOR_MAP_HPP
#define BIDIRECTIONAL_ITERATOR_MAP_HPP

#include "utils.hpp"
#include "Map.hpp"

// #include "../Stack.hpp"
// #include "../Vector.hpp"

namespace ft {

	template < class Key, class T >
	class BidirectionalIteratorMap {
	public:
			typedef 	Key										key_type;
			typedef 	T										mapped_type;
			typedef 	ft::pair<key_type, mapped_type>			value_type;
			typedef 	value_type *							pointer;
			typedef 	std::bidirectional_iterator_tag         iterator_category;

	// ----------------------------------------------------------------------------------------------------------- //

			BidirectionalIteratorMap() {
				this->_binary_tree = nullptr;
			};
			
			virtual ~BidirectionalIteratorMap() {};
			
			BidirectionalIteratorMap(BinaryTree<Key, T> & src) {
				this->_binary_tree = new BinaryTree<Key, T>(src);
			};
			
			BidirectionalIteratorMap(BidirectionalIteratorMap const & src) {
				*this = src;
			};
			
			BidirectionalIteratorMap & operator = (BidirectionalIteratorMap const & src) {
				if (this != &src) {
					if (this->_binary_tree != nullptr) {
						// delete this->_binary_tree; // sega
					}
					this->_binary_tree = new BinaryTree<Key, T>(*src._binary_tree);
                }
				return (*this);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			bool operator == (BidirectionalIteratorMap const & src) const {
				// return (this->_binary_tree->_value->first == src._binary_tree->_value->first);
				return (this->_binary_tree->_value == src._binary_tree->_value);
			};

			bool operator != (BidirectionalIteratorMap const & src) const {
				// return (this->_binary_tree->_value->first != src._binary_tree->_value->first);
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
				BinaryTree<Key, T> *tmp(this->_binary_tree);

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
				BinaryTree<Key, T> *tmp(this->_binary_tree);


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
		// friend void ft::map<Key, T>::erase(typename ft::map<Key, T>::iterator position);
		BinaryTree<Key, T>		*_binary_tree;
	};
};

#endif