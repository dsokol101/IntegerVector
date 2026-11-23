#ifndef INTEGERVECTOR_H
#define INTEGERVECTOR_H

// forward declaration of the IntegerVectorIterator class

class IntegerVector
{
private:
    int *data;
    int capacity;
    int numElts;
    static const int DEFAULT_CAPACITY = 0;
    void resize(int newCapacity);

public:
    class IntegerVectorIterator; // forward declaration of the nested iterator class
    IntegerVector();
    IntegerVector(int size);
    // Rule of 3: copy constr, destructor, assignment operator
    IntegerVector(const IntegerVector &other); // copy constructor
    // destructor
    ~IntegerVector();
    // assignment operator
    IntegerVector &operator=(const IntegerVector &other);
    void push_back(int value);
    int operator[](int index) const; // subscript operator
    int &operator[](int index);      // allows an lvalue to be returned so that the value can be modified
    int size() const { return numElts; }
    int &at(int index);
    void print() const;
    //  iterator support (not recommended to give direct access to the underlying data)
    IntegerVectorIterator begin();
    IntegerVectorIterator end();

    class IntegerVectorIterator
    {
    private:
        int *current;

    public:
        IntegerVectorIterator(int *ptr) : current(ptr) {}
        int &operator*() { return *current; }
        IntegerVectorIterator &operator++()
        {
            ++current;
            return *this;
        }
        bool operator!=(const IntegerVectorIterator &other) const { return current != other.current; }
        bool operator==(const IntegerVectorIterator &other) const { return current == other.current; }
    };
};


#endif