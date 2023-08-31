#pragma once
#include <iostream>
#include <vector>
#include "../Profile/Profile.hpp"
#include "../Command/Command.hpp"

template <class T>
class Node
{
private:
    T data;
    Node<T> *next;

public:
    Node(T data) : data(data), next(nullptr) {}

    inline ~Node()
    {
        delete next;
    }

    inline T getData() const
    {
        return data;
    }
    inline void setData(T data)
    {
        this->data = data;
    }

    inline Node<T> *getNext()
    {
        return next;
    }

    inline void setNext(Node<T> *next)
    {
        this->next = next;
    }
};

template <class T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    LinkedList();

    ~LinkedList();

    inline int getSize() const
    {
        return size;
    }

    inline Node<T> *getHead() const
    {
        return head;
    }

    inline Node<T> *getTail() const
    {
        return tail;
    }

    inline bool isEmpty() const
    {
        return size == 0;
    }

    T random(std::vector<T>&) const;
    void add(T);
    void remove(int);
    void clear();
    void print();
};