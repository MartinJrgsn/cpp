#pragma once
#include <iostream>
#include <memory>

template <typename T>
class DoublyLinkedList;

template <typename T>
class Node  
{
public:
    //Node(std::shared_ptr<Node<T>> prev, T data, std::shared_ptr<Node<T>> next);
 /******************************************************************************************************************\
 * The code above can be considered, under the right circumstances, to be considered a security flaw in a program,  *
 * where the direct access of the next and previous smart pointers, could technically be pointed elsewhere.         *
 \******************************************************************************************************************/
    
    Node(const T& data);
    std::shared_ptr<Node<T>> get_prev();
    const T& get_data();
    std::shared_ptr<Node<T>> get_next();

private:
    friend class DoublyLinkedList<T>;
    std::shared_ptr<Node<T>> m_prev; 
    T m_data;
    std::shared_ptr<Node<T>> m_next;
// m_ is making it easier to recognize these variables specifically as member variable

protected:
};

    template <typename T>
    Node<T>::Node(const T& data)
        : m_data{ data }
    {
        //std::cout << "Node constructor called" << std::endl; // help text 
    }

    template <typename T>
    std::shared_ptr<Node<T>> Node<T>::get_prev()
    {
        return m_prev;
    }

    template <typename T>
    const T& Node<T>::get_data()
    {
        return m_data;
    }

    template <typename T>
    std::shared_ptr<Node<T>> Node<T>::get_next()
    {
        return m_next;
    }
