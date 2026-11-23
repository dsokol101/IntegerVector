#include "IntegerVectorIterator.h"
#include <iostream>
void someFunction();

int main() {
    IntegerVector vec{};
    std::cout << "vec: ";
    vec.print();
    std::cout << "Size of vec: " << vec.size() << std::endl;
    vec.push_back(99);
    vec.push_back(100);
    std::cout << "After pushing back 99 and 100, vec: ";
    std::cout << "Element at index 1: " << vec[1] << std::endl;
    vec[0]= 10; 
    std::cout << "After modifying element at index 0 vec: ";
    //vec.print();
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    // what about range based for loop?
    std::cout << "Using range based for loop: ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    someFunction();
    IntegerVector vec2 = vec; // copy constructor
    vec = vec2; // assignment operator
    IntegerVector *vecPtr = new IntegerVector(vec); // copy constructor

    delete vecPtr; // this will call the destructor of IntegerVector and free up the memory allocated in the constructor
    return 0;
}
void someFunction() {
    IntegerVector vec(10); // declare a local IntegerVector object on the stack
    // this is automatic storage, so it will be destroyed when the function exits
    // and at that moment, the destructor will be called to free up the memory allocated in the constructor
}