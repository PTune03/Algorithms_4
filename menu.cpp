
#include "BinaryTree.hpp"
#include <iostream>
#include <string>



void menu()
{
    std::cout << "Choose type of data: 1 - double, 2 - int: ";
    int type = 0;

    std::cin >> type;

    if (type == 1)
    {
        BinaryTree<double> *tree = nullptr;

        int choice = 0;
        while (choice != 9)
        {
            std::cout << "Choose what you want to do:" << std::endl;
            std::cout << "1. Insert new element in binary tree\n"
                         "2. Delete element from binary tree\n"
                         "3. Find element in binary tree\n"
                         "4. Traversal binary tree\n"
                         "5. Print binary tree\n"
                         "6. Check an element for occurrence in binary tree\n"
                         "7. Writing binary tree to a string\n"
                         "8. Reading binary tree from a string\n"
                         "9. Exit\n";
            std::cin >> choice;

            switch (choice)
            {
                case 1: {
                    int counter;
                    double value;
                    std::cout << "Print number of elements which you want to insert: " << std::endl;
                    std::cin >> counter;
                    for (int i = 0; i < counter; i++) {
                        std::cin >> value;
                        tree->addNode(tree, value);
                    }
                    break;
                }
                case 2: {
                    std::cout << "Input element" << std::endl;
                    double element;
                    std::cin >> element;
                    tree->deleteNode(tree, element);
                    std::cout << std::endl;
                    break;
                }
                case 3: {
                    std::cout << "Input element" << std::endl;
                    double el;
                    std::cin >> el;
                    tree->find(tree, el);
                    std::cout << std::endl;
                    break;
                }
                case 4: {
                    std::cout
                            << "Choose a traversal of binary tree: 1 - LeftRightRoot, 2 - LeftRootRight, 3 - RootLeftRight"
                            << std::endl;
                    int a;
                    std::cin >> a;
                    switch (a) {
                        case 1:
                            std::cout << "LeftRightRoot traversal:" << std::endl;
                            tree->leftRightRoot(tree);
                            break;
                        case 2:
                            std::cout << "LeftRootRight traversal:" << std::endl;
                            tree->leftRootRight(tree);
                            break;
                        case 3:
                            std::cout << "LeftRootRight traversal:" << std::endl;
                            tree->rootLeftRight(tree);
                            break;
                    }
                    std::cout << std::endl;
                    break;
                }
                case 5: {
                    std::cout << "Binary tree: " << std::endl;
                    tree->print(tree, 0);
                    break;
                }
                case 6: {
                    double num;
                    std::cout << "Enter element: " << std::endl;
                    std::cin >> num;
                    bool answer = tree->containsNode(tree, num);
                    if (answer)
                        std::cout << "Element is in tree" << std::endl;
                    else
                        std::cout << "Element is not in tree" << std::endl;
                    break;
                }
                case 8: {
                    std::string string;
                    std::cout << "Enter the string in the desired format:" << std::endl;
                    std::cout << "Your string: ";
                    std::cin >> string;
                    int start = 0;
                    tree = tree->constructTree(string, &start);
                    break;
                }
                case 7:{
                    std::cout << "Your tree: ";
                    auto *answer = new std::string ();
                    tree->printToString(tree, answer);
                    std::cout << answer[0]<< std::endl;
                    break;


                }
            }


        }
    }

    if (type == 2) {
        BinaryTree<int> *tree = nullptr;

        int choice = 0;
        while (choice != 9) {
            std::cout << "Choose what you want to do:" << std::endl;
            std::cout << "1. Insert new element in binary tree\n"
                         "2. Delete element from binary tree\n"
                         "3. Find element in binary tree\n"
                         "4. Traversal binary tree\n"
                         "5. Print binary tree\n"
                         "6. Check an element for occurrence in binary tree\n"
                         "7. Writing binary tree to a string\n"
                         "8. Reading binary tree from a string\n"
                         "9. Exit\n";
            std::cin >> choice;

            switch (choice) {
                case 1: {
                    int counter;
                    int value;
                    std::cout << "Print number of elements which you want to insert: " << std::endl;
                    std::cin >> counter;
                    for (int i = 0; i < counter; i++) {
                        std::cin >> value;
                        tree->addNode(tree, value);
                    }
                    break;
                }
                case 2: {
                    std::cout << "Input element" << std::endl;
                    int element;
                    std::cin >> element;
                    tree->deleteNode(tree, element);
                    std::cout << std::endl;
                    break;
                }
                case 3: {
                    std::cout << "Input element" << std::endl;
                    int el;
                    std::cin >> el;
                    tree->find(tree, el);
                    std::cout << std::endl;
                    break;
                }
                case 4: {
                    std::cout
                            << "Choose a traversal of binary tree: 1 - LeftRightRoot, 2 - LeftRootRight, 3 - RootLeftRight"
                            << std::endl;
                    int a;
                    std::cin >> a;
                    switch (a) {
                        case 1:
                            std::cout << "LeftRightRoot traversal:" << std::endl;
                            tree->leftRightRoot(tree);
                            break;
                        case 2:
                            std::cout << "LeftRootRight traversal:" << std::endl;
                            tree->leftRootRight(tree);
                            break;
                        case 3:
                            std::cout << "LeftRootRight traversal:" << std::endl;
                            tree->rootLeftRight(tree);
                            break;
                    }
                    std::cout << std::endl;
                    break;
                }
                case 5: {
                    std::cout << "Binary tree: " << std::endl;
                    tree->print(tree, 0);
                    break;
                }
                case 6: {
                    int num;
                    std::cout << "Enter element: " << std::endl;
                    std::cin >> num;
                    bool answer = tree->containsNode(tree, num);
                    if (answer)
                        std::cout << "Element is in tree" << std::endl;
                    else
                        std::cout << "Element is not in tree" << std::endl;
                    break;
                }
                case 8: {
                    std::string string;
                    std::cout << "Enter the string in the desired format:" << std::endl;
                    std::cout << "Your string: ";
                    std::cin >> string;
                    int start = 0;
                    tree = tree->constructTree(string, &start);
                    break;
                }
                case 7: {
                    std::cout << "Your tree: ";
                    std::string *answer = new std::string ();
                    tree->printToString(tree, answer);
                    std::cout << answer[0]<< std::endl;
                    break;
                }


            }
        }

    }
}
