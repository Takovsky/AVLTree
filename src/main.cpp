#include "inc/avltree.h"
#include <iostream>

using namespace std;

int main()
{
    AVLTree<int> *tree = new AVLTree<int>;
    tree->insert(8);
    tree->display();
    std::cout << "-------------------------------------" << std::endl;
    tree->insert(3);
    tree->display();
    std::cout << "-------------------------------------" << std::endl;
    tree->insert(112);
    tree->display();
    std::cout << "-------------------------------------" << std::endl;
    tree->insert(0);
    tree->display();
    std::cout << "-------------------------------------" << std::endl;
    tree->insert(82);
    tree->display();
    std::cout << "-------------------------------------" << std::endl;
    tree->insert(-72);
    tree->display();
    std::cout << "-------------------------------------" << std::endl;
    tree->insert(98);
    tree->display();
    std::cout << "-------------------------------------" << std::endl;
    tree->insert(1);
    tree->display();
    std::cout << "-------------------------------------" << std::endl;
    tree->insert(-6);
    tree->display();
    std::cout << "-------------------------------------" << std::endl;
    tree->insert(88);
    tree->display();
    std::cout << "-------------------------------------" << std::endl;
    tree->insert(14);
    tree->display();
    std::cout << "-------------------------------------" << std::endl;
    tree->insert(5);
    tree->display();
    std::cout << "-------------------------------------" << std::endl;
    tree->insert(4);
    tree->display();
    std::cout << "-------------------------------------" << std::endl;
    tree->insert(23);
    tree->display();
    std::cout << "-------------------------------------" << std::endl;
    tree->insert(45);
    tree->display();
    std::cout << "-------------------------------------" << std::endl;
    tree->insert(25);
    tree->display();
    std::cout << "-------------------------------------" << std::endl;
    tree->insert(70);
    tree->display();
    std::cout << "-------------------------------------" << std::endl;
    delete tree;
    return 0;
}
