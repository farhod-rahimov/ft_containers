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


			pair() : first(first_type()) {
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

}; 

#endif