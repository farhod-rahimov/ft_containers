#ifndef VECtOR_HPP
# define VECTOR_HPP

#include <memory>

#include "RandomAccessIterator.hpp"

template < class T, class Alloc = std::allocator<T> >
class vector {
public:
		typedef T										value_type;
		typedef Alloc									allocator_type;

		typedef allocator_type::reference				reference;
		typedef allocator_type::const_reference			const_reference;
		
		typedef allocator_type::pointer					pointer;
		typedef allocator_type::const_pointerinter		const_pointer;
		
		typedef RandomAccessIterator<value_type>		iterator;
		// typedef RandomAccessIterator<value_type const>	const_iterator;
		// typedef ReverseIterator<iterator>				reverse_iterator;
		// typedef ReverseIterator<const_iterator>			const_reverse_iterator;

		typedef std::ptrdiff_t							difference_type;
		typedef size_t									size_type;

private:
	pointer		_my_vector;
	size_type	_capacity;
	size_type	_size;
};

#endif