#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft {

// LEXICOGRAPHICAL COMAPRE LEXICOGRAPHICAL COMAPRE LEXICOGRAPHICAL COMAPRE LEXICOGRAPHICAL COMAPRE LEXICOGRAPHICAL COMAPRE //

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
	{
		static_cast<void>(last2);
		while (first1!=last1)
		{
			if (!(*first1 < *first2) && !(*first2 < *first1))
				return (false);
			++first1; ++first2;
		}
		return (true);
	};

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2,
								Compare comp)
	{
		static_cast<void>(last2);
		while (first1!=last1)
		{
			if(!comp(first1,first2) && !comp(first1,first2))
				return (false);
			++first1; ++first2;
		}
		return (true);
	};

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

    // template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair <const Key,T> > >
	template < class Key, class T >
	struct BinaryTree {
	public:
			typedef 			Key													key_type;
			typedef 			T													mapped_type;
			typedef 			ft::pair<key_type, mapped_type>						value_type;
			typedef 			value_type *										pointer;

			BinaryTree() {
				this->_value = new value_type;
				this->_value->first = key_type();
				this->_value->second = mapped_type();
				this->_parent = nullptr;
				this->_lh = nullptr;
				this->_rh = nullptr;
				this->_last_element = 0;
				this->_first_element = 0;
			};
			
			BinaryTree(const value_type & val, BinaryTree * parent) {
				this->_value = new value_type;
				this->_value->first = val.first;
				this->_value->second = val.second;
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
			
			BinaryTree	*createFirstElemet() const {
				BinaryTree *ret = new BinaryTree();
				ret->setFirstElementFlag();
				return (ret);
			};

			BinaryTree	*createLastElemet() const {
				BinaryTree *ret = new BinaryTree();
				ret->setLastElementFlag();
				return (ret);
			};
	
			pointer		_value;
			BinaryTree	*_parent;
			BinaryTree	*_lh;
			BinaryTree	*_rh;
			bool		_last_element;
			bool		_first_element;
	};


};

#endif