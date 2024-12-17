#include <iostream>
#include "DynamicArray.h"

using namespace std;

void runTestCases() {
    DynamicArray arr;

    cout<<"==== Test Case 1: Add Elements ===="<<endl;
    arr.add(10);
    arr.add(9223372036854775807); // Large value
    arr.add(-9223372036854775807); // Negative large value
    arr.display();

    cout<<"==== Test Case 2: Access Valid Index ===="<<endl;
    cout<<"Element at index 1: "<<arr.get(1)<<endl;

    cout<<"==== Test Case 3: Access Invalid Index ===="<<endl;
    try {
        cout<<arr.get(5)<<endl;
    } catch(const exception& e) {
        cerr<<"Error: "<<e.what()<<endl;
    }

    cout<<"==== Test Case 4: Modify Element ===="<<endl;
    arr.set(1,5000000000LL);
    arr.display();

    cout<<"==== Test Case 5: Remove Element at Valid Index ===="<<endl;
    arr.remove(1);
    arr.display();

    cout<<"==== Test Case 6: Remove Element at Invalid Index ===="<<endl;
    try {
        arr.remove(5);
    } catch(const exception& e) {
        cerr<<"Error: "<<e.what()<<endl;
    }

    cout<<"==== Test Case 7: Add Multiple Elements and Resize ===="<<endl;
    for(long long int i=1;i<=10;++i)arr.add(i*1000000000LL);
    arr.display();

    cout<<"==== Test Case 8: Display Capacity ===="<<endl;
    cout<<"Capacity: "<<arr.getCapacity()<<", Size: "<<arr.getSize()<<endl;

    cout<<"==== Test Case 9: Remove All Elements ===="<<endl;
    while(arr.getSize()>0)arr.remove(0);
    arr.display();

    cout<<"==== Test Case 10: Access After Removing All Elements ===="<<endl;
    try {
        cout<<arr.get(0)<<endl;
    } catch(const exception& e) {
        cerr<<"Error: "<<e.what()<<endl;
    }

    cout<<"==== Test Case 11: Add After Clearing Array ===="<<endl;
    arr.add(100);
    arr.display();

    cout<<"==== Test Case 12: Secure Deallocate ===="<<endl;
    arr.secureDeallocate();

    cout<<"==== Test Case 13: Operation on Deallocated Memory ===="<<endl;
    try {
        arr.add(200);
    } catch(const exception& e) {
        cerr<<"Error: "<<e.what()<<endl;
    }

    cout<<"==== Test Case 14: Reinitialize and Add ===="<<endl;
    DynamicArray arr2;
    arr2.add(1);
    arr2.add(2);
    arr2.display();

    cout<<"==== Test Case 15: Remove Element from Small Array ===="<<endl;
    arr2.remove(0);
    arr2.display();

    cout<<"==== Test Case 16: Add Large Numbers ===="<<endl;
    arr2.add(999999999999LL);
    arr2.display();

    cout<<"==== Test Case 17: Add and Modify ===="<<endl;
    arr2.set(0,888888888888LL);
    arr2.display();

    cout<<"==== Test Case 18: Add 20 Elements ===="<<endl;
    for(int i=0;i<20;++i)arr2.add(i);
    arr2.display();

    cout<<"==== Test Case 19: Remove All but One ===="<<endl;
    while(arr2.getSize()>1)arr2.remove(0);
    arr2.display();

    cout<<"==== Test Case 20: Final Capacity Check ===="<<endl;
    cout<<"Capacity: "<<arr2.getCapacity()<<", Size: "<<arr2.getSize()<<endl;
}

int main() {
    try {
        runTestCases();
    } catch(const exception& e) {
        cerr<<"Fatal error: "<<e.what()<<endl;
    }

    return 0;
}

