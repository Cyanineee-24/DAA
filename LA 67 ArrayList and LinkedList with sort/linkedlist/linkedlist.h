#include "list.h"
#include "node.h"
#include <iostream>
#include <algorithm>

using namespace std;

class LinkedList : public List
{
    node *head;
    node *tail;
    int index;

    node *create_node(int num)
    {
        node *newNode = (node *)malloc(sizeof(node));
        newNode->element = num;
        newNode->next = nullptr;
        return newNode;
    }

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        index = 0;
    }

    // 0 - based index
    int add(int num)
    {
        node *n = create_node(num);
        if (index <= 0)
        {
            head = tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
        return ++index;
    }

    // 0 - based index
    int get(int pos)
    {
        node *curr = head;
        int count = 0;

        while (curr != nullptr)
        {
            if (count == pos)
            {
                return curr->element;
            }
            count++;
            curr = curr->next;
        }
    }

    void swap(int pos1, int pos2)
    {
        if (pos1 == pos2)
            return;

        node *prev1, *cur1, *prev2, *cur2;
        getNodeInfo(pos1, prev1, cur1);
        getNodeInfo(pos2, prev2, cur2);

        if (!cur1 || !cur2)
            return;

        // 1. Update predecessors
        if (prev1)
            prev1->next = cur2;
        else
            head = cur2;

        if (prev2)
            prev2->next = cur1;
        else
            head = cur1;

        // 2. Fix the "Next" pointers (Handling Adjacency)
        if (cur1->next == cur2)
        { // cur1 is right before cur2
            cur1->next = cur2->next;
            cur2->next = cur1;
        }
        else if (cur2->next == cur1)
        { // cur2 is right before cur1
            cur2->next = cur1->next;
            cur1->next = cur2;
        }
        else
        { // Nodes are apart
            node *temp = cur1->next;
            cur1->next = cur2->next;
            cur2->next = temp;
        }

        // 3. Update the tail pointer if necessary
        if (cur1->next == nullptr)
            tail = cur1;
        else if (cur2->next == nullptr)
            tail = cur2;
    }

    // Helper to find node and its predecessor at a given index
    void getNodeInfo(int pos, node *&prev, node *&cur)
    {
        prev = nullptr;
        cur = head;
        while (pos > 0 && cur != nullptr)
        {
            prev = cur;
            cur = cur->next;
            pos--;
        }
    }

    int size()
    {
        return index;
    }

    // BUBBLE SORT
    void bubbleSort()
    {
        int n = size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (get(j) > get(j + 1))
                {
                    swap(j, j + 1);
                }
            }
        }
    }

    // SELECTOIN SORT
    void selectionSort()
    {
        int n = size();
        for (int i = 0; i < n - 1; i++)
        {
            int min_idx = i;
            for (int j = i + 1; j < n; j++)
            {
                if (get(j) < get(min_idx))
                {
                    min_idx = j;
                }
            }
            if (min_idx != i)
            {
                swap(i, min_idx);
            }
        }
    }

    void insertionSort()
    {
        int n = size();
        for (int i = 1; i < n; i++)
        {
            int j = i;
            // Move the current element back until it's in the correct spot
            while (j > 0 && get(j) < get(j - 1))
            {
                swap(j, j - 1);
                j--;
            }
        }
    }
    // DO NOT MODIFY this print method
    void print()
    {
        node *currnode = head;
        if (head == nullptr && tail == nullptr)
        {
            cout << "(empty)";
            return;
        }
        while (true)
        {
            cout << currnode->element;
            if (currnode == tail)
            {
                cout << endl;
                return;
            }
            cout << " -> ";
            currnode = currnode->next;
        }
    }
};