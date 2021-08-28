#pragma once
#include <iostream>
#include <memory>

template <typename T>
class Node  
{
public:
//Node(std::shared_ptr<Node<T>> prev, T data, std::shared_ptr<Node<T>> next);
private:
std::shared_ptr<Node<T>> m_prev;
T data;
std::shared_ptr<Node<T>> m_next;

protected:
};