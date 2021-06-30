#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <limits>
#include "VectorIterators_old.hpp"
#include "RandomAccessIterator.hpp"

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

	typedef RandomAccessIterator<T>				iterator;
	// typedef VectorIterator<T>				iterator;
	typedef VectorIterator<T>				InputIterator;
	// typedef ConstVectorIterator<T> 			const_iterator;
	// typedef ReverseVectorIterator<T>		reverse_iterator;
	// typedef ConstReverseVectorIterator<T>	const_reverse_iterator;

	// BASIC_STUFF // BASIC_STUFF // BASIC_STUFF // BASIC_STUFF // BASIC_STUFF // BASIC_STUFF // BASIC_STUFF 

	explicit Vector () : _my_vector(nullptr), _size(0), _capacity(0) {
	};

	explicit Vector (size_type n, const value_type& val = value_type()) {
		// std::cout << "THISSSS BOYY\n";
		
		if (n > max_size())
			throw (std::length_error("ft::Vector<T>::Vector(size_type n, ...) - 'n' exceeds maximum supported size"));
		this->_my_vector = new value_type[n];

		for (size_type i = 0; i < n; i++) {
			this->_my_vector[i] = val;
		}
		this->_size = n;
		this->_capacity = n;
	};

	Vector(InputIterator first, InputIterator last) {
		size_type size = 0;

		// std::cout << "NNNOOOOOO BOYY\n";
		for (iterator f = first; f != last; f++) {
			size++;
		}
		if (size > max_size())
			throw (std::length_error("ft::Vector<T>::Vector(InputIterator first, InputIterator last) - 'last - first' exceeds maximum supported size"));
		_my_vector = new value_type[size];
		_capacity = size;
		_size = size;
		for (size_type i = 0; i < size; i++)
			_my_vector[i] = *first;
	};
	
	Vector (const Vector& x) {
		this->_my_vector = nullptr;
		*this = x;
	};

	~Vector() {
		if (_my_vector != nullptr)
			delete [] _my_vector;
	}

	
	Vector & operator=(Vector const &src) {
		if (this != &src)
		{
			if (_my_vector != nullptr)
				delete [] _my_vector;
			_my_vector = new value_type[src._capacity];
			_capacity = src._capacity;
			_size = src._size;

			for (size_type i = 0; i < _size; i++) {
				_my_vector[i] = src._my_vector[i];
			}
		}
		return (*this);
	};
	
	// ITERATORS // ITERATORS // ITERATORS // ITERATORS // ITERATORS // ITERATORS // ITERATORS // ITERATORS // ITERATORS 

	iterator begin() {
		iterator it(_my_vector);
		return (it);
	};

	// const_iterator begin() const {						 //UNCOMMENT
	// 	return (_my_vector);
	// };

	iterator end() {
		iterator it(_my_vector + _size);
		return (it);
	};

	// const_iterator end() const {						 //UNCOMMENT
	// 	return (_my_vector + _size);
	// };





	// reverse_iterator rbegin();						 //UNCOMMENT
	// const_reverse_iterator rbegin() const;			//UNCOMMENT

	// reverse_iterator rend();						 //UNCOMMENT
	// const_reverse_iterator rend() const;			//UNCOMMENT




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
	
	void assign (InputIterator first, InputIterator last) {
		size_type size;

		for (size = 0; first != last; first++) {
			size++;
		}

		if (size > this->_capacity)
		{
			if (_my_vector != nullptr)
				delete [] _my_vector;

			_my_vector = new value_type[size];
			for (size_type i = 0; first != last; first++) {
				_my_vector[i++] = *first;
			}
			this->_capacity = size;
		}
		else if (size < this->_capacity)
		{
			for (size_type i = 0; first != last; first++) {
				_my_vector[i++] = *first;
			}
		}
		this->_size = size;
	};
	
	void assign (size_type n, const value_type& val) {
		if (n > this->_capacity)
		{
			if (_my_vector != nullptr)
				delete [] _my_vector;

			_my_vector = new value_type[n];
			for (size_type i = 0; i < n; i++) {
				_my_vector[i] = val;
			}
			this->_capacity = n;
		}
		else
		{
			for (size_type i = 0; i < n; i++) {
				_my_vector[i] = val;
			}
		}
		this->_size = n;
	};

	void push_back(const value_type& val) {
		pointer tmp;
		
		if (this->_size < this->_capacity)
		{
			this->_my_vector[this->_size] = val;
			this->_size++;
			return ;
		}

		tmp = new value_type[this->_size];
		for (size_type i = 0; i < this->_size; i++) {
			tmp[i] = this->_my_vector[i];
		}

		if (this->_my_vector != nullptr)
			delete [] this->_my_vector;
		
		this->_my_vector = new value_type[this->_size + 1];
		for (size_type i = 0; i < this->_size; i++) {
			this->_my_vector[i] = tmp[i];
		}
		this->_my_vector[this->_size] = val;
		
		this->_size += 1;
		this->_capacity = this->_size; 
	};

	void pop_back() {
		if (this->_my_vector == nullptr)
			return ;
		this->_size -= 1;
	};


	iterator insert (iterator position, const value_type& val) {
		size_type i = 0;
		
		if (this->_size < this->_capacity)
		{
			iterator ret;
			Vector tmp(*this);
			for (iterator start = this->begin(); i < tmp.size(); start++) {
				if (start == position)
				{
					*start = val;
					ret = start;
					start++;
				}
				*start = tmp[i++];
			}
			this->_size += 1;
			return (ret);
		}

		pointer new_vector = new value_type[this->_size + 1];
		size_type k = 0;
		size_type ret;
		for (iterator start = this->begin(); i < this->_size + 1; start++) {
			if (start == position)
			{
				ret = i;
				new_vector[i++] = val;
			}
			new_vector[i++] = this->_my_vector[k++];
		}
		delete [] this->_my_vector;
		this->_my_vector = new_vector;
		this->_size += 1;
		this->_capacity = this->_size;
		return (this->begin() + ret);
	};

	void insert (iterator position, size_type n, const value_type& val) {
		for (size_type i = 0; i < n; i++) {
			position = insert(position, val);
		}
	};

	// template <class InputIterator>				// DONT UNDERSTAND - HALF WORKING
	// void insert (iterator position, InputIterator first, InputIterator last) {
		
	// 	value_type val = *first;
		
	// 	for ( ; first != last; first++) {
	// 		val = *first;
	// 		position = this->insert(position, val);
	// 	}
	// };

	iterator erase (iterator position) {
		Vector		tmp(*this);
		iterator	start = this->begin();
		size_type	ret;
		size_type	k = 0;

		if (this->_size == 0)
			return (this->begin());
		for (size_type i = 0; i < this->_size; i++) {
			if (start == position)
				ret = i++;
			this->_my_vector[k++] = tmp[i];
			start++;
		}
		this->_size -= 1;
		return (this->begin() + ret);
	};

	iterator erase (iterator first, iterator last) {
		size_type deleted = 0;
		iterator f = first;	

		
		if (this->_size == 0)
			return (this->begin());

		while (f != last)
		{
			f++;
			deleted++;
		}

		Vector		tmp(*this);
		size_type	ret;
		size_type	k = 0;
		iterator	start = this->begin();
		for (size_type i = 0; i < this->_size; i++) {
			if (start == first)
			{
				ret = i++;
				while (true)
				{
					start++;
					if (start == last)
						break;
					i++;
				}
			}
			this->_my_vector[k++] = tmp[i];
			start++;
		}
		this->_size = this->_size - deleted;
		return (this->begin() + ret);
	};

	void swap (Vector& x) {
		pointer tmp;
		size_type tmp_size;
		size_type tmp_capacity;

		tmp = this->_my_vector;
		tmp_size = this->_size;
		tmp_capacity = this->_capacity;
		
		this->_my_vector = x._my_vector;
		this->_size = x._size;
		this->_capacity = x._capacity;
		
		x._my_vector = tmp;
		x._size = tmp_size;
		x._capacity = tmp_capacity;
	};

	void clear() {
		for (iterator start = this->begin(); start != this->end(); start++) {
			*start = value_type();
		}
		this->_size = 0;
	};

private:
	pointer     _my_vector;
	size_type   _capacity;
	size_type   _size;
};

#endif
