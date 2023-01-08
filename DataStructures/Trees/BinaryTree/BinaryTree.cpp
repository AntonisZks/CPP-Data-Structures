/* Filename: "BinaryTree.hpp" */

/* This file includes all the basic functions
   for a Binary Data Structure */

#include <iostream>
#include "BinaryTree.hpp"
using namespace std;

template <typename ntype>
Binary::TreeNode<ntype>::TreeNode()
{
    /* Setting all the data */
    this->setLeftChild(NULL);
    this->setRightChild(NULL);
    this->setParent(NULL);
}

template <typename ntype>
Binary::TreeNode<ntype>::TreeNode(ntype data, btrnode<ntype> *leftChild,
                                  btrnode<ntype> *rightChild, btrnode<ntype> *parent)
{
    /* Setting all the data */
    this->setData(data);
    this->setLeftChild(leftChild);
    this->setRightChild(rightChild);
    this->setParent(parent);
}

template <typename ntype>
void Binary::TreeNode<ntype>::set(ntype data, btrnode<ntype> *leftChild,
                                  btrnode<ntype> *rightChild, btrnode<ntype> *parent)
{
    this->setData(data);
    this->setLeftChild(leftChild);
    this->setRightChild(rightChild);
    this->setParent(parent);
}

template <typename ttype>
void Binary::Tree<ttype>::destroy(Binary::TreeNode<ttype> *root)
{
    if (root != NULL)
    {
        this->destroy(root->getLeftChild());
        this->destroy(root->getRightChild());
        delete root;
    }
}

template <typename ttype>
void Binary::Tree<ttype>::Insert_left(Binary::TreeNode<ttype> *parentNode, ttype data)
{
    if (parentNode->getLeftChild() == NULL)
    {
        Binary::TreeNode<ttype> *newLeftNode = new Binary::TreeNode<ttype>(data);
        parentNode->setLeftChild(newLeftNode);
        newLeftNode->setParent(parentNode);
    }
}

template <typename ttype>
void Binary::Tree<ttype>::Insert_right(Binary::TreeNode<ttype> *parentNode, ttype data)
{
    if (parentNode->getRightChild() == NULL)
    {
        Binary::TreeNode<ttype> *newRightNode = new Binary::TreeNode<ttype>(data);
        parentNode->setRightChild(newRightNode);
        newRightNode->setParent(parentNode);
    }
}

template <typename ttype>
void Binary::Tree<ttype>::Insert_left_node(Binary::TreeNode<ttype> *parentNode, Binary::TreeNode<ttype> *leftNode)
{
    if (parentNode->getLeftChild() == NULL)
    {
        parentNode->setLeftChild(leftNode);
        leftNode->setParent(parentNode);
    }
}

template <typename ttype>
void Binary::Tree<ttype>::Insert_right_node(Binary::TreeNode<ttype> *parentNode, Binary::TreeNode<ttype> *rightNode)
{
    if (parentNode->getRightChild() == NULL)
    {
        parentNode->setRightChild(rightNode);
        rightNode->setParent(parentNode);
    }
}

template <typename ttype>
void Binary::Tree<ttype>::printPreOrder(void)
{
    cout << "(";
    this->printPreOrder_(this->root);
    cout << ")";
}

template <typename ttype>
void Binary::Tree<ttype>::printInOrder(void)
{
    cout << "(";
    this->printInOrder_(this->root);
    cout << ")";
}

template <typename ttype>
void Binary::Tree<ttype>::printPostOrder(void)
{
    cout << "(";
    this->printPostOrder_(this->root);
    cout << ")";
}

template <typename ttype>
void Binary::Tree<ttype>::printPreOrder_(Binary::TreeNode<ttype> *root)
{
    /* The Pre Order first prints the root of the main tree,
    then the left sub-tree of the main tree
    and finally the right sub-tree of the main tree */
    if (root != NULL)
    {
        cout << root->getData() << " ";
        this->printPreOrder_(root->getLeftChild());
        this->printPreOrder_(root->getRightChild());
    }
}

template <typename ttype>
void Binary::Tree<ttype>::printInOrder_(Binary::TreeNode<ttype> *root)
{
    /* The Pre Order first prints the root of the main tree,
    then the left sub-tree of the main tree
    and finally the right sub-tree of the main tree */
    if (root != NULL)
    {
        this->printInOrder_(root->getLeftChild());
        cout << root->getData() << " ";
        this->printInOrder_(root->getRightChild());
    }
}

template <typename ttype>
void Binary::Tree<ttype>::printPostOrder_(Binary::TreeNode<ttype> *root)
{
    /* The Pre Order first prints the root of the main tree,
    then the left sub-tree of the main tree
    and finally the right sub-tree of the main tree */
    if (root != NULL)
    {
        this->printPostOrder_(root->getLeftChild());
        this->printPostOrder_(root->getRightChild());
        cout << root->getData() << " ";
    }
}