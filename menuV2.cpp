#include <iostream>
#include "BinaryTreeV2.hpp"

int main() {
    binary_tree<int> *tree=new binary_tree<int>(20);
////    УДАЛИЛИ ПУСТОЕ И ДОБАВИЛИ ПОТОМ
//    tree->erase(20);
//    tree->print(tree->Get(),0);
//    tree->insert(15);
//    tree->print(tree->Get(),0);
//    tree->insert(12);
//    tree->print(tree->Get(),0);
//// ПРАВОГО НЕТ НА МЕСТО ВСТАЕТ НАИБОЛЬШИЙ ИЗ ЛЕВЫХ ОТ КОРНЯ
//    tree->insert(10);
//    tree->insert(9);
//    tree->insert(11);
//    tree->insert(15);
//    tree->print(tree->Get(),0);
//    tree->erase(20);
//    tree->print(tree->Get(),0);
//// ОБЫЧНОЕ ДЕРЕВО 21-18-20 удаляем корень встает правый узел
//    tree->insert(18);
//    tree->insert(21);
//    tree->print(tree->Get(),0);
//    tree->erase(20);
//    tree->print(tree->Get(),0);
//    tree->insert(10);
//    tree->insert(5);
//    tree->insert(40);
//    tree->insert(15);
//    tree->insert(12);
//    tree->insert(17);
//    tree->insert(8);
//    tree->print(tree->Get(),0);
//    cout<<"ASDHJJASFHBJKDASHBDKNANSKFAS"<<endl;
//    tree->erase(10);
//    tree->print(tree->Get(),0);
//    cout<<"ASDHJJASFHBJKDASHBDKNANSKFAS"<<endl;
//    tree->erase(20);
//    tree->print(tree->Get(),0);
//    cout<<"ASDHJJASFHBJKDASHBDKNANSKFAS"<<endl;
//    tree->erase(40);
//    tree->print(tree->Get(),0);
    cout<<"1-to add elements\n2-to del element\n3-to print tree\n0-to exit\n: ";
    int choice;
    cin>>choice;
    while (choice!=0)
    {
        switch(choice)
        {
            case(1):
                cout<<"Input number of elements: "<<endl;
                int len;
                int element;
                cin>>len;
                for (int i=0;i<len;i++)
                {
                    cin>>element;
                    tree->insert(element);
                }
                break;
            case(2):
                cout<<"Input element: "<<endl;
                cin>>element;
                tree->erase(element);
                break;
            case 3:
                tree->print(tree->Get(),0);
                break;
            case 0:
                return 0;
                break;
        }
        cout<<"1-to add elements\n2-to del element\n3-to print tree\n0-to exit\n: ";
        cin>>choice;
    }


    return 0;
}

