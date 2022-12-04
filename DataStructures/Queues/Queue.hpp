/* Filename: Queue.hpp */

/* This file includes all the basic function prototypes
   for a Queue Data Structure. Use of the Singly Linked List
   Data Structure. More details about Singly Linked List in file:
   "LinkedList.hpp" */

#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include <iostream>
#include "../Lists/LinkedList.hpp"
using namespace std;

template <typename type>
class Queue
{
public:
    /* Constructor and Copy Constructor */
    Queue();                         // Constructor
    Queue(const Queue<type> &other); // Copy Constructor

    // Getters
    Singly::Node<type> *GetFront() const; // Returns the front node of the queue
    Singly::Node<type> *GetRear() const;  // Returns the rear node of the queue

    /* Adding method */
    void Enqueue(type data); // Adds an element at the queue

    /* Removing Method */
    type Dequeue(); // Removes and returns the first element in the queue

    /* Printing method */
    // Cout method in file: "Queue.cpp"

private:
    Singly::LinkedList<type> list;
    Singly::Node<type> *front;
    Singly::Node<type> *rear;
};

#endif /* QUEUE_HEADER */