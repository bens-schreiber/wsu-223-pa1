#include "queue.h"
#include <iostream>

namespace QueueTest
{

    // Test the queue::size () function
    inline void testSize(void)
    {
        Queue q;
        if (q.size() != 0)
        {
            std::cout << "Queue::size () failed: expected 0, got " << q.size() << std::endl;
            return;
        }
        q.enQueue(1);
        if (q.size() != 1)
        {
            std::cout << "Queue::size () failed: expected 1, got " << q.size() << std::endl;
            return;
        }

        std::cout << "Queue::size () passed" << std::endl;
    }

    // Test the queue::isEmpty () function
    inline void testIsEmpty(void)
    {
        Queue q;
        if (!q.isEmpty())
        {
            std::cout << "Queue::isEmpty () failed: expected true, got false" << std::endl;
            return;
        }
        q.enQueue(1);
        if (q.isEmpty())
        {
            std::cout << "Queue::isEmpty () failed: expected false, got true" << std::endl;
            return;
        }

        std::cout << "Queue::isEmpty () passed" << std::endl;
    }

    // Test the queue::isFull () function
    inline void testIsFull(void)
    {
        Queue q;
        for (int i = 0; i < 10; i++)
        {
            q.enQueue(i);
        }
        if (!q.isFull())
        {
            std::cout << "Queue::isFull () failed: expected true, got false" << std::endl;
            return;
        }
        q.deQueue();
        if (q.isFull())
        {
            std::cout << "Queue::isFull () failed: expected false, got true" << std::endl;
            return;
        }

        std::cout << "Queue::isFull () passed" << std::endl;
        return;
    }

    // Test the dequeue function
    inline void testDequeue(void)
    {
        Queue q;
        for (int i = 0; i < 10; i++)
        {
            q.enQueue(i);
        }
        for (int i = 0; i < 10; i++)
        {
            if (q.peek() != i)
            {
                std::cout << "Queue::deQueue () failed: expected " << i << ", got " << q.peek() << std::endl;
                return;
            }
            q.deQueue();
        }

        std::cout << "Queue::deQueue () passed" << std::endl;
        return;
    }

    // test the enqueue function
    inline void testEnqueue(void)
    {
        Queue q;
        for (int i = 0; i < 10; i++)
        {
            q.enQueue(i);
        }
        for (int i = 0; i < 10; i++)
        {
            if (q.peek() != i)
            {
                std::cout << "Queue::enQueue () failed: expected " << i << ", got " << q.peek() << std::endl;
                return;
            }
            q.deQueue();
        }

        std::cout << "Queue::enQueue () passed" << std::endl;
        return;
    }
}