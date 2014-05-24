/*
 * implements a type-specific vector (int) to demonstrate use of 
 * classes which must manage dynamically allocated memory - shows 
 * usage of copy constructor, destructor, and assignment operator
 */

#include <iostream>
#include <climits>
#include "VectorInt.h"

using namespace std;

/**
 * allocates a 32 element vetor by default
 */
VectorInt::VectorInt ()
    : _size(32),
      _elements(0)
{
    _data = new int[ _size ]();
}

/**
 * allocates a vector specified by size arg
 */
VectorInt::VectorInt (unsigned size)
    : _size(size),
      _elements(0)
{
    _data = new int[ _size ]();
}

/**
 * destroys mem in data pointer
 */
VectorInt::~VectorInt ()
{
    delete [] _data;
    _data = NULL;
}

/**
 * copy constructor
 */
VectorInt::VectorInt (const VectorInt &other)
    : _size(other._size),
      _elements(other._elements)
{
    _data = new int[ _size ]();
    for (unsigned i = 0; i < _elements; ++i)
        _data[i] = other._data[i];
}

/**
 * assignment operator
 */
VectorInt& VectorInt::operator= (const VectorInt &other)
{
    // check for self assignment
    if (this != &other)
    {
        // destory old memory
        delete [] _data;
	

		// reassign new memory
		_size = other._size;
		_elements = other._elements;
            
        _data = new int[ _size ]();
        for (unsigned i = 0; i < _elements; ++i)
            _data[i] = other._data[i];
    }
    return *this;
}

/**
 * returns the value at the specified index
 */
int VectorInt::get (unsigned idx)
{
    if (idx >= _elements) 
        return INT_MAX;

    return _data[ idx ];
}

/**
 * sets the value at idx with value, only if a value
 * exists at that index
 */
bool VectorInt::set (unsigned idx, int value)
{
    if (idx >= _elements)
        return false;

    _data[ idx ] = value;
    return true;
}

/**
 * adds an element to the end of the array, resizing if
 * necessary
 */
VectorInt& VectorInt::push_back (int val)
{
    // the new elem
    ++_elements;

    // resize if elements greater than or equal to size
    if (_elements > _size)
    {
        int *old_data = _data;
        _size *= 1.5;
        _data = new int[ _size ]();
        
        // copy old data
        for (unsigned i = 0; i < (_elements - 1); ++i)
            _data[i] = old_data[i];

        delete [] old_data;
    }

    // add the new guy no matter what
    _data[ _elements - 1 ] = val;

    return *this;
}

/**
 * adds an element to the front of the array, resizing if
 * necessary
 */
VectorInt& VectorInt::push_front (int val)
{
    // the new elem
    ++_elements;

    // resize the array with val at front if _elements > _size
    if (_elements > _size)
    {
        _size *= 1.5;
    }

    // put the element at front of array and copy over old data
    int *new_data = new int[ _size ]();
    new_data[ 0 ] = val;

    for (unsigned i = 0; i < (_elements - 1); ++i)
        new_data[ i + 1 ] = _data[ i ];
    
    delete[] _data;
    _data = new_data;

    return *this;
}

/**
 * prints all the elements in the VectorInt
 */
ostream& operator << (ostream &os, const VectorInt &vec)
{
    for (unsigned i = 0; i < vec._elements; ++i)
        os << vec._data[ i ] << " ";

    return os;
}

/*
 * tests
 */
int main (void)
{
    VectorInt foo;

    // test push back
    foo.push_back(5);
    foo.push_back(10);
    foo.push_back(50);

    foo.push_front(3);
    foo.push_front(2);
    foo.push_front(1);

    for (int i = 0; i < 50; ++i)
        foo.push_back(i);

    // test push front
    for (int i = 0; i < 50; ++i)
        foo.push_front(50-i);

    cout << foo << endl << endl;

    foo = VectorInt(5);
    
    for (int i = 0; i < 10; ++i)
        foo.push_front(10-i);

    VectorInt bar(20);

    for (int i = 0; i < 2000; ++i)
        bar.push_back(i);

    cout << foo << endl << endl;

    cout << bar << endl << endl;
}
