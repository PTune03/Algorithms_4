#include "tests.hpp"
#include <iostream>
using namespace std;

void containsSubTreeTest()
{
    BinaryTree<int> *tree = nullptr;
    tree->addNode(tree,2);
    tree->addNode(tree,1);
    tree->addNode(tree,3);
    BinaryTree<int> *tree2 = nullptr;
    tree2->addNode(tree,1);
    tree2->addNode(tree,3);
    bool contain = tree->containsSubTree(tree, tree2);

    assert(contain == true);
}

void addDataTest()
{
    BinaryTree<int> *tree = nullptr;
    tree->addNode(tree, 1);
    assert(tree->getValue() == 1);
}

void deleteNodeTest()
{
    BinaryTree<int> *tree = nullptr;
    tree->addNode(tree,1);
    tree->addNode(tree,2);
    tree->addNode(tree,3);
    tree->deleteNode(tree, 2);
    tree->deleteNode(tree,3);
    assert(tree->getLeft() == nullptr);
    assert(tree->getRight() == nullptr);
}

void containsNodeTest()
{
    BinaryTree<int> *tree = nullptr;
    tree->addNode(tree,1);
    tree->addNode(tree,2);
    tree->addNode(tree,3);
    bool contain = tree->containsNode(tree, 2);
    assert(contain == true);

}

bool div2(int item)
{
    if (item % 2 == 0)
        return true;
    else
        return false;
}

void whereTest()
{
    BinaryTree<int> *tree = nullptr;
    BinaryTree<int> *tree2 = nullptr;
    tree->addNode(tree, 2);
    tree->addNode(tree, 1);
    tree->addNode(tree, 4);
    tree->addNode(tree, 3);
    tree->addNode(tree, 6);
    tree->addNode(tree, 5);
    tree->addNode(tree, 8);
    tree2 = tree2->Where(&div2, tree, tree2);
    assert(tree2->getValue() == 2);
    assert(tree2->getRight()->getValue() == 4);
    assert(tree2->getRight()->getRight()->getValue() == 6);
    assert(tree2->getRight()->getRight()->getRight()->getValue() == 8);
}
int multiply2(int item){return item * 2;}
void mapTest()
{
    BinaryTree<int> *tree = nullptr;
    BinaryTree<int> *tree2 = nullptr;
    tree->addNode(tree, 2);
    tree->addNode(tree, 1);
    tree->addNode(tree, 4);
    tree->addNode(tree, 3);

    BinaryTree<int> *answer = nullptr;
    answer->addNode(answer, 4);
    answer->addNode(answer, 2);
    answer->addNode(answer, 8);
    answer->addNode(answer, 6);

    tree2 = tree2->map(&multiply2, tree,tree2);
    assert(tree2->getValue() == answer->getValue());
    assert(tree2->getRight()->getValue() == answer->getRight()->getValue());
    assert(tree2->getRight()->getLeft()->getValue() == answer->getRight()->getLeft()->getValue());
    assert(tree2->getLeft()->getValue() == answer->getLeft()->getValue());

}

void tests()
{
    addDataTest();
//    containsSubTreeTest();
    deleteNodeTest();
    containsNodeTest();
    whereTest();
    mapTest();
}