#pragma once

template <class T>
class tree_elem
{
public:
    T m_data;
    tree_elem<T> * m_left;
    tree_elem<T> * m_right;
    tree_elem<T> (T val)
    {
        m_left = nullptr;
        m_right = nullptr;
        m_data = val;
    }
    tree_elem<T> ()
    {
        m_left = nullptr;
        m_right = nullptr;
    }
    tree_elem<T> (tree_elem * elem)
    {
        m_left = elem->m_left;
        m_right = elem->m_right;
        m_data = elem->m_data;
    }
};