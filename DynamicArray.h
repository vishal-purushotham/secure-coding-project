#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <cstddef>
#include <stdexcept>

class DynamicArray {
private:
    long long int* data; //pointer to the array
    size_t capacity; //maximum capacity
    size_t size; //current number of elements
    bool isDeallocated; //flag for memory deallocation

    void resize(size_t newCapacity); //resizes the array
    void validateIndex(size_t index) const; //validates the index

public:
    DynamicArray(size_t initialCapacity=4); //constructor
    ~DynamicArray(); //destructor

    void add(long long int value); //add an element
    void remove(size_t index); //remove an element
    long long int get(size_t index) const; //get element at index
    void set(size_t index, long long int value); //set value at index
    size_t getSize() const; //return current size
    size_t getCapacity() const; //return current capacity
    void display() const; //display all elements
    void secureDeallocate(); //securely deallocate memory
};

#endif // DYNAMICARRAY_H

