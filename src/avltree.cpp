#include "inc/avltree.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>

// template <typename Type>
// typename AVLTree<Type>::Node *&AVLTree<Type>::newNode(Type key, Node *&root, Node *&parent)
//{
//    root->key    = key;
//    root->parent = parent;
//    tmp->left = tmp->right = NULL;
//}

template <typename Type>
bool AVLTree<Type>::insert(Type key)
{
    if(!mRoot)
    {
        mRoot         = new Node(key);
        mRoot->key    = key;
        mRoot->parent = mRoot->left = mRoot->right = NULL;
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
bool AVLTree<Type>::remove(Node *&root)
{
    if(!root)
        return false;
    if(isExternal(root))
    {
        if(root != mRoot)
        {
            if(root == root->parent->left)
                root->parent->left = NULL;
            else
                root->parent->right = NULL;
        }

        delete root;
        root = NULL;

        return true;
    }
    else
    {
        Node *tmp = minAfter(root);
        if(!tmp)
            tmp = maxBefore(root);
        root->key = tmp->key;
        return remove(tmp);
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
    //    return NULL;
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
    //    return NULL;
}

template class AVLTree<int>;
