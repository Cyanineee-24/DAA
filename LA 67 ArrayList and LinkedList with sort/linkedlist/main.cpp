
#include <iostream>
#include "linkedlist.h"

using namespace std;
int main()
{
    List *list = new LinkedList();
    int choice, val, p1, p2;

    while (true)
    {
        cout << "\n--- Linked List Menu ---" << endl;
        cout << "1. Add Element" << endl;
        cout << "2. Get Element" << endl;
        cout << "3. Swap Nodes" << endl;
        cout << "4. Print List" << endl;
        cout << "5. Exit" << endl;
        cout << "6. Bubble Sort" << endl;
        cout << "7. Selection Sort" << endl;
        cout << "8. Insertion Sort" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to add: ";
            cin >> val;
            list->add(val);
            break;
        case 2:
            cout << "Enter position: ";
            cin >> p1;
            val = list->get(p1);
            if (val != -1)
                cout << "Value: " << val << endl;
            break;
        case 3:
            cout << "Positions to swap: ";
            cin >> p1 >> p2;
            list->swap(p1, p2);
            break;
        case 4:
            list->print();
            break;
        case 5:
            delete list;
            return 0;
        case 6:
            list->bubbleSort();
            cout << "Sorted using Bubble Sort!" << endl;
            list->print();
            break;
        case 7:
            list->selectionSort();
            cout << "Sorted using Selection Sort!" << endl;
            list->print();
            break;
        case 8:
            list->insertionSort();
            cout << "Sorted using Insertion Sort!" << endl;
            list->print();
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    }
    return 0;
}