#ifndef BIDIRECTIONAL_ITERATOR_MAP_HPP
#define BIDIRECTIONAL_ITERATOR_MAP_HPP

namespace ft {
    template <typename T>
    class BidirectionalIteratorMap {
    public:
			typedef std::ptrdiff_t							difference_type;
			typedef T										value_type;

			typedef T *                                     pointer;

			typedef std::bidirectional_iterator_tag         iterator_category;

	// ----------------------------------------------------------------------------------------------------------- //
    
	private:
                typedef struct _s {
				public:
					_s() {};
					_s(value_type const & src, _s * parent) : value(src), parent(parent) {
						this->lhs = nullptr;
						this->rhs = nullptr;
					};
					~_s() {
						// delete lhs;
						// delete rhs;
					};
					value_type	value;
					struct _s	*parent;
					struct _s	*lhs;
					struct _s	*rhs;
				} 				_BinaryTree;
	
	// ----------------------------------------------------------------------------------------------------------- //
    
	public:

            BidirectionalIteratorMap() {};
			
            virtual ~BidirectionalIteratorMap() {};
            
            BidirectionalIteratorMap(pointer ptr) : _ptr(ptr) {};
            
            BidirectionalIteratorMap(pointer ptr, _BinaryTree & btree) : _ptr(ptr), _binary_tree(btree) {};
			
			BidirectionalIteratorMap(BidirectionalIteratorMap const & src) {
				*this = src;
			};
			
			BidirectionalIteratorMap & operator = (BidirectionalIteratorMap const & src) {
				if (this != &src) {
					this->_ptr = src._ptr;
                    this->_binary_tree = src._binary_tree;
                }
				return (*this);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			bool operator == (BidirectionalIteratorMap const & src) const {
				return (this->_ptr == src._ptr);
			}

			bool operator != (BidirectionalIteratorMap const & src) const {
				return (this->_ptr != src._ptr);
			}

	// ----------------------------------------------------------------------------------------------------------- //

			value_type & operator * (void) {
				return (*_ptr);
			};

			value_type *operator -> (void) {
				return (_ptr);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			friend BidirectionalIteratorMap operator ++ (BidirectionalIteratorMap & it) {
				it++;
				return (it);
			};

			BidirectionalIteratorMap operator ++ (int)
			{
				BidirectionalIteratorMap tmp(*this);

				if (tmp->_binary_tree->rhs) {
					tmp->_binary_tree = tmp->_binary_tree->rhs;
					while (tmp->_binary_tree->lhs) {
						tmp->_binary_tree = tmp->_binary_tree->lhs;
					}
				}
				else {
					while (tmp->_binary_tree->value <= this->_binary_tree->value && tmp->_binary_tree->parent) {
						tmp->_binary_tree = tmp->_binary_tree->parent;
						}
					if (tmp->_binary_tree->value <= this->_binary_tree->value)
						return (nullptr);
				}		
				return (tmp);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			friend BidirectionalIteratorMap operator -- (BidirectionalIteratorMap & it) {
				it--;
				return (it);
			};

			BidirectionalIteratorMap operator -- (int)
			{
				BidirectionalIteratorMap tmp(*this);
				if (tmp->_binary_tree->lhs) {
					tmp->_binary_tree = tmp->_binary_tree->lhs;
					while (tmp->_binary_tree->rhs) {
						tmp->_binary_tree = tmp->_binary_tree->rhs;
					}
				}
				else {
					while (tmp->_binary_tree->value >= this->_binary_tree->value && tmp->_binary_tree->parent) {
						tmp->_binary_tree = tmp->_binary_tree->parent;
					}
					if (tmp->_binary_tree->value >= this->_binary_tree->value)
						return (nullptr);
				}
				return (tmp);
			};

	// ----------------------------------------------------------------------------------------------------------- //


    private:
            pointer     _ptr;
            _BinaryTree _binary_tree;
    };
};

#endif