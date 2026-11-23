## RAII summary

When a class has a resource, RAII demands that the designer of the class "take care" of the resource.
In our example, the resource is the pointer.

- allocate properly
- deallocate (free) properly
- copy using copy constructor
- copy using operator=


"Rule of three" -- copy constr, op=, destructor
"Rule of five" -- move constr, move op=

## Classes in this Repository

### IntegerVector
A template-based dynamic array container class that manages a collection of integers with dynamic memory allocation. 

**Key Features:**
- **Dynamic Growth**: Automatically resizes when capacity is exceeded
- **RAII Compliance**: Properly manages memory through constructors, destructors, and assignment operators
- **Copy Semantics**: Implements the "Rule of Three" with copy constructor, assignment operator, and destructor
- **Random Access**: Provides index-based access through the `operator[]` subscript operator
- **Iterator Support**: Includes custom iterator support for range-based operations

**Main Methods:**
- `IntegerVector()` - Default constructor with default capacity
- `IntegerVector(int size)` - Constructor with specified initial size
- `push_back(int value)` - Adds an element to the end, resizing if necessary
- `operator[](int index)` - Array-like access to elements
- `size()` - Returns the current number of elements
- `at(int index)` - Provides bounds-checked element access
- `print()` - Outputs all elements in the vector
- `begin()` / `end()` - Return iterators for range-based loops

**Member Variables:**
- `data` - Pointer to the dynamically allocated integer array
- `capacity` - Current maximum size before resizing
- `numElts` - Current number of elements in the vector

### IntegerVectorIterator
A nested iterator class within IntegerVector that provides iterator functionality for traversing elements.

**Key Features:**
- **Encapsulation**: Defined as a nested class within IntegerVector
- **Dereference Operator**: Provides access to the underlying integer via `operator*`
- **Increment Operator**: Supports prefix increment (`operator++`) for forward traversal
- **Comparison Operators**: Supports equality (`operator==`) and inequality (`operator!=`) comparisons

**Main Methods:**
- `IntegerVectorIterator(int *ptr)` - Constructor that wraps a pointer
- `operator*()` - Dereferences the iterator to access the element
- `operator++()` - Increments the iterator to point to the next element
- `operator==()` / `operator!=()` - Compares two iterators

**Member Variables:**
- `current` - Pointer to the current element being referenced