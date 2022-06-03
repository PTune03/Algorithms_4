#pragma once

#include "Node.hpp"
#include <iostream>
using namespace std;

template <class T>
class binary_tree {
private:
    tree_elem<T> *m_root;
    int m_size;
    void print_tree(tree_elem<T> *);
    void delete_tree(tree_elem<T> *);

public:
    binary_tree(T key);
    binary_tree();


    ~binary_tree<T>();
    tree_elem<T>* Get();
    void print(tree_elem<T> *elem, int level);
    bool find(T key);
    void insert(T key);
    void erase(T key);
    int size();

};
template <class T>
binary_tree<T>::binary_tree(T key)
{
    m_root = new tree_elem(key);
    m_size = 1;
}


template <class T>
binary_tree<T>::~binary_tree<T>()
{
    delete_tree(m_root);
}
template <class T>
void binary_tree<T>::delete_tree(tree_elem<T> * curr)

{
    if (curr)
    {
        delete_tree(curr->m_left);
        delete_tree(curr->m_right);
        delete curr;
    }
}
//template <class T>
//void binary_tree<T>::print()
//{
//    print_tree(m_root);
//    cout << endl;
//}
template <class T>
tree_elem<T>* binary_tree<T>::Get()
{
    return this->m_root;
}
template<class T>
void binary_tree<T>::print(tree_elem<T> *elem, int level)
{

    if (elem)
    {
        print(elem->m_right, level + 3);
        for (int i = 0; i < level; i++) cout << " ";
        cout << elem->m_data<< endl;
        print(elem->m_left, level + 3);
    }
    else{
        cout<<"";
    }
}
template <class T>
void binary_tree<T>::print_tree(tree_elem<T> * curr)
{
    if (curr) // Проверка на ненулевой указатель
    {
        cout << curr->m_data << " ";
        print_tree(curr->m_left);
        print_tree(curr->m_right);
    }
}
template <class T>
bool binary_tree<T>::find(T key)
{
    tree_elem<T> * curr = m_root;
    while (curr && curr->m_data != key)
    {
        if (curr->m_data > key)
            curr = curr->m_left;
        else
            curr = curr->m_right;
    }
    return curr != NULL;
}
template <class T>
void binary_tree<T>::insert(T key)
{
    tree_elem<T> * curr = m_root;
    if (m_root== nullptr)
    {
        m_root=new tree_elem<T>(key);
    }
    while (curr && curr->m_data != key)
    {
        if (curr->m_data > key && curr->m_left == NULL)
        {
            curr->m_left = new tree_elem(key);
            ++m_size;
            return;
        }
        if (curr->m_data < key && curr->m_right == NULL)
        {
            curr->m_right = new tree_elem(key);
            ++m_size;
            return;
        }
        if (curr->m_data > key)
            curr = curr->m_left;
        else
            curr = curr->m_right;
    }
}
template <class T>
void binary_tree<T>::erase(T key)
{
    tree_elem<T> * curr = m_root;
    tree_elem<T> * parent = NULL;
    while (curr && curr->m_data != key)
    {
        parent = curr;
        if (curr->m_data > key)
        {
            curr = curr->m_left;
        }
        else
        {
            curr = curr->m_right;
        }
    }
    if (!curr)
        return;

    if (curr->m_left == NULL)
    {
        if (curr==m_root && m_root->m_right== nullptr)
        {
            if (curr==this->m_root) {

                delete this->m_root;
                this->m_root=nullptr;
                --m_size;
                return;
            }
        }
        else if(curr==m_root && m_root->m_right)
        {
            tree_elem<T>* tmp=new tree_elem<T>(m_root->m_right);
            delete this->m_root;
            this->m_root=tmp;
            --m_size;
            return;
        }
        if (parent && parent->m_left == curr)
            parent->m_left = curr->m_right;
        if (parent && parent->m_right == curr)
            parent->m_right = curr->m_right;
        --m_size;
        delete curr;
        return;
    }

    if (curr->m_right == NULL)
    {
        if (curr==m_root)
        {
            if (curr->m_left->m_right) {
                tree_elem<T> *tmp = m_root->m_left;
                while (tmp->m_right->m_right)
                    tmp = tmp->m_right;
                m_root->m_data = tmp->m_right->m_data;
                delete tmp->m_right;
                tmp->m_right = nullptr;
                return;
            }
            else
            {
                tree_elem<T>* tmp=new tree_elem<T>(m_root->m_left);
                delete this->m_root;
                this->m_root=tmp;
                --m_size;
                return;
            }
        }

        if (parent && parent->m_left == curr)
            parent->m_left = curr->m_left;
        if (parent && parent->m_right == curr)
            parent->m_right = curr->m_left;
        --m_size;
        delete curr;
        return;
    }


    tree_elem<T> * replace = curr->m_right;
    while (replace->m_left)
        replace = replace->m_left;
    int replace_value = replace->m_data;
    erase(replace_value);
    curr->m_data = replace_value;
}