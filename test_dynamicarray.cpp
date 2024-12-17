#include "DynamicArray.h"
#include <gtest/gtest.h>

// Test Case 1: Adding elements to the dynamic array
TEST(DynamicArrayTest, AddElements) {
    DynamicArray arr;
    arr.add(10);
    arr.add(20);
    arr.add(30);

    EXPECT_EQ(arr.get(0), 10); // Check first element
    EXPECT_EQ(arr.get(1), 20); // Check second element
    EXPECT_EQ(arr.get(2), 30); // Check third element
    EXPECT_EQ(arr.getSize(), 3); // Check size of the array
    EXPECT_GE(arr.getCapacity(), 4); // Check capacity is at least 4
}

// Test Case 2: Removing an element by index
TEST(DynamicArrayTest, RemoveElement) {
    DynamicArray arr;
    arr.add(10);
    arr.add(20);
    arr.add(30);

    arr.remove(1); // Remove element at index 1 (20)
    EXPECT_EQ(arr.get(0), 10); // First element remains unchanged
    EXPECT_EQ(arr.get(1), 30); // Second element shifts
    EXPECT_EQ(arr.getSize(), 2); // Size decreases
}

// Test Case 3: Accessing an invalid index
TEST(DynamicArrayTest, AccessInvalidIndex) {
    DynamicArray arr;
    arr.add(10);

    try {
        arr.get(5); // Access out-of-bounds index
        FAIL() << "Expected out_of_range exception";
    } catch (const std::out_of_range& e) {
        EXPECT_EQ(std::string(e.what()), "Index out of bounds!");
    } catch (...) {
        FAIL() << "Expected std::out_of_range";
    }
}

// Test Case 4: Secure deallocation of memory
TEST(DynamicArrayTest, SecureDeallocate) {
    DynamicArray arr;
    arr.add(10);
    arr.secureDeallocate(); // Free the memory

    try {
        arr.add(20); // Attempt operation on deallocated memory
        FAIL() << "Expected runtime_error exception";
    } catch (const std::runtime_error& e) {
        EXPECT_EQ(std::string(e.what()), "Operation on deallocated memory!");
    } catch (...) {
        FAIL() << "Expected std::runtime_error";
    }
}

// Test Case 5: Resizing the dynamic array
TEST(DynamicArrayTest, DynamicResizing) {
    DynamicArray arr;
    for(int i = 0; i < 10; ++i) {
        arr.add(i * 100); // Add multiple elements
    }

    EXPECT_EQ(arr.getSize(), 10); // Size should be 10
    EXPECT_GE(arr.getCapacity(), 16); // Capacity should grow dynamically
    EXPECT_EQ(arr.get(0), 0); // Check first element
    EXPECT_EQ(arr.get(9), 900); // Check last element
}

