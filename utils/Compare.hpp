#ifndef COMPARE_HPP
# define COMPARE_HPP

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

// EQUAL COMAPRE EQUAL COMAPRE EQUAL COMAPRE EQUAL COMAPRE EQUAL COMAPRE EQUAL COMAPRE EQUAL COMAPRE EQUAL COMAPRE EQUAL COMAPRE  //

	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 ) {
		while (first1!=last1) {
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return (true);
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2, BinaryPredicate pred) {
		while (first1!=last1) {
			if (!pred(*first1,*first2))
				return false;
			++first1; ++first2;
		}
		return (true);
	};
};

#endif