#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft {

// PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR //

	template <class T1, class T2>
	struct pair {
	public:
			typedef		T1	first_type;
			typedef		T2	second_type;


			pair() : first(first_type()), second(second_type()) {
			};
			
			template <class U, class V>
			pair (const pair <U, V> & pr) : first(pr.first), second(pr.second) {
			};

			pair (const first_type & a, const second_type & b) {
				this->first = a;
				this->second = b;
			};

			pair & operator = (const pair & pr) {
				if (this != &pr) {
					this->first = pr.first;
					this->second = pr.second;
				}
				return (*this);
			};

			first_type	first;
			second_type	second;
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (lhs.first==rhs.first && lhs.second==rhs.second);
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (!(lhs==rhs));
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second));
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (!(rhs<lhs));
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (rhs<lhs);
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (!(lhs<rhs));
	}

// MAKE_PAIR MAKE_PAIR MAKE_PAIR MAKE_PAIR MAKE_PAIR MAKE_PAIR MAKE_PAIR MAKE_PAIR MAKE_PAIR MAKE_PAIR MAKE_PAIR  //
	
	template <class T1, class T2>
	pair<T1, T2> make_pair (T1 x, T2 y) {
		return (pair<T1, T2>(x, y));
	};

// BINARY_TREE BINARY_TREE BINARY_TREE BINARY_TREE BINARY_TREE BINARY_TREE BINARY_TREE BINARY_TREE BINARY_TREE   //

    template < class Key, class T, class Alloc = std::allocator<ft::pair <Key const,T> > >
	struct BinaryTree {
	public:
			typedef 			Key													key_type;
			typedef 			T													mapped_type;
			typedef 			ft::pair<key_type const, mapped_type>				value_type;
			typedef 			Alloc												allocator_type;
			typedef typename	allocator_type::pointer								pointer;

			BinaryTree(const allocator_type& alloc = allocator_type()) {
				this->_allocator = alloc;
				this->_value = this->_allocator.allocate(1);
				this->_allocator.construct(this->_value, value_type());

				this->_parent = nullptr;
				this->_lh = nullptr;
				this->_rh = nullptr;
				this->_last_element = 0;
				this->_first_element = 0;
			};
			
			~BinaryTree() {
				this->_allocator.destroy(this->_value);
				this->_allocator.deallocate(this->_value, 1);
			}

			BinaryTree(const value_type & val, BinaryTree * parent, const allocator_type& alloc = allocator_type()) {
				this->_allocator = alloc;
				this->_value = this->_allocator.allocate(1);
				this->_allocator.construct(this->_value, val);

				this->_parent = parent;
				this->_lh = nullptr;
				this->_rh = nullptr;
				this->_last_element = 0;
				this->_first_element = 0;
			};
			
			BinaryTree(const BinaryTree & src) {
				*this = src;
			};

			BinaryTree &operator=(BinaryTree const &src) {
				if (this != &src) {
					this->_allocator = src._allocator;
					this->_value = src._value;
					this->_parent = src._parent;
					this->_lh = src._lh;
					this->_rh = src._rh;
					this->_last_element = src._last_element;
					this->_first_element = src._first_element;
				}
				return (*this);
			};


			void 		setLastElementFlag() { this->_last_element = 1; };
			void 		setFirstElementFlag() { this->_first_element = 1; };
			void 		removeLastElementFlag() { this->_last_element = 0; };
			void 		removeFirstElementFlag() { this->_first_element = 0; };
			bool 		isLastElement() const { return (this->_last_element); };
			bool 		isFirstElement() const { return (this->_first_element); };
			
			BinaryTree	*createFirstElemet(BinaryTree * parent) const {
				BinaryTree *ret = new BinaryTree();
				ret->_parent = parent;
				ret->setFirstElementFlag();
				return (ret);
			};

			BinaryTree	*createLastElemet(BinaryTree * parent) const {
				BinaryTree *ret = new BinaryTree();
				ret->_parent = parent;
				ret->setLastElementFlag();
				return (ret);
			};
	
			allocator_type	_allocator;
			pointer			_value;
			BinaryTree		*_parent;
			BinaryTree		*_lh;
			BinaryTree		*_rh;
			bool			_last_element;
			bool			_first_element;
	};
};

#endif