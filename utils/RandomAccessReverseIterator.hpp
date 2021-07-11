#ifndef RANDOM_ACCESS_REVERSE_ITERATOR_HPP
# define RANDOM_ACCESS_REVERSE_ITERATOR_HPP

namespace ft {
	template <typename T>
	class RandomAccessReverseIterator {
	public:
			typedef std::ptrdiff_t							        difference_type;
			typedef T										        value_type;
			typedef value_type *                                    pointer;
			typedef value_type const *                       	    const_pointer;
			typedef value_type &									reference;
			typedef value_type const &								const_reference;
			typedef std::random_access_iterator_tag                 iterator_category;

	// ----------------------------------------------------------------------------------------------------------- //
		
			RandomAccessReverseIterator() {};
			
			virtual ~RandomAccessReverseIterator() {};

			RandomAccessReverseIterator(pointer ptr) : _ptr(ptr) {};
			
			RandomAccessReverseIterator(RandomAccessReverseIterator const & src) {
				*this = src;
			};
			
			RandomAccessReverseIterator & operator = (RandomAccessReverseIterator const & src) {
				if (this != &src)
					this->_ptr = src._ptr;
				return (*this);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			bool operator == (RandomAccessReverseIterator const & src) const {
				return (this->_ptr == src._ptr);
			}

			bool operator != (RandomAccessReverseIterator const & src) const {
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

			friend RandomAccessReverseIterator operator ++ (RandomAccessReverseIterator & it) {
				it++;
				return (it);
			};

			RandomAccessReverseIterator operator ++ (int)
			{
				RandomAccessReverseIterator ret_it(*this);
				this->_ptr--;
				return (ret_it);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			friend RandomAccessReverseIterator operator -- (RandomAccessReverseIterator & it) {
				it--;
				return (it);
			};

			RandomAccessReverseIterator operator -- (int)
			{
				RandomAccessReverseIterator ret_it(*this);
				this->_ptr++;
				return (ret_it);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			RandomAccessReverseIterator operator + (int n) const {
				RandomAccessReverseIterator ret_it(this->_ptr - n);
				return (ret_it);
			};

			friend RandomAccessReverseIterator operator + (int n, RandomAccessReverseIterator const & it) {
				RandomAccessReverseIterator ret_it(it._ptr - n);
				return (ret_it);
			};

			RandomAccessReverseIterator operator - (int n) const {
				RandomAccessReverseIterator ret_it(this->_ptr + n);
				return (ret_it);
			};

			difference_type operator - (RandomAccessReverseIterator const & it) const {
				difference_type ret = this->_ptr + it._ptr;
				return (ret);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			bool operator < (RandomAccessReverseIterator const & it) const {
				return (this->_ptr > it._ptr);
			};

			bool operator > (RandomAccessReverseIterator const & it) const {
				return (this->_ptr < it._ptr);
			};

			bool operator <= (RandomAccessReverseIterator const & it) const {
				return (this->_ptr >= it._ptr);
			};

			bool operator >= (RandomAccessReverseIterator const & it) const {
				return (this->_ptr <= it._ptr);
			};

	// ----------------------------------------------------------------------------------------------------------- //

			RandomAccessReverseIterator & operator += (int n) {
				this->_ptr -= n;
				return (*this);
			}

			RandomAccessReverseIterator & operator -= (int n) {
				this->_ptr += n;
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