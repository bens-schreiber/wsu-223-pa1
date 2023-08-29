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
void LinkedList<T>::remove(int index) {
    if (index < 0 || index >= size) {
        return;
    }
    if (index == 0) {
        Node<T> *temp = head;
        head = head->getNext();
        temp->setNext(nullptr);
        delete temp;
    } else {
        Node<T> *prev = head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->getNext();
        }
        Node<T> *temp = prev->getNext();
        prev->setNext(temp->getNext());
        temp->setNext(nullptr);
        delete temp;
    }
    size--;
}

template <class T>
void LinkedList<T>::clear() {
    while (!isEmpty()) {
        remove(0);
    }
}

template <class T>
void LinkedList<T>::print() {
    Node<T> *temp = head;
    while (temp != nullptr) {
        std::cout << temp->getData() << std::endl;
        temp = temp->getNext();
    }
}


