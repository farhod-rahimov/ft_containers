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
				BidirectionalIteratorMap ret_it(*this);
                this->_ptr = &ret_it->_binary_tree->value->rhs;
				return (ret_it);
			};

	// ----------------------------------------------------------------------------------------------------------- //

    private:
                typedef struct _s {
				public:
					_s(value_type const & src, size_type idx) : value(src) {
						this->lhs = nullptr;
						this->rhs = nullptr;
						this->index = idx;
					};
					~_s() {
						delete lhs;
						delete rhs;
					};
					value_type	value;
					struct _s	*lhs;
					struct _s	*rhs;
				} 				_BinaryTree;

            pointer     _ptr;
            _BinaryTree _binary_tree;
    };
};

#endif