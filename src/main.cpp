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
    tree->insert(7);
    tree->display();
    //    std::cout << "-------------------------------------" << std::endl;
    //    tree->leftRotation(3);
    //    std::cout << "-------------------------------------" << std::endl;
    //    tree->display();
    //    tree->rightRotation(8);
    //    std::cout << "-------------------------------------" << std::endl;
    //    tree->display();
    //    std::cout << "height: " << tree->height() << std::endl;
    //    std::cout << "balance: " << tree->getBalance() << std::endl;
    //    std::cout << "depthOf(8): " << tree->depthOf(5) << std::endl;
    //    std::cout << "-------------------------------------"<<std::endl;
    //    tree->leftRightRotation(8);
    //    tree->display();
    //    std::cout << "height: " << tree->height() << std::endl;
    //    std::cout << "balance: " << tree->getBalance() << std::endl;

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

    //    std::cout << "height: " << tree->height() << std::endl;
    //    std::cout << "balance: " << tree->getBalance() << std::endl;
    //    tree->rightLeftRotation(3);
    //    tree->display();
    //    std::cout << "height: " << tree->height() << std::endl;
    //    std::cout << "balance: " << tree->getBalance() << std::endl;
    delete tree;
    return 0;
}
