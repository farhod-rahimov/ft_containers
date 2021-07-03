#ifndef STACK_HPP
# define STACK_HPP

#include <memory>

#include "RandomAccessIterator.hpp"
#include "RandomAccessReverseIterator.hpp"
#include "utils.hpp"

#include "Vector.hpp"

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack {
	public:
			typedef	T				value_type;
			typedef	Container		container_type;
			typedef	std::ptrdiff_t	size_type;

	private:
	
	};
}


#endif