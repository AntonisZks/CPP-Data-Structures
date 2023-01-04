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
    template <typename ltype>
    class Node
    {
    public:
        // Constructor
        Node() {}

        // Setters
        void set_data(ltype &data);
        void set_next(Node *const next_node);
        void set(ltype &data, Node *const next_node);

        // Getters
        ltype &get_data();
        Node<ltype> *get_next();

        // Printing Method
        template <typename item>
        friend ostream &operator<<(ostream &left, const Node<item> &right);

    private:
        ltype data;        // Data of the node
        Node<ltype> *next; // Pointer to the next node
    };

    template <typename ltype>
    class LinkedList
    {
    public:
        /* Constructor, Destructor and Copy Constructor */
        LinkedList();                               // Constructor
        ~LinkedList();                              // Destructor
        LinkedList(const LinkedList<ltype> &other); // Copy constructor

        /* Adding Methods */
        void Insert(ltype data, const unsigned int index = END);          // Adds data to the given position in the linked
        void Insert_at_start(ltype data);                                 // Adds data to the start of the list
        void Insert_at_end(ltype data);                                   // Adds data to the end of the list
        void Insert_at_position(ltype data, const unsigned int position); // Adds data to the given position

        /* Deleting Methods */
        void Delete_part(int start = START, int end = END); // Deletes all the nodes from start to end
        void Delete_start();                                // Deletes the first node of the list
        void Delete_end();                                  // Deletes the last node of the list
        void Delete_position(const unsigned int position);  // Deletes the given position of the list
        void Delete_all();                                  // Deletes all the nodes of the list

        /* Extracting Methods */
        ltype Extract_start();                              // Deletes and returns the data at the first node
        ltype Extract_end();                                // Deletes and returns the data at the last node
        ltype Extract_position(const unsigned int index);   // Deletes and returns the data at the given position of the list
        LinkedList<ltype> Extract_from(int start, int end); // Deletes and returns a list made from the main list according to the given start and end positions

        /* Replacing Methods */
        void Replace_start(const ltype data);                              // Replaces the data of the first node with the given data
        void Replace_end(const ltype data);                                // Replaces the data of the last node with the given data
        void Replace_position(const ltype data, const unsigned int index); // Replaces the data of the given index node with the given data

        /* Extending Methods */
        void Extend_start(const LinkedList<ltype> &other_list);                           // Adds a list at the start of the main list
        void Extend_end(const LinkedList<ltype> &other_list);                             // Adds a list at the end of the main list
        void Extend_at(const LinkedList<ltype> &other_list, const unsigned int position); // Adds a list at the given position of the main list

        /* Getters */
        Singly::Node<ltype> *Get_first_node() const;                      // Returns the first node
        Singly::Node<ltype> *Get_last_node() const;                       // Returns the last node
        Singly::Node<ltype> *Get_node_at(const unsigned int index) const; // Returns the node at the given index
        Singly::Node<ltype> *Get_node_by_data(const ltype data) const;    // Returns the node with the given data if it exists

        /* Sorting Methods */
        void Sort();                // Sorts the list
        LinkedList<ltype> Sorted(); // Returns a sorted version of the list

        /* Copying Method */
        LinkedList<ltype> Copy() const; // Creates a copy of the list

        /* Min and Max elements */
        ltype Min(); // Returns the minimum element of the list
        ltype Max(); // Returns the maximum element of the list

        /* Other Methods */
        int Length() const;              // Returns the length of the list
        bool Is_empty();                 // Returns true if the list is empty or false if it is not
        int Count(const ltype data);     // Returns how many times the given data exists in the list
        int Index_of(const ltype data);  // Returns the index of the given data
        void Clear();                    // Clears the list
        bool Contains(const ltype data); // Returns true if the list contains the given data

        /* Printing Method */
        // template <typename item>
        // friend ostream &operator<<(ostream &left, const Singly::LinkedList<item> &right); // Cout method for the list

        /* Overloading */
        void operator=(Singly::LinkedList<ltype> &other_list); // Overloading operator =
        ltype &operator[](int index);                          // Overloading operator []

    private:
        int size;          // Size of the list
        Node<ltype> *head; // Pointer to the first node of the list
    };
}

namespace Doubly
{
    template <typename ltype>
    class Node
    {
    public:
        Node() {}

        // Setters
        void set_data(ltype &data);
        void set_next(Node *const next_node);
        void set_prev(Node *const prev_node);
        void set(ltype &data, Node *const prev_node, Node *const next_node);

        // Getters
        ltype &get_data();
        Node<ltype> *get_next();
        Node<ltype> *get_prev();

        // Printing Method
        template <typename item>
        friend ostream &operator<<(ostream &left, const Node<item> &right);

    private:
        ltype data;        // Data of the node
        Node<ltype> *next; // Pointer to the next node
        Node<ltype> *prev; // Pointer to the previous node
    };

    template <typename ltype>
    class LinkedList
    {
    public:
        /* Constructor, Destructor and Copy Constructor */
        LinkedList();                               // Constructor
        ~LinkedList();                              // Destructor
        LinkedList(const LinkedList<ltype> &other); // Copy constructor

        /* Adding Methods */
        void Insert(ltype data, const unsigned int index = END);          // Adds data to the given position in the linked
        void Insert_at_start(ltype data);                                 // Adds data to the start of the list
        void Insert_at_end(ltype data);                                   // Adds data to the end of the list
        void Insert_at_position(ltype data, const unsigned int position); // Adds data to the given position

        /* Deleting Methods */
        void Delete_part(int start = START, int end = END); // Deletes all the nodes from start to end
        void Delete_start();                                // Deletes the first node of the list
        void Delete_end();                                  // Deletes the last node of the list
        void Delete_position(int position);                 // Deletes the given position of the list
        void Delete_all();                                  // Deletes all the nodes of the list

        /* Extracting Methods */
        ltype Extract_start();                              // Deletes and returns the data at the first node
        ltype Extract_end();                                // Deletes and returns the data at the last node
        ltype Extract_position(const unsigned int index);   // Deletes and returns the data at the given position of the list
        LinkedList<ltype> Extract_from(int start, int end); // Deletes and returns a list made from the main list according to the given start and end positions

        /* Replacing Methods */
        void Replace_start(const ltype data);                              // Replaces the data of the first node with the given data
        void Replace_end(const ltype data);                                // Replaces the data of the last node with the given data
        void Replace_position(const ltype data, const unsigned int index); // Replaces the data of the given index node with the given data

        /* Extending Methods */
        void Extend_start(const LinkedList<ltype> &other_list);                           // Adds a list at the start of the main list
        void Extend_end(const LinkedList<ltype> &other_list);                             // Adds a list at the end of the main list
        void Extend_at(const LinkedList<ltype> &other_list, const unsigned int position); // Adds a list at the given position of the main list

        /* Getters */
        Doubly::Node<ltype> *Get_first_node() const;                      // Returns the first node
        Doubly::Node<ltype> *Get_last_node() const;                       // Returns the last node
        Doubly::Node<ltype> *Get_node_at(const unsigned int index) const; // Returns the node at the given index
        Doubly::Node<ltype> *Get_node_by_data(const ltype data) const;    // Returns the node with the given data if it exists

        /* Sorting Methods */
        void Sort();                // Sorts the list
        LinkedList<ltype> Sorted(); // Returns a sorted version of the list

        /* Copying Method */
        LinkedList<ltype> Copy() const; // Creates a copy of the list

        /* Min and Max elements */
        ltype Min(); // Returns the minimum element of the list
        ltype Max(); // Returns the maximum element of the list

        /* Other Methods */
        int Length() const;              // Returns the length of the list
        bool Is_empty();                 // Returns true if the list is empty or false if it is not
        int Count(const ltype data);     // Returns how many times the given data exists in the list
        int Index_of(const ltype data);  // Returns the index of the given data
        void Clear();                    // Clears the list
        bool Contains(const ltype data); // Returns true if the list contains the given data

        /* Printing Method */
        // template <typename item>
        // friend ostream &operator<<(ostream &left, const Doubly::LinkedList<item> &right); // Cout method for the list

        /* Overloading */
        void operator=(Doubly::LinkedList<ltype> &other_list); // Overloading operator =
        ltype &operator[](int index);                          // Overloading operator []

    private:
        int size;                  // Size of the list
        Doubly::Node<ltype> *head; // Pointer to the first node of the list
        Doubly::Node<ltype> *tail; // Pointer to the last node of the list
    };
}

#endif /* LINKED_LIST_HEADER */