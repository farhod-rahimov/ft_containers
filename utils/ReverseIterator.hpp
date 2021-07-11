#ifndef REVERSE_ITERATOR_HPP
#define  REVERSE_ITERATOR_HPP

#include "IteratorTraits.hpp"

namespace ft {
	
	template <class Iterator>
	class  reverse_iterator {
	public:
			typedef	Iterator												iterator_type;
			typedef	typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef	typename iterator_traits<Iterator>::value_type			value_type;
			typedef	typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef	typename iterator_traits<Iterator>::pointer				pointer;
			typedef	typename iterator_traits<Iterator>::reference			reference;

			reverse_iterator() {};

			explicit reverse_iterator (iterator_type it) : _base(--it) {};

			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter> & rev_it) {
				*this = rev_it;
			};

			template <class Iter>
			reverse_iterator & operator = (const reverse_iterator<Iter>& rev_it) {
				if (this != &rev_it) {
					_base = rev_it._base;
				}
				return *this;
			}

			iterator_type base() const {
				iterator_type ret(this->_base);
				return (++ret);
			};

			reference operator * () const {
				return (*_base);
			}

			reverse_iterator operator + (difference_type n) const {
				reverse_iterator tmp(*this);
				tmp._base = tmp._base - n;
				return tmp;
			}

			reverse_iterator & operator ++ () {
				--_base;
				return *this;
			}

			reverse_iterator operator ++ (int) {
				reverse_iterator tmp(*this);
				--_base;
				return tmp;
			}

			reverse_iterator& operator+=(difference_type n) {
				_base = _base - n;
				return *this;
			}

			reverse_iterator operator - (difference_type n) const {
				reverse_iterator tmp(*this);
				tmp._base = tmp._base + n;
				return tmp;
			}

			reverse_iterator & operator -- () {
				++_base;
				return *this;
			}

			reverse_iterator operator -- (int)
			{
				reverse_iterator tmp(*this);
				++_base;
				return tmp;
			}

			reverse_iterator & operator -= (difference_type n) {
				_base = _base + n;
				return *this;
			}

			pointer operator -> () const {
				return (&(operator*()));
			}

			reference operator [] (difference_type n) const {
				return (_base[-n - 1]);
			}

			template <class it>
			friend bool operator == (const reverse_iterator & lhs, const reverse_iterator<it> & rhs) {
				return lhs._base == rhs._base;
			}
			
			template <class it>
			friend bool operator != (const reverse_iterator & lhs, const reverse_iterator<it> & rhs) {
				return lhs._base != rhs._base;
			}
			
			template <class it>
			friend bool operator < (const reverse_iterator & lhs, const reverse_iterator<it> & rhs) {
				return lhs._base > rhs._base;
			}
			
			template <class it>
			friend bool operator <= (const reverse_iterator & lhs, const reverse_iterator<it> & rhs) {
				return lhs._base >= rhs._base;
			}
			
			template <class it>
			friend bool operator > (const reverse_iterator & lhs, const reverse_iterator<it>&  rhs) {
				return lhs._base < rhs._base;
			}
			
			template <class it>
			friend bool operator >= (const reverse_iterator & lhs, const reverse_iterator<it> & rhs) {
				return lhs._base <= rhs._base;
			}


	private:
		iterator_type _base;

	};

	template <class Iterator>
	ft::reverse_iterator<Iterator> operator + (typename ft::reverse_iterator<Iterator>::difference_type n,
												const ft::reverse_iterator<Iterator> & rev_it) {
		return ft::reverse_iterator<Iterator>(rev_it + n);
	}

	template <class Iterator>
	ft::reverse_iterator<Iterator> operator - (typename ft::reverse_iterator<Iterator>::difference_type n,
												const ft::reverse_iterator<Iterator> & rev_it) {
		return ft::reverse_iterator<Iterator>(rev_it - n);
	}
};

#endif