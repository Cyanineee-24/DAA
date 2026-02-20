class List
{
public:
    virtual int add(int) = 0;
    virtual int get(int pos) = 0;
    virtual void swap(int pos1, int pos2) = 0;
    virtual void print() = 0;
    virtual int size() = 0;
    virtual void bubbleSort() = 0;
    virtual void selectionSort() = 0;
    virtual void insertionSort() = 0;
};