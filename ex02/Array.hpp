#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template< typename T>
class Array {

    public:
        Array<T>();
        Array<T>(unsigned int n);
        Array<T>(const Array<T> & instance);
        ~Array<T>();

        Array<T>    &operator=(const Array<T> &instance);
        T           &operator[](const size_t &i) const;

        size_t size() const;

        class IndexInvalidException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Index is not valid";	
                }
        };

    private:
        T 		*_values;
        size_t	_size;
};

// ---------Constructor and destructor ------------

template <typename T>
Array<T>::Array() : _values(NULL), _size(0) {
	std::cout << "Constructor called" << std::endl;
    this->_values = new T[0];
}

template <typename T>
Array<T>::Array( unsigned int n ) : _values(NULL), _size(n) {
	std::cout << "Constructor called" << std::endl;
    this->_values = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T>& instance) {
    *this = instance;
}

template <typename T>
Array<T>::~Array() {
	std::cout << "Destructor called" << std::endl;
    delete [] this->_values;
}

// --------- Fonctions ------------

template <typename T>
size_t Array<T>::size() const {
    return this->_size;
}

// --------- Operator overload ------------

template <typename T>
Array<T> &Array<T>::operator=(const  Array<T> &instance) {
    std::cout << "An Array is copied" << std::endl;
    this->_values = new T[instance._size];
    this->_size = instance._size;
    for (size_t i = 0; i < instance._size; ++i) {
        this->_values[i] = instance[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](const size_t &i) const {
  if (i >= this->_size)
    throw Array<T>::IndexInvalidException();
  return (this->_values[i]);
}

#endif