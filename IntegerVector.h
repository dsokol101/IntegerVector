#ifndef INTEGERVECTOR_H
#define INTEGERVECTOR_H

template <typename T>
class IntegerVector {
    private:
        T* data;
        int capacity;
        int numElts;
        static const int DEFAULT_CAPACITY = 0;
        void resize(int newCapacity);
    public:
        IntegerVector();
        IntegerVector(int size);
        // Rule of 3: copy constr, destructor, assignment operator
        IntegerVector(const IntegerVector& other); // copy constructor
        // destructor
        ~IntegerVector();
        // assignment operator
        IntegerVector& operator=(const IntegerVector& other);
        void push_back(int value);
        int operator[] (int index) const; // subscript operator
        int& operator[] (int index); // allows an lvalue to be returned so that the value can be modified
        int size() const { return numElts; }
        int& at(int index);
        void print() const;
        // simple iterator support (not recommended to give direct access to the underlying data)
        int *begin() { return data; }
        int *end() { return data + numElts; }

};

#endif