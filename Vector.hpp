#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>

#include "RandomAccessIterator.hpp"
#include "RandomAccessReverseIterator.hpp"
#include "utils.hpp"

namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class vector {
	public:
			typedef 			T												value_type;
			typedef 			Alloc											allocator_type;

			typedef typename	allocator_type::reference						reference;
			typedef typename	allocator_type::const_reference					const_reference;
			
			typedef typename	allocator_type::pointer							pointer;
			typedef typename	allocator_type::const_pointer					const_pointer;
			
			typedef 			RandomAccessIterator<value_type>				iterator;
			typedef 			RandomAccessIterator<value_type const>			const_iterator;
			typedef 			RandomAccessReverseIterator<value_type>			reverse_iterator;
			typedef 			RandomAccessReverseIterator<value_type const>	const_reverse_iterator;

			typedef 			std::ptrdiff_t									size_type;
			typedef 			size_t											difference_type;

	// INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION  //

			explicit vector (const allocator_type& alloc = allocator_type()) {
				static_cast<void>(alloc);

				this->_my_vector = nullptr;
				this->_capacity = 0;
				this->_size = 0;
			};
			
			explicit vector (size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type()) {
				static_cast<void>(alloc);

				this->_my_vector = _allocator.allocate(n);
				this->_capacity = n;
				this->_size = n;
				for (size_type i = 0; i < this->_size; i++) {
					this->_allocator.construct(this->_my_vector + i, val);
				}
			};
			
			vector (iterator first, iterator last,
							const allocator_type& alloc = allocator_type()) {
				static_cast<void>(alloc);

				size_type size = last - first;

				this->_my_vector = _allocator.allocate(size);
				this->_capacity = size;
				for (size_type i = 0; i < size; i++) {
					this->_allocator.construct(this->_my_vector + i, *first++);
				}
				this->_size = size;
			};
			
			vector (const vector& x) {
				this->_my_vector = _allocator.allocate(x._size);
				this->_capacity = x._capacity;
				this->_size = x._size;

				for (size_type i = 0; i < x._size; i++) {
					this->_allocator.construct(this->_my_vector + i, x._my_vector[i]);
				}
			};

			~vector () {
				for (size_type i = 0; i < this->_size; i++) {
					this->_allocator.destroy(this->_my_vector + i);
				}
				this->_allocator.deallocate(this->_my_vector, this->_capacity);
			};

	// ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS ITERATORS //

			iterator begin() {
				iterator ret_it(this->_my_vector);
				return (ret_it);
			};
			
			const_iterator begin() const {
				const_iterator ret_it(this->_my_vector);
				return (ret_it);
			};

			iterator end() {
				iterator ret_it(this->_my_vector + this->_size);
				return (ret_it);
			};
			
			const_iterator end() const {
				const_iterator ret_it(this->_my_vector + this->_size);
				return (ret_it);
			};

			reverse_iterator rbegin() {
				reverse_iterator ret_it(this->_my_vector + this->_size - 1);
				return(ret_it);
			};

			const_reverse_iterator rbegin() const {
				const_reverse_iterator ret_it(this->_my_vector + this->_size - 1);
				return(ret_it);
			};

			reverse_iterator rend() {
				reverse_iterator ret_it(this->_my_vector - 1);
				return (ret_it);
			};

			const_reverse_iterator rend() const {
				const_reverse_iterator ret_it(this->_my_vector - 1);
				return (ret_it);
			};


	// CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY CAPACITY //
			
			size_type size() const {
				return (this->_size);
			};

			size_type max_size() const {
				return (this->_allocator.max_size());
			};

			void resize (size_type n, value_type val = value_type()) {
				if (n < this->_size) {
					for (size_type i = n; i < this->size(); i++) {
						this->_allocator.destroy(this->_my_vector + i);
					}
				}
				else if (n < this->_capacity) {
					for (size_type i = this->_size; i < n; i++) {
						this->_allocator.construct(this->_my_vector + i, val);
					}
				}
				else {
					vector tmp(*this);

					for (size_type i = 0; i < this->_size; i++) {
						this->_allocator.destroy(this->_my_vector + i);
					}
					this->_allocator.deallocate(this->_my_vector, this->_capacity);
					if (this->_capacity != 0) {
						this->_my_vector = this->_allocator.allocate(this->_capacity * 2);
						this->_capacity *= 2;
					}
					else {
						this->_my_vector = this->_allocator.allocate(1);
						this->_capacity = 1;
					}

					size_type i = 0;
					for (iterator it = tmp.begin(); it != tmp.end(); i++) {
						this->_allocator.construct(this->_my_vector + i, *it++);
					}
					for (; i < n; i++) {
						this->_allocator.construct(this->_my_vector + i, val);
					}
				}
				this->_size = n;
			};

			size_type capacity() const {
				return (this->_capacity);
			};

			bool empty() const {
				return (this->_size == 0);
			};

			void reserve (size_type n) {
				if (n > this->_capacity) {
					vector tmp(*this);

					for (size_type i = 0; i < this->_size; i++) {
						this->_allocator.destroy(this->_my_vector + i);
					}
					this->_allocator.deallocate(this->_my_vector, this->_capacity);
					this->_my_vector = this->_allocator.allocate(n);

					size_type i = 0;
					for (iterator it = tmp.begin(); it != tmp.end(); i++) {
						this->_allocator.construct(this->_my_vector + i, *it++);
					}
					this->_capacity = n;
				}
			};

	// ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS ELEMENT_ACCESS //

			reference operator [] (size_type n) {
				return (this->_my_vector[n]);
			};

			const_reference operator [] (size_type n) const {
				return (this->_my_vector[n]);
			};

			reference at (size_type n) {
				if (n >= this->_size)
					throw (std::out_of_range("vector"));
				return (this->_my_vector[n]);
			};

			const_reference at (size_type n) const {
				if (n >= this->_size)
					throw (std::out_of_range("vector"));
				return (this->_my_vector[n]);
			};

			reference front() {
				return (this->_my_vector[0]);
			};

			const_reference front() const {
				return (this->_my_vector[0]);
			};

			reference back() {
				return (this->_my_vector[this->_size - 1]);
			};

			const_reference back() const {
				return (this->_my_vector[this->_size - 1]);
			};

	// MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS MODIFIERS //

			void assign (iterator first, iterator last) {
				size_type size = last - first;

				for (size_type i = 0; i < this->_size; i++) {
					this->_allocator.destroy(this->_my_vector + i);
				}

				if (size > this->_capacity) {
					this->_allocator.deallocate(this->_my_vector, this->_capacity);
					this->_my_vector = this->_allocator.allocate(size);
					this->_capacity = size;
				}

				for (size_type i = 0; i < size; i++) {
					this->_allocator.construct(this->_my_vector + i, *first++);
				}
				this->_size = size;
			};
			
			void assign (size_type n, const value_type& val) {
				for (size_type i = 0; i < this->_size; i++) {
					this->_allocator.destroy(this->_my_vector + i);
				}
				
				if (n > this->_capacity) {
					this->_allocator.deallocate(this->_my_vector, this->_capacity);
					this->_my_vector = this->_allocator.allocate(n);
					this->_capacity = n;
				}

				for (size_type i = 0; i < n; i++) {
					this->_allocator.construct(this->_my_vector + i, val);
				}
				this->_size = n;
			};

			void push_back (const value_type& val) {
				if (this->_size < this->_capacity) {
					this->_my_vector[this->_size] = val;
				}
				else {
					vector tmp(*this);

					for (size_type i = 0; i < this->_size; i++) {
						this->_allocator.destroy(this->_my_vector + i);
					}
					this->_allocator.deallocate(this->_my_vector, this->_capacity);
					if (this->_capacity != 0) {
						this->_my_vector = this->_allocator.allocate(this->_capacity * 2);
						this->_capacity *= 2;
					}
					else {
						this->_my_vector = this->_allocator.allocate(1);
						this->_capacity = 1;
					}
					
					size_type i = 0;
					for (iterator it = tmp.begin(); it != tmp.end(); i++) {
						this->_allocator.construct(this->_my_vector + i, *it++);
					}
					this->_my_vector[i] = val;
				}
				this->_size += 1;
			};

			void pop_back() {
				if (this->empty())
					return ;
				this->_allocator.destroy(this->_my_vector + this->_size - 1);
				this->_size -= 1;
			};

			iterator insert (iterator position, const value_type& val) {
				iterator	inserted_element = this->begin();
				size_type	inserted_position = 0;
				vector		tmp(*this);

				while (inserted_element++ != position)
					inserted_position++;
				
				if (this->_size + 1 > this->_capacity) {
					for (size_type i = 0; i < this->_size; i++) {
						this->_allocator.destroy(this->_my_vector + i);
					}

					this->_allocator.deallocate(this->_my_vector, this->_capacity);
					if (this->_capacity != 0) {
						this->_my_vector = this->_allocator.allocate(this->_capacity * 2);
						this->_capacity *= 2;
					}
					else {
						this->_my_vector = this->_allocator.allocate(1);
						this->_capacity = 1;
					}
				}

				if (tmp.size() != 0) {
					for (size_type i = 0; i < tmp.size(); i++) {
						if (i == inserted_position) {
							this->_allocator.construct(this->_my_vector + i, val);
							for (size_type k = inserted_position + 1; i < tmp.size(); ++i) {
								this->_allocator.construct(this->_my_vector + k++, tmp[i]);
							}
							break ;
						}
						this->_allocator.construct(this->_my_vector + i, tmp[i]);
					}
				}
				else {
					this->_allocator.construct(this->_my_vector + inserted_position, val);
				}

				this->_size += 1;
				return (this->begin() + inserted_position);
			};
			
			void insert (iterator position, size_type n, const value_type& val) {
				iterator	inserted_element = this->begin();
				size_type	inserted_position = 0;
				vector		tmp(*this);

				if (n == 0)
					return ;
				while (inserted_element++ != position)
					inserted_position++;

				if (this->_size + n > this->_capacity) {
					for (size_type i = 0; i < this->_size; i++) {
						this->_allocator.destroy(this->_my_vector + i);
					}
					this->_allocator.deallocate(this->_my_vector, this->_capacity);
					this->_my_vector = this->_allocator.allocate(this->_size + n);
					this->_capacity = this->_size + n;
				}

				if (tmp.size() != 0) {
					for (size_type i = 0; i < tmp.size(); i++) {
						if (i == inserted_position) {
							size_type k = i;
							for (size_type j = 0; j < n; j++) {
								this->_allocator.construct(this->_my_vector + i++, val);
							}
							for ( ; k < tmp.size(); k++) {
								this->_allocator.construct(this->_my_vector + i++, tmp[k]);
							}
							break ;
						}
						this->_allocator.construct(this->_my_vector + i, tmp[i]);
					}
				}
				else {
					for (size_type j = 0; j < n; j++) {
							this->_allocator.construct(this->_my_vector + j, val);
					}
				}
				this->_size += n;
			};

			void insert (iterator position, iterator first, iterator last) {
				size_type n = last - first;
				iterator	inserted_element = this->begin();
				size_type	inserted_position = 0;
				vector		tmp(*this);

				if (n == 0)
					return ;
				while (inserted_element++ != position)
					inserted_position++;

				if (this->_size + n > this->_capacity) {
					for (size_type i = 0; i < this->_size; i++) {
						this->_allocator.destroy(this->_my_vector + i);
					}
					this->_allocator.deallocate(this->_my_vector, this->_capacity);
					this->_my_vector = this->_allocator.allocate(this->_size + n);
					this->_capacity = this->_size + n;
				}

				if (tmp.size() != 0) {
					for (size_type i = 0; i < tmp.size(); i++) {
						if (i == inserted_position) {
							size_type k = i;
							for (size_type j = 0; j < n; j++) {
								this->_allocator.construct(this->_my_vector + i++, *first++);
							}
							for ( ; k < tmp.size(); k++) {
								this->_allocator.construct(this->_my_vector + i++, tmp[k]);
							}
							break ;
						}
						this->_allocator.construct(this->_my_vector + i, tmp[i]);
					}
				}
				else {
					for (size_type j = 0; j < n; j++) {
							this->_allocator.construct(this->_my_vector + j, *first++);
					}
				}
				this->_size += n;
			};

			iterator erase (iterator position) {
				vector		tmp(*this);
				iterator	erase_el = this->begin();
				size_type	erase_pos = 0;

				while (erase_el++ != position)
					erase_pos++;
				if (erase_pos >= this->_size)
					return (this->begin());

				for (size_type i = erase_pos; i < this->_size; i++) {
					this->_allocator.destroy(this->_my_vector + i);
				}

				for (size_type i = erase_pos; i + 1 < tmp.size(); i++) {
					this->_allocator.construct(this->_my_vector + i, tmp[i + 1]);
				}
				this->_size -= 1;
				return (this->begin() + erase_pos);
			};

			iterator erase (iterator first, iterator last) {
				vector			tmp(*this);
				size_type	n = last - first;
				iterator		erase_el = this->begin();
				size_type		erase_pos = 0;

				while (erase_el++ != first)
					erase_pos++;
				if (erase_pos >= this->_size)
					return (this->begin());
				
				for (size_type i = erase_pos; i < this->_size; i++) {
					this->_allocator.destroy(this->_my_vector + i);
				}
				
				for (size_type i = erase_pos; i + n < tmp.size(); i++) {
					this->_allocator.construct(this->_my_vector + i, tmp[i + n]);
				}
				this->_size -= n;
				return (this->begin() + erase_pos);
			};

			void swap (vector& x) {
				pointer		tmp_pointer = &x.front();
				size_type 	tmp_size = x.size();
				size_type 	tmp_capacity = x.capacity();

				x._my_vector = this->_my_vector;
				x._size = this->_size;
				x._capacity = this->_capacity;

				this->_my_vector = tmp_pointer;
				this->_size = tmp_size;
				this->_capacity = tmp_capacity;
			};

			void clear() {
				for (size_type i = 0; i < this->_size; i++) {
					this->_allocator.destroy(this->_my_vector + i);
				}
				this->_size = 0;
			};

	// ALLOCATOR ALLOCATOR ALLOCATOR ALLOCATOR ALLOCATOR ALLOCATOR ALLOCATOR ALLOCATOR ALLOCATOR ALLOCATOR ALLOCATOR ALLOCATOR //

			allocator_type get_allocator() const {
				return (this->_allocator);
			};

	private:
			pointer		_my_vector;
			size_type	_capacity;
			size_type	_size;
			Alloc		_allocator;
	};

	// NON-MEMBER FUNCTION OVERLOADS | NON-MEMBER FUNCTION OVERLOADS | NON-MEMBER FUNCTION OVERLOADS | NON-MEMBER FUNCTION OVERLOADS //

	template <class T, class Alloc>
	bool operator == (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		for (long i = 0; i < lhs.size(); i++) {
			if (lhs[i] != rhs[i])
				return (false);
		}
		return (true);
	};

	template <class T, class Alloc>
	bool operator != (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs==rhs));
	};

	template <class T, class Alloc>
	bool operator <  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template <class T, class Alloc>
	bool operator <= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		static_cast<void>(lhs);
		if (rhs.size() == 0)
			return (false);
		return (true);
	}

	template <class T, class Alloc>
	bool operator > (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!operator < (lhs, rhs));

	};

	template <class T, class Alloc>
	bool operator >= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!operator <= (lhs, rhs));
	};

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	};
}

#endif