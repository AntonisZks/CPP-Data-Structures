/* Filename: Stack.hpp */

/* This file includes all the basic functions
   for a Stack Data Structure. Use of the Singly Linked List
   Data Structure. More details about Singly Linked List in file:
   "LinkedList.hpp" */

#include <iostream>
#include "Stack.hpp"
using namespace std;

/* STACK METHODS */
template <typename type>
Stack<type>::Stack()
{
    // Setting the top Node be NULL
    this->top = new Singly::Node<type>();
    this->top = NULL;
}

template <typename type>
Stack<type>::Stack(const Stack<type> &other)
{
    // Creating a copy of the Stack
    Singly::Node<type> *current_node = other.GetListHead();

    while (current_node != NULL)
    {
        this->list.Insert(current_node->get_data());
        current_node = current_node->get_next();
    }
    this->top = other.GetTop();
}

template <typename type>
Singly::Node<type>* Stack<type>::GetListHead() const
{
    return this->list.Get_first_node();
}

template <typename type>
Singly::Node<type>* Stack<type>::GetTop() const
{
    return this->list.Get_first_node();
}

template <typename type>
void Stack<type>::Push(type data)
{
    // Pushing an item in the Stack
    this->list.Insert_at_end(data);
    this->top = this->list.Get_last_node();
}

template <typename type>
type Stack<type>::Pop()
{
    // Checking if the Stack is Empty
    if (this->list.Is_empty())
    {
        cout << "Stack is empty!" << endl;
        exit(1);
    }

    // Popping and returning the item at the top of the Stack
    type data = this->list.Extract_end();
    this->top = this->list.Get_last_node();
    return data;
}

template <typename type>
ostream &operator<<(ostream &left, Stack<type> &right)
{
    // Initializing a current node
    Singly::Node<type> *current_node = right.GetListHead();

    // Keeping every element of the Stack
    left << "[";
    while (current_node != NULL)
    {
        left << current_node->get_data();
        if (current_node->get_next() != NULL)
            left << ", ";
        current_node = current_node->get_next();
    }
    left << "]";
    return left;
}