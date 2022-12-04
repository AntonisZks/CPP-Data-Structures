/* Filename: "LinkedList.hpp" */

/* This file includes all the basic function prototypes
   for a Singly Linked List Data Structure */

#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

#include <iostream>
using namespace std;

#define END -1
#define START 0

namespace Singly
{
    template <typename type>
    class Node
    {
    public:
        // Constructor
        Node() {}

        // Setters
        void set_data(type &data);
        void set_next(Node *const next_node);
        void set(type &data, Node *const next_node);

        // Getters
        type &get_data();
        Node<type> *get_next();

        // Printing Method
        template <typename item>
        friend ostream &operator<<(ostream &left, const Node<item> &right);

    private:
        type data;        // Data of the node
        Node<type> *next; // Pointer to the next node
    };

    template <typename type>
    class LinkedList
    {
    public:
        /* Constructor, Destructor and Copy Constructor */
        LinkedList();                              // Constructor
        ~LinkedList();                             // Destructor
        LinkedList(const LinkedList<type> &other); // Copy constructor

        /* Adding Methods */
        void Insert(type data, const int index = END);          // Adds data to the given position in the linked
        void Insert_at_start(type data);                        // Adds data to the start of the list
        void Insert_at_end(type data);                          // Adds data to the end of the list
        void Insert_at_position(type data, const int position); // Adds data to the given position

        /* Deleting Methods */
        void Delete_part(int start = START, int end = END); // Deletes all the nodes from start to end
        void Delete_start();                                // Deletes the first node of the list
        void Delete_end();                                  // Deletes the last node of the list
        void Delete_position(const int position);           // Deletes the given position of the list
        void Delete_all();                                  // Deletes all the nodes of the list

        /* Extracting Methods */
        type Extract_start();                              // Deletes and returns the data at the first node
        type Extract_end();                                // Deletes and returns the data at the last node
        type Extract_position(const int index);            // Deletes and returns the data at the given position of the list
        LinkedList<type> Extract_from(int start, int end); // Deletes and returns a list made from the main list according to the given start and end positions

        /* Replacing Methods */
        void Replace_start(const type data);                     // Replaces the data of the first node with the given data
        void Replace_end(const type data);                       // Replaces the data of the last node with the given data
        void Replace_position(const type data, const int index); // Replaces the data of the given index node with the given data

        /* Extending Methods */
        void Extend_start(const LinkedList<type> &other_list);                  // Adds a list at the start of the main list
        void Extend_end(const LinkedList<type> &other_list);                    // Adds a list at the end of the main list
        void Extend_at(const LinkedList<type> &other_list, const int position); // Adds a list at the given position of the main list

        /* Getters */
        Singly::Node<type> *Get_first_node() const;                  // Returns the first node
        Singly::Node<type> *Get_last_node() const;                   // Returns the last node
        Singly::Node<type> *Get_node_at(const int index) const;      // Returns the node at the given index
        Singly::Node<type> *Get_node_by_data(const type data) const; // Returns the node with the given data if it exists

        /* Sorting Methods */
        void Sort();               // Sorts the list
        LinkedList<type> Sorted(); // Returns a sorted version of the list

        /* Copying Method */
        LinkedList<type> Copy() const; // Creates a copy of the list

        /* Min and Max elements */
        type Min(); // Returns the minimum element of the list
        type Max(); // Returns the maximum element of the list

        /* Other Methods */
        int Length() const;             // Returns the length of the list
        bool Is_empty();                // Returns true if the list is empty or false if it is not
        int Count(const type data);     // Returns how many times the given data exists in the list
        int Index_of(const type data);  // Returns the index of the given data
        void Clear();                   // Clears the list
        bool Contains(const type data); // Returns true if the list contains the given data

        /* Printing Method */
        // template <typename item>
        // friend ostream &operator<<(ostream &left, const Singly::LinkedList<item> &right); // Cout method for the list

        /* Overloading */
        void operator=(Singly::LinkedList<type> &other_list); // Overloading operator =
        type &operator[](int index);                          // Overloading operator []

    private:
        int size;         // Size of the list
        Node<type> *head; // Pointer to the first node of the list
    };
}

namespace Doubly
{
    template <typename type>
    class Node
    {
    public:
        Node() {}

        // Setters
        void set_data(type &data);
        void set_next(Node *const next_node);
        void set_prev(Node *const prev_node);
        void set(type &data, Node *const prev_node, Node *const next_node);

        // Getters
        type &get_data();
        Node<type> *get_next();
        Node<type> *get_prev();

        // Printing Method
        template <typename item>
        friend ostream &operator<<(ostream &left, const Node<item> &right);

    private:
        type data;        // Data of the node
        Node<type> *next; // Pointer to the next node
        Node<type> *prev; // Pointer to the previous node
    };

    template <typename type>
    class LinkedList
    {
    public:
        /* Constructor, Destructor and Copy Constructor */
        LinkedList();                              // Constructor
        ~LinkedList();                             // Destructor
        LinkedList(const LinkedList<type> &other); // Copy constructor

        /* Adding Methods */
        void Insert(type data, const int index = END);          // Adds data to the given position in the linked
        void Insert_at_start(type data);                        // Adds data to the start of the list
        void Insert_at_end(type data);                          // Adds data to the end of the list
        void Insert_at_position(type data, const int position); // Adds data to the given position

        /* Deleting Methods */
        void Delete_part(int start = START, int end = END); // Deletes all the nodes from start to end
        void Delete_start();                                // Deletes the first node of the list
        void Delete_end();                                  // Deletes the last node of the list
        void Delete_position(int position);                 // Deletes the given position of the list
        void Delete_all();                                  // Deletes all the nodes of the list

        /* Extracting Methods */
        type Extract_start();                              // Deletes and returns the data at the first node
        type Extract_end();                                // Deletes and returns the data at the last node
        type Extract_position(const int index);            // Deletes and returns the data at the given position of the list
        LinkedList<type> Extract_from(int start, int end); // Deletes and returns a list made from the main list according to the given start and end positions

        /* Replacing Methods */
        void Replace_start(const type data);                     // Replaces the data of the first node with the given data
        void Replace_end(const type data);                       // Replaces the data of the last node with the given data
        void Replace_position(const type data, const int index); // Replaces the data of the given index node with the given data

        /* Extending Methods */
        void Extend_start(const LinkedList<type> &other_list);                  // Adds a list at the start of the main list
        void Extend_end(const LinkedList<type> &other_list);                    // Adds a list at the end of the main list
        void Extend_at(const LinkedList<type> &other_list, const int position); // Adds a list at the given position of the main list

        /* Getters */
        Doubly::Node<type> *Get_first_node() const;                  // Returns the first node
        Doubly::Node<type> *Get_last_node() const;                   // Returns the last node
        Doubly::Node<type> *Get_node_at(const int index) const;      // Returns the node at the given index
        Doubly::Node<type> *Get_node_by_data(const type data) const; // Returns the node with the given data if it exists

        /* Sorting Methods */
        void Sort();               // Sorts the list
        LinkedList<type> Sorted(); // Returns a sorted version of the list

        /* Copying Method */
        LinkedList<type> Copy() const; // Creates a copy of the list

        /* Min and Max elements */
        type Min(); // Returns the minimum element of the list
        type Max(); // Returns the maximum element of the list

        /* Other Methods */
        int Length() const;             // Returns the length of the list
        bool Is_empty();                // Returns true if the list is empty or false if it is not
        int Count(const type data);     // Returns how many times the given data exists in the list
        int Index_of(const type data);  // Returns the index of the given data
        void Clear();                   // Clears the list
        bool Contains(const type data); // Returns true if the list contains the given data

        /* Printing Method */
        // template <typename item>
        // friend ostream &operator<<(ostream &left, const Doubly::LinkedList<item> &right); // Cout method for the list

        /* Overloading */
        void operator=(Doubly::LinkedList<type> &other_list); // Overloading operator =
        type &operator[](int index);                          // Overloading operator []

    private:
        int size;                 // Size of the list
        Doubly::Node<type> *head; // Pointer to the first node of the list
        Doubly::Node<type> *tail; // Pointer to the last node of the list
    };
}

#endif /* LINKED_LIST_HEADER */