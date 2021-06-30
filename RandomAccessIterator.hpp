#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

template <typename T>
class RandomAccessIterator {
public:
        typedef std::ptrdiff_t							difference_type;
        typedef T										value_type;
        
        typedef T *                                     pointer;
        typedef T const *                       		const_pointer;
        
        typedef T &                                     reference;
        typedef T const &                   			const_reference;
        
        typedef std::random_access_iterator_tag         iterator_category;

        typedef RandomAccessIterator<value_type>		iterator;
        // typedef RandomAccessIterator<value_type const>	const_iterator;
        // typedef ReverseIterator<iterator>				reverse_iterator;
        // typedef ReverseIterator<const_iterator>			const_reverse_iterator;

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

#endif