#include "inc/avltree.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>

template <typename Type>
bool AVLTree<Type>::insert(Type key)
{
    if(!mRoot)
    {
        mRoot = new Node(key);
        return true;
    }
    else
        return insert(key, mRoot);
}

template <typename Type>
bool AVLTree<Type>::insert(Type key, Node *&root)
{
    if(key < root->key and root->left)
        return insert(key, root->left);
    else if(key > root->key and root->right)
        return insert(key, root->right);
    else if(key < root->key and !root->left)
        root->left = new Node(key, root);
    else if(key > root->key and !root->right)
        root->right = new Node(key, root);
    else
        return false;

    if(!root->parent)
        return true;

    int balance = getBalance(root->parent);

    if(balance > 1 and key < root->key)
        rightRotation(root->parent->key);
    else if(balance > 1 and key > root->key)
        leftRightRotation(root->parent->key);
    else if(balance < -1 and key < root->key)
        rightLeftRotation(root->parent->key);
    else if(balance < -1 and key > root->key)
        leftRotation(root->parent->key);
    return true;
}

template <typename Type>
int AVLTree<Type>::height(Node *root)
{
    if(!root)
        return 0;
    int left  = height(root->left);
    int right = height(root->right);
    return left > right ? left + 1 : right + 1;
}

template <typename Type>
int AVLTree<Type>::depthOf(Node *root)
{
    if(!root)
        return -1;
    else if(root == mRoot)
        return 0;
    else
        return depthOf(root->parent) + 1;
}

template <typename Type>
Type AVLTree<Type>::remove(Node *&root)
{
    if(root and !isExternal(root))
    {
        Node *tmp = minAfter(root);
        if(!tmp)
            tmp = maxBefore(root);
        root->key = tmp->key;
        return remove(tmp);
    }
    else if(isExternal(root) and root != mRoot)
    {
        Node *tmp = root;
        Type key = root->key;
        if(root == root->parent->left)
            root->parent->left = NULL;
        else
            root->parent->right = NULL;

        int balance = getBalance(tmp);

        delete root;

        if(balance > 1 and getBalance(tmp->parent->left) >= 0)
            rightRotation(tmp->parent->key);
        else if(balance > 1 and getBalance(tmp->parent->left) < 0)
            leftRightRotation(tmp->parent->key);
        else if(balance < -1 and getBalance(tmp->parent->right) > 0)
            rightLeftRotation(tmp->parent->key);
        else if(balance < -1 and getBalance(tmp->parent->right) <= 0)
            leftRotation(tmp->parent->key);

        return key;
    }
    else
    {
        int key = mRoot->key;
        delete mRoot;
        mRoot = NULL;
        return key;
    }
}

template <typename Type>
typename AVLTree<Type>::Node *&AVLTree<Type>::find(Type key, Node *&root)
{
    if(root)
    {
        if(key == root->key)
            return root;
        else if(key < root->key)
            return find(key, root->left);
        else if(key > root->key)
            return find(key, root->right);
    }
}

template <typename Type>
void AVLTree<Type>::inOrderWalkDebug(Node *root)
{
    if(root)
    {
        if(root->left)
            std::cout << "inOrderWalk: going to -> " << root->left->key << std::endl;
        else
            std::cout << "inOrderWalk: left branch of \"" << root->key << "\" is NULL" << std::endl;
        inOrderWalkDebug(root->left);
        std::cout << "inOrderWalk: visiting -> ";
        visit(root);
        std::cout << std::endl;
        if(root->right)
            std::cout << "inOrderWalk: going to -> " << root->right->key << std::endl;
        else
            std::cout << "inOrderWalk: right branch of \"" << root->key << "\" is NULL" << std::endl;
        inOrderWalkDebug(root->right);
    }
}

template <typename Type>
void AVLTree<Type>::preOrderWalkDebug(Node *root)
{
    if(root)
    {
        std::cout << "preOrderWalk: visiting -> ";
        visit(root);
        std::cout << std::endl;
        if(root->left)
            std::cout << "preOrderWalk: going to -> " << root->left->key << std::endl;
        else
            std::cout << "preOrderWalk: left branch of \"" << root->key << "\" is NULL" << std::endl;
        preOrderWalkDebug(root->left);
        if(root->right)
            std::cout << "preOrderWalk: going to -> " << root->right->key << std::endl;
        else
            std::cout << "preOrderWalk: right branch of \"" << root->key << "\" is NULL" << std::endl;
        preOrderWalkDebug(root->right);
    }
}

template <typename Type>
void AVLTree<Type>::postOrderWalkDebug(Node *root)
{
    if(root)
    {
        if(root->left)
            std::cout << "postOrderWalk: going to -> " << root->left->key << std::endl;
        else
            std::cout << "postOrderWalk: left branch of \"" << root->key << "\" is NULL" << std::endl;
        postOrderWalkDebug(root->left);
        if(root->right)
            std::cout << "postOrderWalk: going to -> " << root->right->key << std::endl;
        else
            std::cout << "postOrderWalk: right branch of \"" << root->key << "\" is NULL" << std::endl;
        postOrderWalkDebug(root->right);
        std::cout << "postOrderWalk: visiting -> ";
        visit(root);
        std::cout << std::endl;
    }
}

template <typename Type>
void AVLTree<Type>::inOrderWalk(Node *root)
{
    if(root)
    {
        inOrderWalk(root->left);
        visit(root);
        inOrderWalk(root->right);
    }
}

template <typename Type>
void AVLTree<Type>::preOrderWalk(Node *root)
{
    if(root)
    {
        visit(root);
        preOrderWalk(root->left);
        preOrderWalk(root->right);
    }
}

template <typename Type>
void AVLTree<Type>::postOrderWalk(Node *root)
{
    if(root)
    {
        postOrderWalk(root->left);
        postOrderWalk(root->right);
        visit(root);
    }
}

template <typename Type>
int AVLTree<Type>::getBalance(Node *root)
{
    if(!root)
        return 0;
    return height(root->left) - height(root->right);
}

template <typename Type>
void AVLTree<Type>::leftRotation(Node *&root)
{
    Node *tmp    = root;
    root         = root->right;
    root->parent = tmp->parent;
    tmp->parent  = root;
    tmp->right   = NULL;
    root->left   = tmp;
}

template <typename Type>
void AVLTree<Type>::rightRotation(Node *&root)
{
    Node *tmp    = root;
    root         = root->left;
    root->parent = tmp->parent;
    tmp->parent  = root;
    tmp->left    = NULL;
    root->right  = tmp;
}

template <typename Type>
void AVLTree<Type>::leftRightRotation(Node *&root)
{
    leftRotation(root->left);
    rightRotation(root);
}

template <typename Type>
void AVLTree<Type>::rightLeftRotation(Node *&root)
{
    rightRotation(root->right);
    leftRotation(root);
}

template <typename Type>
typename AVLTree<Type>::Node *AVLTree<Type>::minAfter(Node *root)
{
    if(root->right)
    {
        Node *tmp = root->right;
        while(tmp->left)
        {
            tmp = tmp->left;
        }
        return tmp;
    }
    return NULL;
}

template <typename Type>
typename AVLTree<Type>::Node *AVLTree<Type>::maxBefore(Node *root)
{
    if(root->left)
    {
        Node *tmp = root->left;
        while(tmp->right)
        {
            tmp = tmp->right;
        }
        return tmp;
    }
    return NULL;
}

template <typename Type>
int AVLTree<Type>::size(Node *root)
{
    if(!root)
        return 0;
    return size(root->left) + size(root->right) + 1;
}

template <typename Type>
int AVLTree<Type>::leaves(Node *root)
{
    if(!root)
        return 0;
    if(isExternal(root))
        return 1;
    return leaves(root->left) + leaves(root->right);
}

template <typename Type>
void AVLTree<Type>::display(Node *root, int indent)
{
    if(root)
    {
        display(root->left, indent + 4);
        if(indent > 0)
            std::cout << std::setw(indent) << " ";
        std::cout << root->key << std::endl;
        display(root->right, indent + 4);
    }
}

template class AVLTree<int>;
