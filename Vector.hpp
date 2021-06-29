#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <limits>
#include "VectorIterators.hpp"

template<typename T>
class Vector {
public:
	typedef std::ptrdiff_t  				difference_type;
	typedef size_t          				size_type;
	typedef T               				value_type;
	typedef T *             				pointer;
	typedef T const *       				const_pointer;
	typedef T &             				reference;
	typedef T const &       				const_reference;

	typedef VectorIterator<T>				iterator;
	// typedef ConstVectorIterator<T> 			const_iterator;
	// typedef ReverseVectorIterator<T>		reverse_iterator;
	// typedef ConstReverseVectorIterator<T>	const_reverse_iterator;

	// BASIC_STUFF // BASIC_STUFF // BASIC_STUFF // BASIC_STUFF // BASIC_STUFF // BASIC_STUFF // BASIC_STUFF 

	Vector() : _my_vector(NULL), _capacity(0), _size(0) {
	};
	
	Vector(size_type n) {
		if (n > max_size())
			throw (std::length_error("ft::Vector<T>::Vector(size_type n) - 'n' exceeds maximum supported size"));
		_my_vector = new value_type[n];
		_capacity = n;
		_size = n;
	};
	
	template <class InputIterator>
	Vector(InputIterator first, InputIterator last) {
		size_type size;

		size = first - last;
		if (size > max_size())
			throw (std::length_error("ft::Vector<T>::Vector(InputIterator first, InputIterator last) - 'last - first' exceeds maximum supported size"));
		_my_vector = new value_type[size];
		_capacity = size;
		_size = size;
		for (size_type i = 0; i < size; i++)
			_my_vector[i] = first++;

	};

	Vector(Vector const & src) {
		*this = src;
	};
	
	~Vector() {
		if (_my_vector)
			delete [] _my_vector;
	}

	
	Vector & operator=(Vector const &src) {
		if (this == &src)
			return ;
		if (_my_vector != NULL)
			delete [] _my_vector;
		_my_vector = new value_type[src._capacity];
		_capacity = src._capacity;
		_size = src._size;

		for (size_type i = 0; i < _size; i++) {
			_my_vector[i] = src._my_vector[i];
		}
	};
	
	// ITERATORS // ITERATORS // ITERATORS // ITERATORS // ITERATORS // ITERATORS // ITERATORS // ITERATORS // ITERATORS 

	// iterator begin() {
	// 	return (_my_vector);
	// };

	// const_iterator begin() const {
	// 	return (_my_vector);
	// };

	// iterator end() {
	// 	return (_my_vector + _size);
	// };

	// const_iterator end() const {
	// 	return (_my_vector + _size);
	// };


	// CAPACITY_START // CAPACITY_START // CAPACITY_START // CAPACITY_START // CAPACITY_START // CAPACITY_START

	size_type size() const {
		return (_size);
	};

	size_type max_size() const {
		return (std::numeric_limits<size_type>::max() / sizeof(value_type));
	};

	void resize(size_type n, value_type val = value_type()) {
		if (n > max_size())
			throw (std::length_error("ft::Vector<T>::resize(size_type n, ...) - 'n' exceeds maximum supported size"));
		if (n < _size)
		{
			for (size_type i = _size - 1; _size > n; _size--) {
				_my_vector[i--] = val;
			}
		}
		else if (n < _capacity && n > _size) {
			for (size_type i = _size; _size < n; _size++) {
				_my_vector[i++] = val;
			}
		}
		else if (n > _capacity) {
			pointer tmp;

			tmp = new value_type[_size];
			for (size_type i = 0; i < _size; i++) {
				tmp[i] = _my_vector[i];
			}
			
			delete [] _my_vector;
			_my_vector = new value_type[n];
			for (size_type i = 0; i < n; i++) {
				_my_vector[i] = tmp[i];
				for ( ; i >= _size && i < n; i++) {
					_my_vector[i] = val;
				}
			}
			_size = n;
			_capacity = n;
		}
	};

	size_type capacity() const {
		return (_capacity);
	};

	bool empty() const {
		if (!_size)
			return (true);
		return (false);
	};

	void reserve(size_type n) {
		if (n <= _capacity)
			return ;
		pointer tmp;

		if (n > max_size())
			throw (std::length_error("ft::Vector<T>::reserve(size_type n) - 'n' exceeds maximum supported size"));
		tmp = new value_type[_size];
		for (size_type i = 0; i < _size; i++) {
			tmp[i] = _my_vector[i];
		};

		delete [] _my_vector; _my_vector = nullptr;
		
		_my_vector = new value_type[n];
		for (size_type i = 0; i < n; i++) {
			_my_vector[i] = tmp[i];
			for ( ; i > _size && i < n; i++) {
				_my_vector[i] = value_type();
			};
		};
		_capacity = n;
	};
	
	// ELEMENT_ACCESS_START // ELEMENT_ACCESS_START // ELEMENT_ACCESS_START // ELEMENT_ACCESS_START // ELEMENT_ACCESS_START 

	reference operator[] (size_type n) {
		return (_my_vector[n]);
	};

	const_reference operator[] (size_type n) const {
		return (_my_vector[n]);
	};
	
	reference at (size_type n) {
		
		if (n >= _size)
			throw (std::out_of_range("ft::Vector<T>::at(size_type n) - 'n' out of range"));
		return (_my_vector[n]);
	};
	
	const_reference at (size_type n) const {
		if (n >= _size)
			throw (std::out_of_range("ft::Vector<T>::at(size_type n) - 'n' out of range"));
		return (_my_vector[n]);
	};

	reference front() {
		return (_my_vector[0]);
	};
	
	const_reference front() const {
		return (_my_vector[0]);
	};

	reference back() {
		return (_my_vector[_size - 1]);
	};

	const_reference back() const {
		return (_my_vector[_size - 1]);
	};

	// MODIFIERS // MODIFIERS // MODIFIERS // MODIFIERS // MODIFIERS // MODIFIERS // MODIFIERS // MODIFIERS // MODIFIERS 




private:
	pointer     _my_vector;
	size_type   _capacity;
	size_type   _size;
};

#endif
