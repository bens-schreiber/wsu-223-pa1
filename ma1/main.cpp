// This code was taken from https://www.techiedelight.com/Queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn

/*

1) Using your understanding of design choices,
software principles, and coding standards, which we will group under
the general label “attributes” – list and describe 5 attributes
demonstrated by the code that you would consider poor. These should
NOT be related to the syntax errors. Examples of poor attributes could
be related to comments, file structure, data structure selection,
algorithm efficiency, etc. Place your list in a comment block at the
top of the main.cpp file.

First, our queue is array based, which means its spacial complexity is going to be higher than one of a linked list. 
This is because we have to allocate a contiguous block of memory for the array, which is not always possible. 
This also means that we have to copy the array to a new location if we want to resize it, which is a costly operation. 
A linked list would be a better choice for this implementation.

Second, the queue is not templated, which means it can only hold integers.
This is a poor attribute because it limits the use of the queue to only integers.
If we wanted to use the queue for other data types, we would have to create a new queue class for each data type.

Third, the queue delete function does not actually delete the array with the given syntax: delete arr;
This is a poor attribute because it means that the memory allocated for the array is not freed.
This could lead to memory leaks and other issues.

Fourth, the queue is not a circular queue, which means that the queue will eventually overflow.
This is a poor attribute because it means that the queue is not as efficient as it could be.
A circular queue would be a better choice for this implementation.

Fifth, the queue is not a double-ended queue, which means that the queue can only be accessed from the front.
This is a poor attribute because it means that the queue is not as efficient as it could be.




*/

#include "testQueue.h"

int main()
{

    // run tests
    QueueTest::testSize();
    QueueTest::testIsEmpty();
    QueueTest::testIsFull();
    QueueTest::testDequeue();
    QueueTest::testEnqueue();
}
