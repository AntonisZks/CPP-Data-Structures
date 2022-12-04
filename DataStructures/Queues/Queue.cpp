/* Filename: Queue.hpp */

/* This file includes all the basic functions
   for a Queue Data Structure. Use of the Singly Linked List
   Data Structure. More details about Singly Linked List in file:
   "LinkedList.hpp" */

#include <iostream>
#include "Queue.hpp"
using namespace std;

/* QUEUE METHODS */
template <typename type>
Queue<type>::Queue()
{
    // Setting the front and rear nodes be NULL
    this->front = new Singly::Node<type>();
    this->rear = new Singly::Node<type>();
    this->front = NULL;
    this->rear = NULL;
}

template <typename type>
Queue<type>::Queue(const Queue<type> &other)
{
    // Creating a copy of the queue
    Singly::Node<type> *current_node = other.GetFront();

    while (current_node != NULL)
    {
        this->list.Insert(current_node->get_data());
        current_node = current_node->get_next();
    }
    this->rear = other.GetRear();
}

template <typename type>
Singly::Node<type>* Queue<type>::GetFront() const
{
    return this->list.Get_first_node();
}

template <typename type>
Singly::Node<type>* Queue<type>::GetRear() const
{
    return this->list.Get_last_node();
}

template <typename type>
void Queue<type>::Enqueue(type data)
{
    // Adding an item in the queue
    this->list.Insert_at_end(data);
    this->rear = this->list.Get_last_node();
}

template <typename type>
type Queue<type>::Dequeue()
{
    // Checking if the queue is Empty
    if (this->list.Is_empty())
    {
        cout << "Queue is empty!" << endl;
        exit(1);
    }

    // Removing and returning the item at the front of the queue
    this->front = this->list.Get_first_node()->get_next();
    type data = this->list.Extract_start();
    return data;
}

template <typename type>
ostream &operator<<(ostream &left, Queue<type> &right)
{
    // Initializing a current node
    Singly::Node<type> *current_node = right.GetFront();

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