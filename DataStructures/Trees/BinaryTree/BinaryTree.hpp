/* Filename: "BinaryTree.hpp" */

/* This file includes all the basic function prototypes
   for a Binary Tree Data Structure */

#ifndef BINARY_TREE__HEADER
#define BINARY_TREE__HEADER

#include <iostream>
using namespace std;

#define btrnode Binary::TreeNode

namespace Binary
{
    /* Basic Struct for a Binary Tree Node */
    template <typename ntype>
    struct TreeNode
    {
    public:
        /* Constructors */
        TreeNode(); // Default Constructor
        TreeNode(ntype data, btrnode<ntype> *leftChild = NULL,
                 btrnode<ntype> *rightChild = NULL, btrnode<ntype> *parent = NULL); // Complex Constructor

        /* Setters */
        void setData(ntype data) { this->data = data; }                                                                           // Sets the data of the node
        void setParent(Binary::TreeNode<ntype> *parent) { this->parent = parent; }                                                 // Sets the parent of the node
        void setLeftChild(Binary::TreeNode<ntype> *leftChild) { this->leftChild = leftChild; }                                     // Sets the left child of the node
        void setRightChild(Binary::TreeNode<ntype> *rightChild) { this->rightChild = rightChild; }                                 // Sets the right child of the node
        void set(ntype data, btrnode<ntype> *leftChild = NULL, btrnode<ntype> *rightChild = NULL, btrnode<ntype> *parent = NULL); // Sets the node

        /* Getters */
        ntype &getData() { return this->data; }                                   // Returns the data of the node
        Binary::TreeNode<ntype> *getParent(void) { return this->parent; }         // Returns the parent of the node
        Binary::TreeNode<ntype> *getLeftChild(void) { return this->leftChild; }   // Returns the left child of the node
        Binary::TreeNode<ntype> *getRightChild(void) { return this->rightChild; } // Returns the right child of the node

    private:
        ntype data;                          // Node data
        Binary::TreeNode<ntype> *leftChild;  // Left child of the node
        Binary::TreeNode<ntype> *rightChild; // Right child of the node
        Binary::TreeNode<ntype> *parent;     // Parent of the node
    };

    /* Basic Class for a Binary Tree */
    template <typename ttype>
    class Tree
    {
    public:
        /* Constructors and Destructor */
        Tree() { this->root = new Binary::TreeNode<ttype>(); }
        Tree(ttype &data) { this->root = new Binary::TreeNode<ttype>(data); }
        ~Tree() { this->destroy(this->root); }

        /* Getters */
        Binary::TreeNode<ttype> *getRoot() const { return this->root; }

        /* Inserting */
        void Insert_root(ttype data) { this->root->setData(data); }
        void Insert_left(Binary::TreeNode<ttype> *parentNode, ttype data);
        void Insert_right(Binary::TreeNode<ttype> *parentNode, ttype data);
        void Insert_left_node(Binary::TreeNode<ttype> *parentNode, Binary::TreeNode<ttype> *leftNode);
        void Insert_right_node(Binary::TreeNode<ttype> *parentNode, Binary::TreeNode<ttype> *rightNode);

        /* Printing */
        void printPreOrder(void);  // Prints the pre-order tree
        void printPostOrder(void); // Prints the post-order tree
        void printInOrder(void);   // Prints the in-order tree

        template <typename titem>
        friend ostream &operator<<(ostream &out, const Binary::Tree<titem> tree);

    private:
        /* Private Data */
        Binary::TreeNode<ttype> *root; // Root node of the tree
        int size;                      // Elements in the tree

        /* Private Methods */
        void destroy(Binary::TreeNode<ttype> *root); // Destroys the tree

        void printPreOrder_(Binary::TreeNode<ttype> *root);  // Prints the pre-order tree of the given root
        void printPostOrder_(Binary::TreeNode<ttype> *root); // Prints the post-order tree of the given root
        void printInOrder_(Binary::TreeNode<ttype> *root);   // Prints the in-order tree of the given root
    };
}

#endif /* BINARY_TREE__HEADER */