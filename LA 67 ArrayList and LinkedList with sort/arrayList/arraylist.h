#include "list.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class ArrayList : public List {
    int* array;
    int capacity;
    int curr_size;

    // Logic: If size >= 75% of capacity, increase capacity by 50%
    void dynamicAdd() {
        if (curr_size >= (capacity * 0.75)) {
            int new_capacity = capacity + (capacity / 2);
            if (new_capacity <= capacity) new_capacity++; // Ensure it grows at least by 1
            
            int* new_array = (int*)realloc(array, sizeof(int) * new_capacity);
            if (new_array) {
                array = new_array;
                capacity = new_capacity;
                cout << "\n[System] Capacity increased to: " << capacity << endl;
            }
        }
    }

public:
    ArrayList() {
        capacity = 5;
        curr_size = 0;
        array = (int*)malloc(sizeof(int) * capacity);
    }

    int add(int num) {
        dynamicAdd(); // Check for resize before adding
        array[curr_size++] = num;
        return curr_size;
    }

    int get(int pos) {
        if (pos < 0 || pos >= curr_size) return -1;
        return array[pos];
    }

    void swap(int pos1, int pos2) {
        if (pos1 < 0 || pos1 >= curr_size || pos2 < 0 || pos2 >= curr_size) return;
        int temp = array[pos1];
        array[pos1] = array[pos2];
        array[pos2] = temp;
    }

    int size() {
        return curr_size;
    }

    void print() {
        if (curr_size == 0) {
            cout << "(empty)" << endl;
            return;
        }
        for (int i = 0; i < curr_size; i++) {
            cout << array[i] << (i == curr_size - 1 ? "" : " -> ");
        }
        cout << " [Size: " << curr_size << "/" << capacity << "]" << endl;
    }

    void bubbleSort() {
        for (int i = 0; i < curr_size - 1; i++) {
            for (int j = 0; j < curr_size - i - 1; j++) {
                if (array[j] > array[j + 1]) swap(j, j + 1);
            }
        }
    }

    void selectionSort() {
        for (int i = 0; i < curr_size - 1; i++) {
            int min = i;
            for (int j = i + 1; j < curr_size; j++) {
                if (array[j] < array[min]) min = j;
            }
            swap(i, min);
        }
    }

    void insertionSort() {
        for (int i = 1; i < curr_size; i++) {
            int j = i;
            while (j > 0 && array[j] < array[j - 1]) {
                swap(j, j - 1);
                j--;
            }
        }
    }

    // Destructor to prevent memory leaks
    ~ArrayList() {
        free(array);
    }
};