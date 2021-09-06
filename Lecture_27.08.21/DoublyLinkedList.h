#pragma once

#include "Node.h"

template <typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList();

    std::shared_ptr<Node<T>> insert_front(const T& value);
    std::shared_ptr<Node<T>> insert_last(const T& value);

    void print_list();

    void remove_first();
    void remove_last();

    std::shared_ptr<Node<T>> get_first() const;
    std::shared_ptr<Node<T>> get_last() const;

private:
    std::shared_ptr<Node<T>> m_head;
    std::shared_ptr<Node<T>> m_tail;

protected:
};

    template <typename T>
    DoublyLinkedList<T>::DoublyLinkedList()
        : m_tail{ nullptr }, m_head{ nullptr }
    {
        //std::cout << "DoublyLinkedList constructor called\n";
    }

    template <typename T>
    std::shared_ptr<Node<T>> DoublyLinkedList<T>::insert_front(const T& value)
    {
        auto prev_head = m_head;                        // making a copy of the reference to m_head
        m_head = std::make_shared<Node<T>> (value);     // Setting a new value for the new head
        m_head->m_next = prev_head;                     // Setting the next node in line to be the previous head
        if (prev_head != nullptr) {                     // Checking if list is not empty
            prev_head->m_prev = m_head;                 // in that case im pointing the prev_head previous pointer 
                                                        // to the new head
        }
        if (m_tail == nullptr) {                        // if the list was empty, Im saying that tail is also the head
            m_tail = m_head;
        }
        return m_head;
    }

    template <typename T> 
    std::shared_ptr<Node<T>> DoublyLinkedList<T>::insert_last(const T& value)
    {
        auto next_tail = m_tail;
        m_tail = std::make_shared<Node<T>>(value);
        m_tail->m_prev = next_tail;
        if (next_tail != nullptr) {
            next_tail->m_next = m_tail;
        }
        if (m_head == nullptr) {
        m_head = m_tail;
        }
        return m_tail;
    }

    template <typename T>
    void DoublyLinkedList<T>::print_list() {
        auto current{ m_head };
        while (current != nullptr) {
            std::cout << current->m_data << "\t";
            current = current->m_next;
        }
        std::cout << "\n";
    }

    template <typename T>
    void DoublyLinkedList<T>::remove_first() {
    if (m_tail == m_head) {
                m_tail = nullptr;
                m_head = nullptr;
    }
            else {
                m_head = m_head->m_next;
                if (m_head != nullptr) {
                    m_head->m_prev = nullptr;
                }
            }
    }

    template <typename T>
    void DoublyLinkedList<T>::remove_last() {
        if (m_head == m_tail) {
            m_head = nullptr;
            m_tail = nullptr;
        }
        else {
            m_tail = m_tail->m_prev;
            if (m_tail != nullptr) {
                m_tail->m_next = nullptr;
            }
        }
    }

    template <typename T>
    std::shared_ptr<Node<T>> DoublyLinkedList<T>::get_first() const
    {
        if (m_head == nullptr) {
            throw std::runtime_error("get_first() on empty list");
        }
        return m_head;
    }

    template <typename T>
    std::shared_ptr<Node<T>> DoublyLinkedList<T>::get_last() const
    {
        if (m_tail == nullptr) {
            throw std::runtime_error("get_last() on empty list");
        }
        return m_tail;
    }
