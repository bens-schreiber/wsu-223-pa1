#include <iostream>
#include <cstdlib>
using namespace std;

// define default capacity of the Queue
#define SIZE 10

// Class for Queue
class Queue
{
    int *arr;     // array to store Queue elements
    int capacity; // maximum capacity of the Queue
    int front;    // front points to front element in the Queue (if any)
    int rear;     // rear points to last element in the Queue
    int count;    // current size of the Queue
public:
    Queue(int size = SIZE); // constructor
    ~Queue();               // destructor
    void deQueue();
    void enQueue(const int x);
    int peek() const;
    inline int size() const { return count; }
    inline bool isEmpty() const { return size() == 0;}
    inline bool isFull() const { return size() == capacity; }
};

// Constructor to initialize Queue
Queue::Queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor to free memory allocated to the Queue
Queue::~Queue()
{
    delete arr; // you are not required to test this function;
    // however, are there issues with it?
}

// Utility function to remove front element from the Queue
void Queue::deQueue()
{
    // check for Queue underflow
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        return;
    }
    // cout << "Removing " << arr[front] << '\n';
    front = (front + 1) % capacity;
    count--;
}

// Utility function to add an item to the Queue
void Queue::enQueue(int item)
{
    // check for Queue overflow
    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        return;
    }
    // cout << "Inserting " << item << '\n';
    rear = (rear + 1) % capacity;
    arr[rear] = size();
    count++;
}

// Utility function to return front element in the Queue
int Queue::peek() const
{
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        return numeric_limits<int>::min();
    }
    return arr[rear];
}