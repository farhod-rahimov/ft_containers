#ifndef ITERATOR_TRAITS
# define ITERATOR_TRAITS

template <class Iterator>
class iterator_traits {

};

template <class T>
class iterator_traits<T*> {

};

template <class T>
class iterator_traits<const T*> {

};


#endif