#include <iostream>
using namespace std;

int main() {
    int a = 10; // Stack allocation
    int* b = new int(20); // Heap allocation
    int arr[5]; // Stack allocation
    int* arr2 = new int[5]; // Heap allocation

    // Modifications:
    int added1 = 67; // my stack allocation example
    int* added2 = new int(143); // my heap allocation example


    cout << "a: " << a << endl;
    cout << "*b: " << *b << endl;
    cout << "added1: " << added1 << endl;
    cout << "*added2: " << *added2 << endl;

    delete b;
    //   delete added2 (omitted)

    // try to access an already deleted pointer
    cout << "Accessing *b again: " << *b << endl;
    delete[] arr2;
    return 0;
}