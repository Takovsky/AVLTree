#include "inc/avltree.h"
#include <iostream>

using namespace std;

int main()
{
    AVLTree<int> *tree = new AVLTree<int>;
    tree->insert(8);
    tree->insert(3);
    tree->insert(112);
    tree->insert(0);
    tree->insert(82);
    tree->insert(-72);
    tree->insert(98);
    tree->insert(1);
    tree->insert(-6);
    tree->insert(88);
    tree->insert(14);
    tree->insert(5);
    tree->insert(4);
    tree->insert(23);
    tree->insert(45);
    tree->insert(25);
    tree->insert(70);
    tree->inOrderWalkDebug();
    std::cout << std::endl;
    tree->preOrderWalkDebug();
    std::cout << std::endl;
    tree->postOrderWalkDebug();
    std::cout << std::endl;
    tree->inOrderWalk();
    std::cout << std::endl;
    tree->preOrderWalk();
    std::cout << std::endl;
    tree->postOrderWalk();
    std::cout << std::endl;
    std::cout << "size: " << tree->size() << std::endl;
    std::cout << "leaves: " << tree->leaves() << std::endl;
    std::cout << "root: " << tree->root() << std::endl;
    tree->display();
    delete tree;
    return 0;
}
