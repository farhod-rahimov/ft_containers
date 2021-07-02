#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft {
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
    {
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
        while (first1!=last1)
        {
            if(!comp(first1,first2) && !comp(first1,first2))
                return (false);
            ++first1; ++first2;
        }
        return (true);
    };
} 

#endif