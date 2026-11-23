#include "IntegerVectorIterator.h"
#include <iostream>

IntegerVector::IntegerVector() : IntegerVector(DEFAULT_CAPACITY) {}
IntegerVector::IntegerVector(int size) : capacity(size), numElts(0), data{new int[size]} {}
IntegerVector::IntegerVector(const IntegerVector &other) : capacity{other.capacity}, numElts{other.numElts}
{
    std::cout << "Copy constructor of IntegerVector called" << std::endl;
    data = new int[capacity];
    for (int i = 0; i < numElts; ++i)
    {
        data[i] = other.data[i];
    }
}
IntegerVector &IntegerVector::operator=(const IntegerVector &other)
{
    std::cout << "Assignment operator of IntegerVector called" << std::endl;
    if (this != &other)
    {                              // check for self-assignment
        delete[] data;             // delete left size data
        capacity = other.capacity; // copy the member variables
        numElts = other.numElts;
        data = new int[capacity]; // allocate new memory for the left side data
        for (int i = 0; i < numElts; ++i)
        {
            data[i] = other.data[i]; // loop and copy elt by elt
        }
    }
    return *this;
}
int IntegerVector::operator[](int i) const
{
    return data[i]; // note: no bounds checking
}
int &IntegerVector::operator[](int i)
{
    return data[i]; // note: no bounds checking
}
int &IntegerVector::at(int i)
{
    if (i < 0 || i >= numElts)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[i];
}
// no return type, same name as class with ~
// job is to free up memory allocated in the constructor
IntegerVector::~IntegerVector()
{
    std::cout << "Destructor of IntegerVector called" << std::endl;
    delete[] data;
}
void IntegerVector::print() const
{
    std::cout << "[";
    for (int i = 0; i < numElts - 1; ++i)
    {
        std::cout << data[i] << ", ";
    }
    if (numElts > 0)
    {
        std::cout << data[numElts - 1]; // print last elt
    }
    std::cout << "]" << std::endl;
}
void IntegerVector::push_back(int value)
{
    if (numElts == capacity)
    {      
      std::cout << "Resizing from capacity " << capacity << " to " << (capacity * 2 + 1) << std::endl;
      resize(capacity*2+1);
    }
    data[numElts] = value;
    numElts++;
}
void IntegerVector::resize(int cap)
{
    int *newData = new int[cap];
    // copy old values into newData
    for (int i = 0; i < numElts; ++i)
    {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = cap;
}
// iterator support
IntegerVector::IntegerVectorIterator IntegerVector::begin()
{
    return IntegerVectorIterator(data);
}