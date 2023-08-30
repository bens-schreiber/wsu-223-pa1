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

    ~Node()
    {
        delete next;
    }

    T getData() const
    {
        return data;
    }
    void setData(T data)
    {
        this->data = data;
    }

    Node<T> *getNext()
    {
        return next;
    }

    void setNext(Node<T> *next)
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

    int getSize() const
    {
        return size;
    }

    Node<T> *getHead() const
    {
        return head;
    }

    Node<T> *getTail() const
    {
        return tail;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    T random(std::vector<T>&) const;
    void add(T);
    void remove(int);
    void clear();
    void print();
};