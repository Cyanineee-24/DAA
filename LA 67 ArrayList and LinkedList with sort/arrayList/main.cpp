#include <iostream>
#include "arraylist.h"

using namespace std;

int main() {
    List *list = new ArrayList();
    int choice, val, p1, p2;

    while (true) {
        cout << "\n--- ArrayList Menu ---" << endl;
        cout << "1. Add Element" << endl;
        cout << "2. Get Element" << endl;
        cout << "3. Swap Elements" << endl;
        cout << "4. Print List" << endl;
        cout << "6. Bubble Sort" << endl;
        cout << "7. Selection Sort" << endl;
        cout << "8. Insertion Sort" << endl;
        cout << "0. Exit" << endl; // Exit is now 0
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list->add(val);
                break;
            case 2:
                cout << "Enter position (0-based): ";
                cin >> p1;
                val = list->get(p1);
                if (val != -1) cout << "Value: " << val << endl;
                else cout << "Invalid position!" << endl;
                break;
            case 3:
                cout << "Enter first position: ";
                cin >> p1;
                cout << "Enter second position: ";
                cin >> p2;
                list->swap(p1, p2);
                break;
            case 4:
                list->print();
                break;
            case 6:
                list->bubbleSort();
                list->print();
                break;
            case 7:
                list->selectionSort();
                list->print();
                break;
            case 8:
                list->insertionSort();
                list->print();
                break;
            case 0: // Updated exit case
                cout << "Exiting program. Cleaning up memory..." << endl;
                delete list; 
                return 0;    
            default:
                cout << "Invalid choice. Please choose 0-4 or 6-8." << endl;
        }
    }
}