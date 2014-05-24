#ifndef VECTORINT_H
#define VECTORINT_H
#include <iostream>
using namespace std;

class VectorInt
{
public:
    /**
     * allocates a 32 element vetor by default
     */
    VectorInt ();

    /**
     * destorys the memory in use by the vector
     */
    ~VectorInt();

    /**
     * allocates a vector specified by size arg
     */
    VectorInt (unsigned size);

    /**
     * copy constructor
     */
    VectorInt (const VectorInt &other);

    /**
     * assignment operator
     */
    VectorInt& operator= (const VectorInt &other);

    /**
     * returns the value at the specified index
     */
    int get (unsigned idx);

    /**
     * sets the value at idx with value if and only if a
     * value exists at that index
     */
    bool set (unsigned idx, int value);

    /**
     * adds an element to the end of the array, resizing if
     * necessary
     */
    VectorInt& push_back (int val);

    /**
     * adds an element to the front of the array, resizing if
     * necessary
     */
    VectorInt& push_front (int val);

    /**
     * prints all the elements in the VectorInt
     */
    friend ostream& operator << (ostream &os, const VectorInt &vec);

private:
    int *_data;
    unsigned _size;
    unsigned _elements;
};

#endif /* VECTORINT_H */
