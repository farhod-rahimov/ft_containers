#ifndef STACK_HPP
# define STACK_HPP

#include "Vector.hpp"

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack {
	public:
			typedef 			Container					container_type;
			typedef	typename	container_type::value_type	value_type;
			typedef	typename	container_type::size_type	size_type;

	// INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION INITIALIZATION  //

			explicit stack (const container_type& ctnr = container_type()) {
				this->_c = ctnr;
			};

			stack (const stack & src) {
				this->_c = src._c;
			};

			virtual ~stack () {
			}

			stack & operator = (stack const & src) {
				this->_c = src._c;
				return (*this);
			};

	// MEMBER FUNCTIONS MEMBER FUNCTIONS MEMBER FUNCTIONS MEMBER FUNCTIONS MEMBER FUNCTIONS MEMBER FUNCTIONS MEMBER FUNCTIONS  //

			bool empty() const {
				return (this->_c.empty());
			};

			size_type size() const {
				return (this->_c.size());
			};

			value_type & top() {
				return (this->_c.back());
			};

			const value_type & top() const {
				return (this->_c.back());
			};

			void push (const value_type & val) {
				return (this->_c.push_back(val));
			};

			void pop() {
				return (this->_c.pop_back());
			};

	private:
			template <class TT, class CContainer>
			friend bool ft::operator == (const ft::stack<TT,CContainer> & lhs, const ft::stack<TT,CContainer> & rhs);
			template <class TT, class CContainer>
			friend bool ft::operator != (const ft::stack<TT,CContainer> & lhs, const ft::stack<TT,CContainer> & rhs);
			template <class TT, class CContainer>
			friend bool ft::operator < (const ft::stack<TT,CContainer> & lhs, const ft::stack<TT,CContainer> & rhs);
			template <class TT, class CContainer>
			friend bool ft::operator <= (const ft::stack<TT,CContainer> & lhs, const ft::stack<TT,CContainer> & rhs);
			template <class TT, class CContainer>
			friend bool ft::operator > (const ft::stack<TT,CContainer> & lhs, const ft::stack<TT,CContainer> & rhs);
			template <class TT, class CContainer>
			friend bool ft::operator >= (const ft::stack<TT,CContainer> & lhs, const ft::stack<TT,CContainer> & rhs);


			container_type _c;
	};

	// NON-MEMBER FUNCTION OVERLOADS | NON-MEMBER FUNCTION OVERLOADS | NON-MEMBER FUNCTION OVERLOADS | NON-MEMBER FUNCTION OVERLOADS //

	template <class TT, class CContainer>
	bool operator == (const ft::stack<TT,CContainer> & lhs, const ft::stack<TT,CContainer> & rhs) {
		return (lhs._c == rhs._c);
	};
	
	template <class TT, class CContainer>
	bool operator != (const ft::stack<TT,CContainer> & lhs, const ft::stack<TT,CContainer> & rhs) {
		return (lhs._c != rhs._c);
	};

	template <class TT, class CContainer>
	bool operator < (const ft::stack<TT,CContainer> & lhs, const ft::stack<TT,CContainer> & rhs) {
		return (lhs._c < rhs._c);
	};

	template <class TT, class CContainer>
	bool operator <= (const ft::stack<TT,CContainer> & lhs, const ft::stack<TT,CContainer> & rhs) {
		return (lhs._c <= rhs._c);
	};

	template <class TT, class CContainer>
	bool operator > (const ft::stack<TT,CContainer> & lhs, const ft::stack<TT,CContainer> & rhs) {
		return (lhs._c > rhs._c);
	};

	template <class TT, class CContainer>
	bool operator >= (const ft::stack<TT,CContainer> & lhs, const ft::stack<TT,CContainer> & rhs) {
		return (lhs._c >= rhs._c);
	};
}

#endif