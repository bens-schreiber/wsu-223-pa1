#include "LinkedList.hpp"

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    delete head;
}

template <class T>
void LinkedList<T>::add(T data)
{
    Node<T> *node = new Node<T>(data);
    if (isEmpty())
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->setNext(node);
        tail = node;
    }
    size++;
}

template <class T>
void LinkedList<T>::remove(T data)
{
    Node<T> *temp = head;
    Node<T> *prev = nullptr;
    while (temp != nullptr)
    {
        if (temp->getData() == data)
        {
            if (prev == nullptr)
            {
                head = temp->getNext();
            }
            else
            {
                prev->setNext(temp->getNext());
            }
            temp->setNext(nullptr);
            delete temp;
            size--;
            return;
        }
        prev = temp;
        temp = temp->getNext();
    }
}

template <class T>
void LinkedList<T>::clear()
{
    delete head;
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
void LinkedList<T>::print()
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->getData() << std::endl;
        temp = temp->getNext();
    }
}

template <class T>
T LinkedList<T>::random(std::vector<T> &exclude) const {
    int index = rand() % size;
    Node<T> *temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->getNext();
    }
    for (T data : exclude) {
        if (temp->getData() == data) {
            return random(exclude);
        }
    }
    return temp->getData();
}

template class LinkedList<Command>;
