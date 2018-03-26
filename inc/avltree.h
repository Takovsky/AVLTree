#ifndef AVLTREE_H
#define AVLTREE_H

#include <cstdlib>
#include <iostream>

template <typename Type>
class AVLTree
{
public:
    AVLTree() : mRoot(NULL) {}
    ~AVLTree()
    {
        while(mRoot) remove(mRoot);
    }
    bool insert(Type key);
    bool remove(Type key) { return remove(find(key, mRoot)); }
    bool isEmpty() const { return mRoot; }
    int height() { return height(mRoot); }
    int depthOf(Type key) { return depthOf(find(key, mRoot)); }
    void inOrderWalkDebug() { inOrderWalkDebug(mRoot); }
    void preOrderWalkDebug() { preOrderWalkDebug(mRoot); }
    void postOrderWalkDebug() { postOrderWalkDebug(mRoot); }
    void inOrderWalk() { inOrderWalk(mRoot); }
    void preOrderWalk() { preOrderWalk(mRoot); }
    void postOrderWalk() { postOrderWalk(mRoot); }
    void root()
    {
        if(!mRoot)
            std::cout << "Tree is empty" << std::endl;
        else
            std::cout << "Root of Tree is: " << mRoot->key << std::endl;
    }

private:
    struct Node
    {
        Type key;
        Node *parent;
        Node *left;
        Node *right;
        Node(Type key, Node *parent = NULL, Node *left = NULL, Node *right = NULL)
        : key(key), parent(parent), left(left), right(right)
        {
        }
    };
    Node *mRoot;
    bool isExternal(Node *root) { return !(root->left or root->right); }
    int getBalance(Node *root);
    bool insert(Type key, Node *&root);
    bool remove(Node *&root);
    Node *&find(Type key, Node *&root);
    Node *minAfter(Node *root);
    Node *maxBefore(Node *root);
    int height(Node *root);
    int depthOf(Node *root);
    void inOrderWalk(Node *root);
    void preOrderWalk(Node *root);
    void postOrderWalk(Node *root);
    void inOrderWalkDebug(Node *root);
    void preOrderWalkDebug(Node *root);
    void postOrderWalkDebug(Node *root);
    void visit(Node *root) { std::cout << root->key << " "; }
    void leftRotation(Node *&root);
    void rightRotation(Node *&root);
    void leftRightRotation(Node *&root);
    void rightLeftRotation(Node *&root);
    void leftRotation(Type key) { leftRotation(find(key, mRoot)); }
    void rightRotation(Type key) { rightRotation(find(key, mRoot)); }
    void leftRightRotation(Type key) { leftRightRotation(find(key, mRoot)); }
    void rightLeftRotation(Type key) { rightLeftRotation(find(key, mRoot)); }
};

#endif // AVLTREE_H
