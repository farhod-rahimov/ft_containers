#ifndef VECTOR_ITERATORS_HPP
# define VECTOR_ITERATORS_HPP

#include <iostream> // delete

template<typename T>
class VectorIterator {
public:
    typedef T           value_type;
    typedef T *         pointer;

    //BASIC STUFF //BASIC STUFF //BASIC STUFF //BASIC STUFF //BASIC STUFF 
    VectorIterator() {
    };

    VectorIterator(pointer ptr) : _ptr(ptr) {
    };

    virtual ~VectorIterator() {
    };

    VectorIterator(VectorIterator const & src) {
        *this = src;
    };

    VectorIterator &operator=(VectorIterator const &src) {
        if (this != &src)
            _ptr = src._ptr;
        return (*this);
    };

    bool operator==(const VectorIterator & other) {
        if (_ptr == other._ptr)
            return (true);
        return (false);
    };

    bool operator!=(const VectorIterator & other) {
        if (_ptr != other._ptr)
            return (true);
        return (false);
    };

    value_type & operator*(void) {
        return (*_ptr);
    };

    value_type *operator->(void) {
        return (_ptr);
    };

    // VectorIterator &operator++(void) {
    //     _ptr++;
    //     return (*this);
    // };

    // VectorIterator &operator--(void) {
    //     _ptr--;
    //     return (*this);
    // };

    VectorIterator operator++(int)
    {
        VectorIterator tmp(*this);
        this->_ptr++;
        // operator++();
        return (tmp);
    };

    VectorIterator operator--(int)
    {
        VectorIterator tmp(*this);
        this->_ptr--;
        // operator--();
        return (tmp);
    };

    VectorIterator operator+(int n) const {
        VectorIterator tmp(*this);
        tmp += n;
        return (tmp);
    };

    VectorIterator operator-(int n) const {
        VectorIterator tmp(*this);
        tmp -= n;
        return (tmp);
    };

    bool operator<(VectorIterator const &other) const {
        return (_ptr < other._ptr);
    };

    bool operator<=(VectorIterator const &other) const {
        return (_ptr <= other._ptr);
    };
    
    bool operator>(VectorIterator const &other) const {
        return (_ptr > other._ptr);
    };
    
    bool operator>=(VectorIterator const &other) const {
        return (_ptr >= other._ptr);
    };

    VectorIterator & operator+=(int n) {
        _ptr += n;
        return (*this);
    };

    VectorIterator & operator-=(int n) {
        _ptr -= n;
        return (*this);
    };

    value_type & operator[](int n) {
        return (_ptr[n]);
    };

private:
    pointer _ptr;
};

#endif