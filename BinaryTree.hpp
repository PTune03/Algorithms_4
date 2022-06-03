#pragma once
#include <iostream>
#include <string>

template <class T>
class BinaryTree
{
private:
    T value;
    BinaryTree *left;
    BinaryTree *right;
public:
    BinaryTree();
    BinaryTree(T data);
    BinaryTree *getLeft();
    BinaryTree *getRight();
    T getValue();
    void addNode(BinaryTree<T>*& tree, T item);
    void print(BinaryTree<T>*& tree, int level);
    void deleteTree(BinaryTree<T>* tree);
    BinaryTree<T> *find(BinaryTree<T> *tree, T item);
    void deleteNode(BinaryTree<T>* tree, T item, BinaryTree<T>* prev = nullptr);
    void leftRightRoot(BinaryTree<T>* tree);
    void rootLeftRight(BinaryTree<T>* tree);
    void leftRootRight(BinaryTree<T>* tree);
    bool containsNode(BinaryTree<T>* tree,  T item);
    bool containsSubTree(BinaryTree<T>* tree, BinaryTree<T>* subtree);
    BinaryTree<T>* Where(bool (*f) (T data), BinaryTree<T>* tree, BinaryTree<T>* result);
    BinaryTree<T>* map(T (*f) (T data), BinaryTree<T>* tree, BinaryTree<T>* result);
    BinaryTree<T>* constructTree(const std::string& str, int *start);
    BinaryTree<T>* getSubTree(BinaryTree<T>* tree, T item);
    std::string* printToString(BinaryTree<T>* tree1, std::string* res);
    void deleteNodeV2(BinaryTree<T> * tree, T item, BinaryTree<T> *prev = nullptr);
};

template <class T>
BinaryTree<T>::BinaryTree()
{
    this->left = nullptr;
    this->right = nullptr;
}

template <class T>
BinaryTree<T>* BinaryTree<T>::getLeft()
{
    return this->left;
}

template<class T>
BinaryTree<T>* BinaryTree<T>::getRight()
{
    return this->right;
}

template<class T>
T BinaryTree<T>::getValue()
{
    return this->value;
}


template<class T>
void BinaryTree<T>::addNode(BinaryTree<T> *&tree, T item)
{
    if (tree == nullptr)
    {
        tree = new BinaryTree<T>;
        tree->value = item;
        tree->left = nullptr;
        tree->right = nullptr;
        return;
    }

    if (item < tree->value)
    {
        if (tree->left != nullptr)
            addNode(tree->left, item);
        else
        {
            tree->left = new BinaryTree<T>;
            tree->left->left = nullptr;
            tree->left->right = nullptr;
            tree->left->value = item;
        }
    }

    if (item >= tree->value)
    {
        if (tree->right != nullptr)
            addNode(tree->right, item);
        else
        {
            tree->right = new BinaryTree<T>;
            tree->right->right = nullptr;
            tree->right->left = nullptr;
            tree->right->value = item;
        }
    }
}

template<class T>
void BinaryTree<T>::deleteTree(BinaryTree<T> *tree)
{
    if (tree != nullptr)
    {
        deleteTree(tree->getLeft());
        deleteTree(tree->getRight());
        delete tree;
        tree = nullptr;
    }
}

template<class T>
BinaryTree<T>* BinaryTree<T>::find(BinaryTree<T> * tree, T item)
{
    if (tree != nullptr)
    {
        if (tree->value == item)
            return tree;

        else if (item < tree->value)
            return find(tree->left, item);

        else if(item > tree->value)
            return find(tree->right, item);
    }
    else
        return nullptr;

}

template<class T>
BinaryTree<T>* getMinimal(BinaryTree<T>* tree, BinaryTree<T>*& prev)
{
    if (tree == nullptr)
        return nullptr;

    if (tree->getLeft() != nullptr)
    {
        BinaryTree<T> *temp = getMinimal(tree->getLeft(), tree);
        prev = tree;
        return temp;
    }
    else
        return tree;
}
template<class T>
void BinaryTree<T>::deleteNode(BinaryTree<T> *tree, T item, BinaryTree<T> *prev)
{
    if (tree != nullptr)
    {
        if (item == tree->value)
        {
            if((tree->left == nullptr) && (tree->right == nullptr))
            {
                if (prev != nullptr && prev->value <= tree->value)
                    prev->right = nullptr;
                else
                    prev->left = nullptr;
                delete tree;
            }
            else if(tree->left == nullptr && tree->right != nullptr)
            {
                if (prev != nullptr && prev->value <= tree->value)
                    prev->right = tree->right;
                else
                    prev->left = tree->right;
                delete tree;
            }
            else if(tree->left != nullptr && tree->right == nullptr)
            {
                if (prev != nullptr && prev->value <= tree->value)
                    prev->right = tree->left;
                else
                    prev->left = tree->left;
                delete tree;
            }
            else if(tree->left != nullptr && tree->right != nullptr)
            {
                BinaryTree<T>* prev = nullptr;
                BinaryTree<T>* pointer = getMinimal(tree->right, prev);
                if (pointer->right == nullptr)
                {
                    if (prev != nullptr)
                        prev->left = nullptr;
                }
                else
                {
                    if (prev != nullptr)
                        prev->left = pointer->right;
                }
                tree->value = pointer->value;
                delete pointer;
            }
        }
        else if(item < tree->value)
            deleteNode(tree->left, item, tree);

        else if(item > tree->value)
            deleteNode(tree->right, item, tree);
    }
    else
        std::cout << "no such element" << std::endl;
}

template<class T>
void BinaryTree<T>::print(BinaryTree<T> *&tree, int level)
{

    if (tree)
    {
        print(tree->right, level + 1);
        for (int i = 0; i < level; i++) std::cout << "    ";
        std::cout << tree->value << std::endl;
        print(tree->left, level + 1);
    }
    else
        std::cout << std::endl;
}

template<class T>
void BinaryTree<T>::leftRightRoot(BinaryTree<T> *tree)
{
    if (tree != nullptr)
    {
        leftRightRoot(tree->left);
        leftRightRoot(tree->right);
        std::cout << tree->value << " ";
    }
}

template <class T>
void BinaryTree<T>::leftRootRight(BinaryTree<T> *tree)
{
    if (tree != nullptr)
    {
        leftRootRight(tree->left);
        std::cout << tree->value << " ";
        leftRootRight(tree->right);
    }
}

template<class T>
void BinaryTree<T>::rootLeftRight(BinaryTree<T> *tree)
{
    if (tree != nullptr)
    {
        std::cout << tree->value << " ";
        rootLeftRight(tree->left);
        rootLeftRight(tree->right);
    }
}

template<class T>
BinaryTree<T>::BinaryTree(T data)
{
    this->value = data;
    this->right = nullptr;
    this->left = nullptr;
}

template<class T>
bool BinaryTree<T>::containsNode(BinaryTree<T> *tree, T item)
{
    BinaryTree<T> *new_tree = nullptr;
    new_tree = tree->find(tree, value);

    if (new_tree == nullptr)
        return false;
    else
        return true;
}

template<class T>
bool BinaryTree<T>::containsSubTree(BinaryTree<T> *tree, BinaryTree<T> *subtree)
{
    bool contain = tree->containsNode(tree, subtree->getValue());
    if (!contain)
        return false;

    if (tree->getLeft() != nullptr)
    {
        contain = containsSubTree(tree, subtree->getLeft());
        if (!contain)
            return false;
    }

    if (tree->getRight() != nullptr)
    {
        contain = containsSubTree(tree, subtree->getRight());
        if (!contain)
            return false;
    }
    if (contain)
        return true;
}

template<class T>
BinaryTree<T>* BinaryTree<T>::map(T (*f)(T), BinaryTree<T> *tree, BinaryTree<T> *result)
{
    if (tree == nullptr)
        return nullptr;
    if (tree != nullptr)
    {
        if (tree->getValue())
            result->addNode(result, f(tree->getValue()));

        if (tree->getLeft() != nullptr)
            map(f,tree->getLeft(), result);

        if (tree->getRight() != nullptr)
            map(f, tree->getRight(), result);
    }
    return result;

}




template<class T>
BinaryTree<T>* BinaryTree<T>::Where(bool (*f)(T data), BinaryTree<T> *tree, BinaryTree<T> *result)
{
    if (tree != nullptr)
    {
        if (f(tree->getValue()))
            result->addNode(result, tree->getValue());

        if (tree->getLeft() != nullptr)
            Where(f, tree->getLeft(), result);

        if (tree->getRight() != nullptr)
            Where(f, tree->getRight(), result);
    }
    return result;
}

template<class T>
BinaryTree<T>* BinaryTree<T>::constructTree(const std::string& str, int *start)
{
    if (str.empty() || *start >= str.size())
        return nullptr;

    T num = 0;
    // Получаем первое число
    while(*start < str.size() && str[*start] != '(' && str[*start] != ')')
    {
        T num_here = (T)(str[*start] - '0');
        num = num * 10 + num_here;
        *start = *start + 1;
    }
    // Создаем узел с нашим числом
    BinaryTree<T> *root = nullptr;
    if (num > 0)
        root = new BinaryTree(num);
    // Встречаем правую скобку - начинаем строить дерево слева.
    if (*start < str.size() && str[*start] == '(')
    {
        *start = *start + 1;
        root->left = constructTree(str, start);
    }
    if (*start < str.size() && str[*start] == ')')
    {
        *start = *start + 1;
        return root;
    }
    // Когда мы встречаем вторую правую скобку от узла, строим дерево вправо.
    if (*start < str.size() && str[*start] == '(')
    {
        *start = *start + 1;
        root->right = constructTree(str, start);
    }

    if (*start < str.size() && str[*start] == ')')
        *start = *start + 1;

    return root;


}

template<class T>
BinaryTree<T>* BinaryTree<T>::getSubTree(BinaryTree<T> *tree, T item)
{
    BinaryTree<T> *result = find(tree, item);
    return result;
}

template <class T>
std::string* BinaryTree<T>::printToString(BinaryTree<T>* tree1,std::string* res)
{
    if (tree1== nullptr)
        return nullptr;
    *res= *res+ std::to_string(tree1->getValue());
    if (tree1->getLeft()!= nullptr)
    {
        *res+="(";
        printToString(tree1->getLeft(),res);
        *res+=")";
    }
    else
        *res +="()";

    if (tree1->getRight()!= nullptr) {
        *res += "(";
        printToString(tree1->getRight(), res);
        *res += ")";
    }
    else
        *res += "()";
    return res;
}

template<class T>
void BinaryTree<T>::deleteNodeV2(BinaryTree<T> *tree, T item, BinaryTree<T> *prev)
{
    BinaryTree<T> *parent = nullptr;
    while (tree && tree->value != item)
    {
        parent = tree;
        if (tree->value > item)
            tree = tree->left;
        else
            tree = tree->right;

        if (!tree)
            return;

        if (tree->left == nullptr)
        {
            if (parent && parent->left == tree)
                parent->left = tree->right;

            if (parent && parent->right == tree)
                parent->right = tree->right;

            delete tree;
        }

        if (tree->right == nullptr)
        {
            if (parent && parent->left == tree)
                parent->left = tree->right;

            if (parent && parent->right == tree)
                parent->right = tree->right;

            delete tree;
        }

        BinaryTree<T> *replace = tree->right;

        while (replace->left)
            replace = replace->left;

        T replace_value = replace->getValue();
        deleteNodeV2(tree, replace_value, prev);
        tree->value = replace_value;

    }
}