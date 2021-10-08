#pragma once
#include "Node.h"

template <typename T_key, typename T_val>
class min_heap
{
    private:
    Node<T_key, T_val>* m_elements{};
    int m_capacity{};
    int m_no_of_nodes{};
    int get_parent_index(int i) { return (i-1) / 2; }
    int get_left_child_index(int i) { return 2* i + 1; }
    int get_right_child_index(int i) { return 2* i + 2; }
    void swap(int i1, int i2) {
        Node<T_key, T_val> tmp = m_elements[i1];
        m_elements[i1] = m_elements[i2];
        m_elements[i2] = tmp;
    }
    public:
    min_heap(int cap=100)
    :m_elements{ new Node<T_key, T_val>[cap] }, m_capacity{ cap }, m_no_of_nodes{ 0 } {
        std::cout << "min_heap constructor called.\n";
    }

    bool empty();
    void insert(T_key key, T_val val);
    Node<T_key, T_val> remove();
};

template <typename T_key, typename T_val>
bool min_heap<T_key, T_val>::empty()
{
    return m_no_of_nodes == 0;
}

template <typename T_key, typename T_val>
void min_heap<T_key, T_val>::insert(T_key key, T_val val)
{
    m_elements[m_no_of_nodes++] = Node<T_key, T_val>(key, val);

    int index = m_no_of_nodes - 1;

    while(index != 0 && m_elements[index] < m_elements[get_parent_index(index)]) {
        if(m_elements[index] < m_elements[get_parent_index(index)]) {
            swap(index, get_parent_index(index));
            index = get_parent_index(index);
        }
    }
}