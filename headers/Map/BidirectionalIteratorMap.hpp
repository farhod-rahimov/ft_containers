#ifndef BIDIRECTIONAL_ITERATOR_MAP_HPP
#define BIDIRECTIONAL_ITERATOR_MAP_HPP

#include "utils.hpp"

namespace ft {
	template <typename T>
    class BidirectionalIteratorMap {
	public:
			typedef std::ptrdiff_t							difference_type;
			typedef T										value_type;
			typedef T *                                     pointer;
			typedef std::bidirectional_iterator_tag         iterator_category;

	// ----------------------------------------------------------------------------------------------------------- //

			BidirectionalIteratorMap() {
				this->_binary_tree = nullptr;
			};
			
            virtual ~BidirectionalIteratorMap() {};
            
            BidirectionalIteratorMap(pointer value) {
				this->_binary_tree = new BinaryTree<value_type>;
				this->_binary_tree->_value = value;
				this->_binary_tree->_parent = nullptr;
				this->_binary_tree->_lh = nullptr;
				this->_binary_tree->_rh = nullptr;
			};
            
			BidirectionalIteratorMap(pointer value, BinaryTree<value_type> * parent) {
				this->_binary_tree = new BinaryTree<value_type>;
				this->_binary_tree->_value = value;
				this->_binary_tree->_parent = parent;
				this->_binary_tree->_lh = nullptr;
				this->_binary_tree->_rh = nullptr;
			};
            
            BidirectionalIteratorMap(BinaryTree<value_type> btree) {
				this->_binary_tree = new BinaryTree<value_type>;
				this->_binary_tree = btree;
			};
			
			BidirectionalIteratorMap(BidirectionalIteratorMap const & src) {
				*this = src;
			};
			
			BidirectionalIteratorMap & operator = (BidirectionalIteratorMap const & src) {
				if (this != &src) {
					if (this->_binary_tree != nullptr) {
						delete this->_binary_tree;
					}
					this->_binary_tree = new BinaryTree<value_type>(*src._binary_tree);
                }
				return (*this);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			bool operator == (BidirectionalIteratorMap const & src) const {
				return (this->_binary_tree_ptr == src._binary_tree_ptr);
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

			BidirectionalIteratorMap * operator ++ (int)
			{
				BidirectionalIteratorMap *tmp(this);

				if (tmp->_binary_tree->_rh) {
					tmp->_binary_tree = tmp->_binary_tree->_rh;
					while (tmp->_binary_tree->_lh) {
						tmp->_binary_tree = tmp->_binary_tree->_lh;
					}
				}
				else {
					while (tmp->_binary_tree->_value <= this->_binary_tree->_value && tmp->_binary_tree->_parent) {
						tmp->_binary_tree = tmp->_binary_tree->_parent;
					}
					if (tmp->_binary_tree->_value <= this->_binary_tree->_value)
						return (nullptr);
				}		
				return (tmp);
			};
	
	// ----------------------------------------------------------------------------------------------------------- //
			
			friend BidirectionalIteratorMap operator -- (BidirectionalIteratorMap & it) {
				it--;
				return (it);
			};

			BidirectionalIteratorMap * operator -- (int)
			{

				BidirectionalIteratorMap *tmp(this);

				if (tmp->_binary_tree->_lh) {
					tmp->_binary_tree = tmp->_binary_tree->_lh;
					while (tmp->_binary_tree->_rh) {
						tmp->_binary_tree = tmp->_binary_tree->_rh;
					}
				}
				else {
					while (tmp->_binary_tree->_value >= this->_binary_tree->_value && tmp->_binary_tree->_parent) {
						tmp->_binary_tree = tmp->_binary_tree->_parent;
					}
					if (tmp->_binary_tree->_value >= this->_binary_tree->_value)
						return (nullptr);
				}		
				return (tmp);
			};

	// ----------------------------------------------------------------------------------------------------------- //

	private:
			BinaryTree<value_type> *_binary_tree;
	};
};
#endif