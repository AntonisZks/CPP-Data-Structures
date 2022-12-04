/* Filename: Stack.hpp */

/* This file includes all the basic function prototypes
   for a Stack Data Structure. Use of the Singly Linked List
   Data Structure. More details about Singly Linked List in file:
   "LinkedList.hpp" */

#ifndef STACK_HEADER
#define STACK_HEADER

#include <iostream>
#include "../Lists/LinkedList.hpp"
using namespace std;

template <typename type>
class Stack
{
public:
    /* Constructor and Copy Constructor */
    Stack();                         // Constructor
    Stack(const Stack<type> &other); // Copy Constructor

    // Getters
    Singly::Node<type> *GetListHead() const; // Returns the first node of the stack
    Singly::Node<type> *GetTop() const;      // Returns the last node of the stack

    /* Adding Method */
    void Push(type data); // Adds an element at the stack

    /* Removing Method */
    type Pop(); // Removes and returns the last element in the stack

    /* Printing Method */
    // Cout Method in file: "Stack.cpp"

private:
    Singly::LinkedList<type> list;
    Singly::Node<type> *top;
};

#endif /* STACK_HEADER */