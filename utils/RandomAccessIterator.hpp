#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

namespace ft {
	template <typename T>
	class RandomAccessIterator {
	public:
			typedef std::ptrdiff_t							difference_type;
			typedef T										value_type;
			typedef value_type *                            pointer;
			typedef value_type &                            reference;
			typedef std::random_access_iterator_tag         iterator_category;

	// ----------------------------------------------------------------------------------------------------------- //
		
			RandomAccessIterator() {};
			
			virtual ~RandomAccessIterator() {};

			RandomAccessIterator(pointer ptr) : _ptr(ptr) {};
			
			RandomAccessIterator(RandomAccessIterator const & src) {
				*this = src;
			};
			
			RandomAccessIterator & operator = (RandomAccessIterator const & src) {
				if (this != &src)
					this->_ptr = src._ptr;
				return (*this);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			bool operator == (RandomAccessIterator const & src) const {
				return (this->_ptr == src._ptr);
			}

			bool operator != (RandomAccessIterator const & src) const {
				return (this->_ptr != src._ptr);
			}

	// ----------------------------------------------------------------------------------------------------------- //

			value_type & operator * (void) {
				return (*_ptr);
			};

			value_type *operator -> (void) {
				return (_ptr);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			friend RandomAccessIterator operator ++ (RandomAccessIterator & it) {
				it++;
				return (it);
			};

			RandomAccessIterator operator ++ (int)
			{
				RandomAccessIterator ret_it(*this);
				this->_ptr++;
				return (ret_it);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			friend RandomAccessIterator operator -- (RandomAccessIterator & it) {
				it--;
				return (it);
			};

			RandomAccessIterator operator -- (int)
			{
				RandomAccessIterator ret_it(*this);
				this->_ptr--;
				return (ret_it);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			RandomAccessIterator operator + (int n) const {
				RandomAccessIterator ret_it(this->_ptr + n);
				return (ret_it);
			};

			friend RandomAccessIterator operator + (int n, RandomAccessIterator const & it) {
				RandomAccessIterator ret_it(it._ptr + n);
				return (ret_it);
			};

			RandomAccessIterator operator - (int n) const {
				RandomAccessIterator ret_it(this->_ptr - n);
				return (ret_it);
			};

			difference_type operator - (RandomAccessIterator const & it) const {
				difference_type ret = this->_ptr - it._ptr;
				return (ret);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			bool operator < (RandomAccessIterator const & it) const {
				return (this->_ptr < it._ptr);
			};

			bool operator > (RandomAccessIterator const & it) const {
				return (this->_ptr > it._ptr);
			};

			bool operator <= (RandomAccessIterator const & it) const {
				return (this->_ptr <= it._ptr);
			};

			bool operator >= (RandomAccessIterator const & it) const {
				return (this->_ptr >= it._ptr);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			RandomAccessIterator & operator += (int n) {
				this->_ptr += n;
				return (*this);
			}

			RandomAccessIterator & operator -= (int n) {
				this->_ptr -= n;
				return (*this);
			}

	// ----------------------------------------------------------------------------------------------------------- //

			value_type & operator [] (int n) {
				return (this->_ptr[n]);
			}

	// ----------------------------------------------------------------------------------------------------------- //

	private:
			pointer _ptr;
	};
};

#endif