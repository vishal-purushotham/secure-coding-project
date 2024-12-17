#include "DynamicArray.h"
#include <iostream>
#include <new>

using namespace std;

// Constructor
DynamicArray::DynamicArray(size_t initialCapacity)
    : capacity(initialCapacity), size(0), isDeallocated(false) {
    data=new(nothrow) long long int[capacity];
    if(!data)throw runtime_error("Memory allocation failed!");
}

// Destructor
DynamicArray::~DynamicArray() {
    secureDeallocate();
}

// Resize the array
void DynamicArray::resize(size_t newCapacity) {
    if(isDeallocated)throw runtime_error("Operation on deallocated memory!");
    long long int* temp=new(nothrow) long long int[newCapacity];
    if(!temp)throw runtime_error("Memory allocation failed during resize!");
    for(size_t i=0;i<size;++i)temp[i]=data[i];
    delete[] data;
    data=temp;
    capacity=newCapacity;
}

// Validate index
void DynamicArray::validateIndex(size_t index) const {
    if(isDeallocated)throw runtime_error("Access on deallocated memory!");
    if(index>=size)throw out_of_range("Index out of bounds!");
}

// Add an element
void DynamicArray::add(long long int value) {
    if(isDeallocated)throw runtime_error("Operation on deallocated memory!");
    if(size==capacity)resize(capacity*2);
    data[size++]=value;
}

// Remove an element
void DynamicArray::remove(size_t index) {
    validateIndex(index);
    for(size_t i=index;i<size-1;++i)data[i]=data[i+1];
    size--;
    if(size>0&&size==capacity/4)resize(capacity/2);
}

// Get an element
long long int DynamicArray::get(size_t index) const {
    validateIndex(index);
    return data[index];
}

// Set an element
void DynamicArray::set(size_t index, long long int value) {
    validateIndex(index);
    data[index]=value;
}

// Get current size
size_t DynamicArray::getSize() const {
    return size;
}

// Get current capacity
size_t DynamicArray::getCapacity() const {
    return capacity;
}

// Display all elements
void DynamicArray::display() const {
    cout<<"Array elements: ";
    for(size_t i=0;i<size;++i)cout<<data[i]<<" ";
    cout<<endl;
}

// Secure deallocation of memory
void DynamicArray::secureDeallocate() {
    if(!isDeallocated) {
        delete[] data;
        data=nullptr;
        isDeallocated=true;
    }
}

