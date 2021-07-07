#ifndef BIDIRECTIONAL_ITERATOR_MAP_HPP
#define BIDIRECTIONAL_ITERATOR_MAP_HPP

#include "utils.hpp"

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
						delete this->_binary_tree;
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

			// friend BidirectionalIteratorMap operator ++ (BidirectionalIteratorMap & it) {
			// 	it++;
			// 	return (it);
			// };

			// BidirectionalIteratorMap & operator ++ (int)
			// {
			// 	BidirectionalIteratorMap *tmp(this);

			// 	if (tmp->_binary_tree->_rh) {
			// 		tmp->_binary_tree = tmp->_binary_tree->_rh;
			// 		while (tmp->_binary_tree->_lh) {
			// 			tmp->_binary_tree = tmp->_binary_tree->_lh;
			// 		}
			// 	}
			// 	else {
			// 		while (tmp->_binary_tree->_value <= this->_binary_tree->_value && tmp->_binary_tree->_parent) {
			// 			tmp->_binary_tree = tmp->_binary_tree->_parent;
			// 		}
			// 		// if (tmp->_binary_tree->_value <= this->_binary_tree->_value)
			// 		// 	return (tmp->_binary_tree->_end_iterator);
			// 			// return (++(this->_binary_tree->_value));
			// 			// return (nullptr);
			// 	}	
			// 	return (*tmp);
			// };


	private:
		BinaryTree<Key, T>		*_binary_tree;
	};
};

#endif