#pragma once

#include "Node.h"

template <typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList();

private:
    std::shared_ptr<Node<T>> m_head;
    std::shared_ptr<Node<T>> m_tail;
protected:

};

    template <typename T>
    DoublyLinkedList<T>::DoublyLinkedList()
        : m_tail{ nullptr }, m_head{ nullptr }
    {
        std::cout << "DoublyLinkedList constructor called\n";
    }
