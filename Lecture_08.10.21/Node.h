#pragma once
#include <iostream>

template <typename T_key, typename T_val>
class Node
{
    public:
    Node() = default;
    Node(T_key k, T_val v)
    :m_key{ k }, m_val{ v }
    {
        std::cout << "Node constructor called\n";
    }
    T_key get_key();
    T_val get_val();
    bool operator< (Node<T_key, T_val> other);
    bool operator> (Node<T_key, T_val> other);

    private:
    T_key m_key{};
    T_val m_val{};
};

template <typename T_key, typename T_val>
T_key Node<T_key, T_val>::get_key()
{
    return m_key;
}
template <typename T_key, typename T_val>
T_val Node<T_key, T_val>::get_val()
{
    return m_val;
}

template <typename T_key, typename T_val>
bool Node<T_key, T_val>::operator<(Node<T_key, T_val> other)
{
    return m_key < other.get_key();
}


template <typename T_key, typename T_val>
bool Node<T_key, T_val>::operator>(Node<T_key, T_val> other)
{
    return m_key > other.get_key();
}
