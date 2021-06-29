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

    VectorIterator(VectorIterator & src) {
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

    // value_type & operator*(void) {
    //     return (*_ptr);
    // };

    friend value_type & operator* (const VectorIterator & v1) {
        return (*(v1._ptr));
    };
    // VectorIterator & operator++ (void) {
    //     _ptr++;
    //     return (*this);
    // };
    // VectorIterator & operator-- (void) {
    //     _ptr--;
    //     return (*this);
    // };

private:
    pointer _ptr;
};

#endif