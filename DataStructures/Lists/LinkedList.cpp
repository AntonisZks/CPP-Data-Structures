#include <iostream>
#include "LinkedList.hpp"
using namespace std;

/* SINGLY LINKED LIST NODE METHODS */
template <typename ltype>
void Singly::Node<ltype>::set_data(ltype &data)
{
    // Setting the data
    this->data = data;
}

template <typename ltype>
void Singly::Node<ltype>::set_next(Singly::Node<ltype> *const next_node)
{
    // Setting the next node
    this->next = next_node;
}

template <typename ltype>
void Singly::Node<ltype>::set(ltype &data, Singly::Node<ltype> *const next_node)
{
    // Creating the node
    this->set_data(data);
    this->set_next(next_node);
}

template <typename ltype>
ltype &Singly::Node<ltype>::get_data()
{
    // Returning the current data of the node
    return this->data;
}

template <typename ltype>
Singly::Node<ltype> *Singly::Node<ltype>::get_next()
{
    // Returning the current next node or NULL if there is no next node
    if (this->next == NULL)
        return NULL;
    return this->next;
}

template <typename item>
ostream &operator<<(ostream &left, const Singly::Node<item> &right)
{
    left << right.data;
    return left;
}

/* DOUBLY LINKED LIST NODE METHODS */
template <typename ltype>
void Doubly::Node<ltype>::set_data(ltype &data)
{
    // Setting the data
    this->data = data;
}

template <typename ltype>
void Doubly::Node<ltype>::set_next(Doubly::Node<ltype> *const next_node)
{
    // Setting the next node
    this->next = next_node;
}

template <typename ltype>
void Doubly::Node<ltype>::set_prev(Doubly::Node<ltype> *const prev_node)
{
    // Setting the previous node
    this->prev = prev_node;
}

template <typename ltype>
void Doubly::Node<ltype>::set(ltype &data, Doubly::Node<ltype> *const prev_node, Doubly::Node<ltype> *const next_node)
{
    // Creating the node
    this->set_data(data);
    this->set_next(next_node);
    this->set_prev(prev_node);
}

template <typename ltype>
ltype &Doubly::Node<ltype>::get_data()
{
    // Returning the current data of the node
    return this->data;
}

template <typename ltype>
Doubly::Node<ltype> *Doubly::Node<ltype>::get_next()
{
    // Returning the current next node or NULL if there is no next node
    if (this->next == NULL)
        return NULL;
    return this->next;
}

template <typename ltype>
Doubly::Node<ltype> *Doubly::Node<ltype>::get_prev()
{
    // Returning the current previous node or NULL if there is no previous node
    if (this->prev == NULL)
        return NULL;
    return this->prev;
}

template <typename item>
ostream &operator<<(ostream &left, const Doubly::Node<item> &right)
{
    left << right.data;
    return left;
}

/* SINGLY LINKED LIST METHODS */
template <typename ltype>
Singly::LinkedList<ltype>::LinkedList()
{
    // Initializing the linked list
    this->head = NULL;
    this->size = 0;
    // cout << "Singly Linked List Constructed with " << this->size << " elements." << endl;
}

template <typename ltype>
Singly::LinkedList<ltype>::LinkedList(const Singly::LinkedList<ltype> &other)
{
    // Initializing a current node as the first node of the other list
    Singly::Node<ltype> *current_node = other.Get_first_node();

    this->head = NULL; // Setting the head point to NULL
    while (current_node != NULL)
    {
        this->Insert(current_node->get_data());  // Copying the elements
        current_node = current_node->get_next(); // Setting the current node be the next node
    }
}

template <typename ltype>
Singly::LinkedList<ltype>::~LinkedList()
{
    // Initializing a current node
    Singly::Node<ltype> *current_node;

    // Deleting every node in the linked list
    while (this->head != NULL)
    {
        current_node = this->head;
        this->head = this->head->get_next();
        delete current_node;
    }
    // cout << "Singly Linked List Destructed with " << this->size << " elements." << endl;
}

template <typename item>
ostream &operator<<(ostream &left, const Singly::LinkedList<item> &right)
{
    // Initializing a current node
    Singly::Node<item> *current_node = right.Get_first_node();

    // Giving a good printing
    left << "[";
    while (current_node != NULL)
    {
        left << current_node->get_data();
        if (current_node->get_next() != NULL)
            left << " -> ";
        current_node = current_node->get_next();
    }
    left << "]";
    return left;
}

template <typename ltype>
void Singly::LinkedList<ltype>::Insert_at_start(ltype data)
{

    // Initializing a new node
    Singly::Node<ltype> *new_node = new Singly::Node<ltype>;

    // Checking if memory allocation worked successfully
    if (!new_node)
        exit(1);

    // Creating the new node
    new_node->set(data, NULL);

    // Checking if the list is empty
    if (this->head == NULL)
        this->head = new_node; // Setting the head point to the new node
    else
    {
        new_node->set_next(this->head); // Setting new node point to the head
        this->head = new_node;          // Setting the head point to the new node
    }
    this->size++; // Updating the size
}

template <typename ltype>
void Singly::LinkedList<ltype>::Insert_at_end(ltype data)
{
    // Initializing a new node and a current node
    Singly::Node<ltype> *new_node = new Singly::Node<ltype>, *current_node = this->head;

    // Checking if memory allocation worked successfully
    if (!new_node)
        exit(1);

    // Creating the new node
    new_node->set(data, NULL);

    // Checking if the list is empty
    if (this->head == NULL)
        this->head = new_node; // Setting the head point to the new node
    else
    {
        // Accessing the last node in the list
        while (current_node->get_next() != NULL)
            current_node = current_node->get_next();

        // Setting the last node point to the new node. Now the new node is the last node in the list
        current_node->set_next(new_node);
    }
    this->size++; // Updating the size
}

template <typename ltype>
void Singly::LinkedList<ltype>::Insert_at_position(ltype data, const unsigned int position)
{
    // Initializing a new node and a current node
    Singly::Node<ltype> *new_node = new Singly::Node<ltype>, *current_node = this->head;

    // Checking if memory allocation worked successfully
    new_node->set(data, NULL);

    // Checking if the position is not valid
    if (position > this->size)
    {
        cout << "List has " << this->size << " elements but you entered " << position << " as a value position!" << endl;
        exit(1);
    }

    // If the position is equal to the size of the list plus 1 then Insert at the end
    else if (position == this->size + 1)
        this->Insert_at_end(data); // Inserting at the end

    // Accessing the given position of the list
    for (unsigned int i = 0; i < position - 1; i++)
        current_node = current_node->get_next();

    new_node->set_next(current_node->get_next()); // Setting the new node point to the next node
    current_node->set_next(new_node);             // Setting the previous node point to the new node
    this->size++;                                 // Updating the size
}

template <typename ltype>
void Singly::LinkedList<ltype>::Insert(ltype data, const unsigned int index)
{
    switch (index)
    {
    case START:
        this->Insert_at_start(data);
        break; // Inserting at the start
    case END:
        this->Insert_at_end(data);
        break; // Insert at the end
    default:
        this->Insert_at_position(data, index);
        break; // Insert at the given position
    }
}

template <typename ltype>
void Singly::LinkedList<ltype>::Delete_start()
{
    // Initializing a current node
    Singly::Node<ltype> *current_node = this->head; // The current node is the first node of the list

    // Checking if the list is empty
    if (this->head == NULL)
        cout << "You tried to delete a node while the list is empty." << endl;

    // Deleting the first node
    this->head = this->head->get_next(); // Setting the head point to the second node
    delete current_node;                 // Delete the first node
    this->size--;                        // Updating the size
}

template <typename ltype>
void Singly::LinkedList<ltype>::Delete_end()
{
    // initializing a current node and a previous node
    Singly::Node<ltype> *current_node, *previous_node;

    // Checking if the list is empty
    if (this->head == NULL)
        cout << "You tried to delete a node while the list is empty." << endl;

    // Checking if the list has only one node
    if (this->head->get_next() == NULL)
    {
        // Delete the list
        current_node = this->head; // Setting the current node be the first node
        delete current_node;       // Delete the current node
        this->head = NULL;         // Setting the head point to NULL

        this->size--; // Updating the size
        return;
    }

    current_node = this->head;  // Setting the current node be the first node
    previous_node = this->head; // Setting the previous node be the first node too

    // Accessing the last node
    while (current_node->get_next() != NULL)
    {
        previous_node = current_node;            // Setting the previous node be the current node
        current_node = current_node->get_next(); // Setting the current node be the next node
    }

    // Deleting the last node of the list
    previous_node->set_next(NULL); // Setting the previous node point to NULL
    delete current_node;           // Deleting the current node

    this->size--; // Updating the size
}

template <typename ltype>
void Singly::LinkedList<ltype>::Delete_position(const unsigned int position)
{
    // initializing a current node and a previous node
    Singly::Node<ltype> *current_node = this->head, *previous_node;

    // Checking if the list is empty
    if (this->head == NULL)
        cout << "You tried to delete a node while the list is empty." << endl;

    // Checking if the position is not valid
    if (position < 0 || position > this->size - 1)
    {
        cout << "List has " << this->size << " elements but you entered " << position << " as a position to be deleted." << endl;
        exit(1);
    }

    // Accessing the node at the given position
    if (position == 0)
        this->Delete_start(); // Delete the start
    else if (position == this->size)
        this->Delete_end(); // Delete the end
    else
    {
        for (unsigned int i = 0; i < position; i++)
        {
            previous_node = current_node;            // Setting the previous node be the current node
            current_node = current_node->get_next(); // Setting the current node be the next node
        }
        // Deleting the node at the given position
        previous_node->set_next(current_node->get_next()); // Setting the previous node point to the next node of the current node
        delete current_node;                               // Delete the current node

        this->size--; // Updating the size
    }
}

template <typename ltype>
void Singly::LinkedList<ltype>::Delete_all()
{
    // Initializing a current node and a previous node
    Singly::Node<ltype> *current_node, *previous_node;

    // Checking if the list is empty
    if (this->head == NULL)
        cout << "List is already empty." << endl;

    // Deleting every node
    current_node = this->head;  // Setting the current node be the first node
    previous_node = this->head; // Setting the previous node be the first node
    while (current_node != NULL)
    {
        previous_node = current_node;            // Setting the previous node be the current node
        current_node = current_node->get_next(); // Setting the current node be the next node
        delete previous_node;                    // Delete the previous node
    }
    this->size = 0;    // Updating the size
    this->head = NULL; // Setting the head point to NULL
}

template <typename ltype>
void Singly::LinkedList<ltype>::Delete_part(int start, int end)
{
    // Initializing a current node, a previous node, a start_node and an end node
    Singly::Node<ltype> *current_node = this->head, *previous_node;
    Singly::Node<ltype> *start_node, *end_node;

    if (end == END)
        end = this->size - 1;

    // Checking if the start and end positions are not valid
    if (start > end || start < 0 || start > this->size - 1 || end < 0 || end > this->size - 1)
    {
        cout << "The given positions are not valid. List has " << this->size << " elements." << endl;
        exit(1);
    }

    // Checking if the list is empty
    if (this->head == NULL)
        cout << "You tried to delete a part of the list while the list is empty." << endl;

    // Accesing the node at the given start position
    for (unsigned int i = 0; i < start; i++)
    {
        if (i == start - 1)
            start_node = current_node;           // Setting the start node be the current node
        current_node = current_node->get_next(); // Setting the current node be the next node
    }

    // Deleting every node until the given end position
    for (unsigned int i = start; i < end; i++)
    {
        if (i == end - 1)
            end_node = current_node->get_next(); // Setting the end node be the next node of the current node
        previous_node = current_node;            // Setting the previous node be the current node
        current_node = current_node->get_next(); // Setting the current node be the next node
        delete previous_node;                    // Deleting the previous node
    }
    if (start > 0)
        start_node->set_next(end_node); // Setting the start node point to the next node
    else
        this->head = end_node; // Setting the head point to the end node

    this->size = end - start; // Updating the size
}

template <typename ltype>
Singly::Node<ltype> *Singly::LinkedList<ltype>::Get_first_node() const
{
    // Return the first node
    return this->head;
}

template <typename ltype>
Singly::Node<ltype> *Singly::LinkedList<ltype>::Get_last_node() const
{
    // initializing a current node
    Singly::Node<ltype> *current_node = this->head;

    // Accessing the last node
    while (current_node->get_next() != NULL)
        current_node = current_node->get_next(); // Setting the current node be the next node

    // Return the last node
    return current_node;
}

template <typename ltype>
Singly::Node<ltype> *Singly::LinkedList<ltype>::Get_node_at(const unsigned int index) const
{
    // Initializing a current node
    Singly::Node<ltype> *current_node = this->head;

    // Checking if the index is not valid
    if (index < 0 || index > this->size)
    {
        cout << "List has " << this->size << " elements but you entered " << index << " as an access position." << endl;
        exit(1);
    }

    // Accessing node at the given position
    for (unsigned int i = 0; i < index; i++)
        current_node = current_node->get_next(); // Setting the current node be the next node

    // Return the current node
    return current_node;
}

template <typename ltype>
Singly::Node<ltype> *Singly::LinkedList<ltype>::Get_node_by_data(const ltype data) const
{
    // Initializing a current node
    Singly::Node<ltype> *current_node = this->head;

    // Searching for the given data
    while (current_node != NULL)
    {
        if (current_node->get_data() == data)
            return current_node;
        current_node = current_node->get_next();
    }
    return NULL;
}

template <typename ltype>
ltype Singly::LinkedList<ltype>::Extract_start()
{
    // Initializing a data variable that keeps the data of the first node
    ltype data = this->head->get_data();

    // Deleting the first node
    this->Delete_start();

    // Return the data
    return data;
}

template <typename ltype>
ltype Singly::LinkedList<ltype>::Extract_end()
{
    // Initializing a data variable that keeps the data of the last node
    ltype data = this->Get_last_node()->get_data();

    // Deleting the last node
    this->Delete_end();

    // Return the data
    return data;
}

template <typename ltype>
ltype Singly::LinkedList<ltype>::Extract_position(const unsigned int index)
{
    // Checking if the given index is not valid
    if (index < 0 || index > this->size)
    {
        cout << "List has " << this->size << " elements but you entered " << index << " as an access position." << endl;
        exit(1);
    }

    // Initializing a data variable that keeps the data of the node at the given position
    ltype data = this->Get_node_at(index)->get_data();

    // Deleting the given node
    this->Delete_position(index);

    // Return the data
    return data;
}

template <typename ltype>
Singly::LinkedList<ltype> Singly::LinkedList<ltype>::Extract_from(int start, int end)
{
    // Initializing a new linked list as the result of the function
    Singly::LinkedList<ltype> result_list;

    // Initializing a variable that keeps the the data of the nodes
    ltype data;

    // Accessing all the nodes from the given start position up to the given end position
    for (unsigned int i = start; i <= end; i++)
    {
        data = this->Get_node_at(i)->get_data();
        result_list.Insert_at_end(data); // Creating the result list
    }

    // Deleting the given part of the main list
    this->Delete_part(start, end + 1);

    return result_list;
}

template <typename ltype>
void Singly::LinkedList<ltype>::Replace_start(const ltype data)
{
    // Changing the data of the first node
    this->head->set_data(data);
}

template <typename ltype>
void Singly::LinkedList<ltype>::Replace_end(const ltype data)
{
    // Initializing a last node as the last node of the list
    Singly::Node<ltype> *last_node = this->Get_last_node();

    // Changing the data of the last node
    last_node->set_data(data);
}

template <typename ltype>
void Singly::LinkedList<ltype>::Replace_position(const ltype data, const unsigned int index)
{
    // Initializing a current node as the node at the given position
    Singly::Node<ltype> *current_node = this->Get_node_at(index);

    // Changing the data of the current node
    current_node->set_data(data);
}

template <typename ltype>
void Singly::LinkedList<ltype>::Sort()
{
    // Initializing a left node and a right node
    Singly::Node<ltype> *left_node, *right_node;
    ltype temp;

    // Bubble Sort Algorithm for Linke List
    for (unsigned int i = 0; i < this->size; i++)
        for (int j = 0; j < this->size - i - 1; j++)
        {
            left_node = this->Get_node_at(j);
            right_node = this->Get_node_at(j + 1);
            if (left_node->get_data() > right_node->get_data())
            {
                temp = left_node->get_data();
                left_node->set_data(right_node->get_data());
                right_node->set_data(temp);
            }
        }
}

template <typename ltype>
Singly::LinkedList<ltype> Singly::LinkedList<ltype>::Sorted()
{
    // Initializing a linked list
    Singly::LinkedList<ltype> result_list = this->Copy();

    // Sort the list
    result_list.Sort();

    return result_list;
}

template <typename ltype>
Singly::LinkedList<ltype> Singly::LinkedList<ltype>::Copy() const
{
    // Initializing a new linked list
    Singly::LinkedList<ltype> new_linked_list;

    // Initializing a current node
    Singly::Node<ltype> *current_node = this->head;

    // Copying every node of the list to the new list
    while (current_node != NULL)
    {
        new_linked_list.Insert(current_node->get_data());
        current_node = current_node->get_next();
    }

    return new_linked_list;
}

template <typename ltype>
ltype Singly::LinkedList<ltype>::Min()
{
    // Initializing a data variable that keeps the minimum element
    ltype min_data;

    // Initializing a current node
    Singly::Node<ltype> *current_node = this->head;
    min_data = current_node->get_data();

    // Searching for the minimum element
    while (current_node->get_next() != NULL)
    {
        current_node = current_node->get_next(); // Setting the current node be the next node
        if (current_node->get_data() < min_data)
            min_data = current_node->get_data();
    }
    return min_data;
}

template <typename ltype>
ltype Singly::LinkedList<ltype>::Max()
{
    // Initializing a data variable that keeps the maximum element
    ltype max_data;

    // Initializing a current node
    Singly::Node<ltype> *current_node = this->head;
    max_data = current_node->get_data();

    // Searching for the maximum element
    while (current_node->get_next() != NULL)
    {
        current_node = current_node->get_next(); // Setting the current node be the next node
        if (current_node->get_data() > max_data)
            max_data = current_node->get_data();
    }
    return max_data;
}

template <typename ltype>
int Singly::LinkedList<ltype>::Length() const
{
    return this->size;
}

template <typename ltype>
bool Singly::LinkedList<ltype>::Is_empty()
{
    return this->size == 0;
}

template <typename ltype>
int Singly::LinkedList<ltype>::Count(const ltype data)
{
    // Initializing a variable that keeps how many times the given data exists in the list
    int times = 0;

    // Initializing a current node
    Singly::Node<ltype> *current_node = this->head;

    // Searching for the given data
    while (current_node != NULL)
    {
        if (current_node->get_data() == data)
            times++;
        current_node = current_node->get_next(); // Setting the current node be the next node
    }
    return times;
}

template <typename ltype>
int Singly::LinkedList<ltype>::Index_of(const ltype data)
{
    // Initializing a current node
    Singly::Node<ltype> *current_node = this->head;

    // Searching for the given data
    for (unsigned int i = 0; i < this->size; i++)
    {
        if (current_node->get_data() == data)
            return i;
        current_node = current_node->get_next(); // Setting the current node be the
    }
    return -1;
}

template <typename ltype>
void Singly::LinkedList<ltype>::Clear()
{
    // Initializing a current node and a previous node
    Singly::Node<ltype> *current_node, *previous_node;

    // Deleting every node
    current_node = this->head;  // Setting the current node be the first node
    previous_node = this->head; // Setting the previous node be the first node
    while (current_node != NULL)
    {
        previous_node = current_node;            // Setting the previous node be the current node
        current_node = current_node->get_next(); // Setting the current node be the next node
        delete previous_node;                    // Delete the previous node
    }
    this->size = 0;    // Updating the size
    this->head = NULL; // Setting the head point to NULL
}

template <typename ltype>
void Singly::LinkedList<ltype>::Extend_start(const Singly::LinkedList<ltype> &other_list)
{
    // Initializing a variable that keeps the data of the nodes
    ltype data;

    // Checking if the list is the same
    if (other_list.Get_first_node() == this->Get_first_node())
    {
        // Create a new list
        Singly::LinkedList<ltype> new_list = other_list.Copy();

        // Creating copies of all the nodes of the other list starting from the end
        for (unsigned int i = other_list.Length() - 1; i >= 0; i--)
        {
            // Getting all the data from the other list starting from the end
            data = new_list.Get_node_at(i)->get_data();

            // Adding the new node at the beginning of the main list
            this->Insert_at_start(data);
        }
    }
    else
    {
        // Creating copies of all the nodes of the other list starting from the end
        for (unsigned int i = other_list.Length() - 1; i >= 0; i--)
        {
            // Getting all the data from the other list starting from the end
            data = other_list.Get_node_at(i)->get_data();

            // Adding the new node at the beginning of the main list
            this->Insert_at_start(data);
        }
    }
}

template <typename ltype>
void Singly::LinkedList<ltype>::Extend_end(const Singly::LinkedList<ltype> &other_list)
{
    // Initializing a variable that keeps the data of the nodes
    ltype data;

    // Checking if the list is the same
    if (other_list.Get_first_node() == this->Get_first_node())
    {
        // Create a new list
        Singly::LinkedList<ltype> new_list = other_list.Copy();

        // Creating copies of all the nodes of the other list starting from the end
        for (unsigned int i = 0; i < new_list.Length(); i++)
        {
            // Getting all the data from the other list starting from the end
            data = new_list.Get_node_at(i)->get_data();

            // Adding the new node at the beginning of the main list
            this->Insert_at_end(data);
        }
    }
    else
    {
        // Creating copies of all the nodes of the other list starting from the end
        for (unsigned int i = 0; i < other_list.Length(); i++)
        {
            // Getting all the data from the other list starting from the end
            data = other_list.Get_node_at(i)->get_data();

            // Adding the new node at the beginning of the main list
            this->Insert_at_end(data);
        }
    }
}

template <typename ltype>
void Singly::LinkedList<ltype>::Extend_at(const Singly::LinkedList<ltype> &other_list, const unsigned int position)
{
    // Initializing a variable that keeps the data of the nodes
    ltype data;

    // Checking if the list is the same
    if (other_list.Get_first_node() == this->Get_first_node())
    {
        // Create a new list
        Singly::LinkedList<ltype> new_list = other_list.Copy();

        // Creating copies of all the nodes of the other list starting from the end
        for (unsigned int i = other_list.Length() - 1; i >= 0; i--)
        {
            // Getting all the data from the other list starting from the end
            data = new_list.Get_node_at(i)->get_data();

            // Adding the new node at the beginning of the main list
            this->Insert_at_position(data, position);
        }
    }
    else
    {
        // Creating copies of all the nodes of the other list starting from the end
        for (unsigned int i = other_list.Length() - 1; i >= 0; i--)
        {
            // Getting all the data from the other list starting from the end
            data = other_list.Get_node_at(i)->get_data();

            // Adding the new node at the beginning of the main list
            this->Insert_at_position(data, position);
        }
    }
}

template <typename ltype>
void Singly::LinkedList<ltype>::operator=(Singly::LinkedList<ltype> &other_list)
{
    // Initializing a current node as the fist node of the other list
    Singly::Node<ltype> *current_node = other_list.Get_first_node();

    // Delete the main list
    this->Clear();

    // Copying every node to the main list
    while (current_node != NULL)
    {
        this->Insert(current_node->get_data());
        current_node = current_node->get_next(); // Setting the current node be the next node
    }
}

template <typename ltype>
ltype &Singly::LinkedList<ltype>::operator[](int index)
{
    // Checking if the index is not valid
    if (index < 0 || index >= this->size)
    {
        cout << "List index out of bound." << endl;
        exit(1);
    }
    return this->Get_node_at(index)->get_data();
}

template <typename ltype>
bool Singly::LinkedList<ltype>::Contains(const ltype data)
{
    // Initializing a current node
    Singly::Node<ltype> *current_node = this->head;

    // Searching for the given data
    while (current_node != NULL)
    {
        if (current_node->get_data() == data)
            return true;
        current_node = current_node->get_next();
    }
    return false;
}

/* DOUBLY LINKED LIST METHODS */
template <typename ltype>
Doubly::LinkedList<ltype>::LinkedList()
{
    // Initializing the linked list
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
}

template <typename ltype>
Doubly::LinkedList<ltype>::LinkedList(const Doubly::LinkedList<ltype> &other)
{
    // Initializing a current node as the first node of the other list
    Doubly::Node<ltype> *current_node = other.Get_first_node();

    this->head = NULL; // Setting the head point to NULL
    while (current_node != NULL)
    {
        this->Insert(current_node->get_data());  // Copying the elements
        current_node = current_node->get_next(); // Setting the current node be the next node
    }
}

template <typename ltype>
Doubly::LinkedList<ltype>::~LinkedList()
{
    // Initializing a current node
    Doubly::Node<ltype> *current_node;

    // Deleting every node in the linked list
    while (this->head != NULL)
    {
        current_node = this->head;
        this->head = this->head->get_next();
        delete current_node;
    }
    this->tail = NULL; // Setting the tail point to NULL
}

template <typename item>
ostream &operator<<(ostream &left, const Doubly::LinkedList<item> &right)
{
    // Initializing a current node
    Doubly::Node<item> *current_node = right.Get_first_node();

    // Giving a good printing
    left << "[";
    while (current_node != NULL)
    {
        left << current_node->get_data();
        if (current_node->get_next() != NULL)
            left << " <-> ";
        current_node = current_node->get_next();
    }
    left << "]";
    return left;
}

template <typename ltype>
void Doubly::LinkedList<ltype>::Insert_at_start(ltype data)
{

    // Initializing a new node
    Doubly::Node<ltype> *new_node = new Doubly::Node<ltype>;

    // Checking if memory allocation worked successfully
    if (!new_node)
        exit(1);

    // Creating the new node
    new_node->set(data, NULL, NULL);

    // Checking if the list is empty
    if (this->head == NULL)
    {
        this->head = new_node; // Setting the head point to the new node
        this->tail = new_node; // Setting the tail point to the new node
    }
    else
    {
        new_node->set_next(this->head); // Setting the new node point to the head
        this->head->set_prev(new_node); // Setting the first node point back to the new node
        this->tail = this->head;        // Setting the tail point to the last node
        this->head = new_node;          // Setting the head point to the new node
    }
    this->size++; // Updating the size
}

template <typename ltype>
void Doubly::LinkedList<ltype>::Insert_at_end(ltype data)
{
    // Initializing a new node and a current node
    Doubly::Node<ltype> *new_node = new Doubly::Node<ltype>, *current_node = this->head;

    // Checking if memory allocation worked successfully
    if (!new_node)
        exit(1);

    // Creating the new node
    new_node->set(data, NULL, NULL);

    // Checking if the list is empty
    if (this->head == NULL)
        this->head = new_node; // Setting the head point to the new node
    else
    {
        // Accessing the last node in the list
        while (current_node->get_next() != NULL)
            current_node = current_node->get_next();

        // Setting the last node point to the new node. Now the new node is the last node in the list
        current_node->set_next(new_node);
        new_node->set_prev(current_node);
        this->tail = new_node; // Setting the tail point to the new node
    }
    this->size++; // Updating the size
}

template <typename ltype>
void Doubly::LinkedList<ltype>::Insert_at_position(ltype data, const unsigned int position)
{
    // Initializing a new node and a current node
    Doubly::Node<ltype> *new_node = new Doubly::Node<ltype>, *current_node = this->head;

    // Checking if memory allocation worked successfully
    new_node->set(data, NULL, NULL);

    // Checking if the position is not valid
    if (position > this->size)
    {
        cout << "List has " << this->size << " elements but you entered " << position << " as a value position!" << endl;
        exit(1);
    }

    // If the position is equal to the size of the list plus 1 then Insert at the end
    else if (position == this->size + 1)
        this->Insert_at_end(data); // Inserting at the end

    // Accessing the given position of the list
    for (unsigned int i = 0; i < position - 1; i++)
        current_node = current_node->get_next();

    new_node->set_next(current_node->get_next()); // Setting the new node point to the next node
    current_node->get_next()->set_prev(new_node); // Setting the next node of the current node point back to the new node
    current_node->set_next(new_node);             // Setting the previous node point to the new node
    new_node->set_prev(current_node);             // Setting the new node point back to the current node
    this->size++;                                 // Updating the size
}

template <typename ltype>
void Doubly::LinkedList<ltype>::Insert(ltype data, const unsigned int index)
{
    switch (index)
    {
    case START:
        this->Insert_at_start(data);
        break; // Inserting at the start
    case END:
        this->Insert_at_end(data);
        break; // Insert at the end
    default:
        this->Insert_at_position(data, index);
        break; // Insert at the given position
    }
}

template <typename ltype>
void Doubly::LinkedList<ltype>::Delete_start()
{
    // Initializing a current node
    Doubly::Node<ltype> *current_node = this->head; // The current node is the first node of the list

    // Checking if the list is empty
    if (this->head == NULL)
        cout << "You tried to delete a node while the list is empty." << endl;

    // Deleting the first node
    this->head = this->head->get_next(); // Setting the head point to the second node
    delete current_node;                 // Delete the first node
    this->head->set_prev(NULL);          // Set the head point back to NULL
    this->size--;                        // Updating the size
}

template <typename ltype>
void Doubly::LinkedList<ltype>::Delete_end()
{
    // initializing a current node and a previous node
    Doubly::Node<ltype> *current_node, *previous_node;

    // Checking if the list is empty
    if (this->head == NULL)
        cout << "You tried to delete a node while the list is empty." << endl;

    // Checking if the list has only one node
    if (this->head->get_next() == NULL)
    {
        // Delete the list
        current_node = this->head; // Setting the current node be the first node
        delete current_node;       // Delete the current node
        this->head = NULL;         // Setting the head point to NULL
        this->tail = NULL;         // Setting the tail point to NULL

        this->size--; // Updating the size
        return;
    }

    current_node = this->head;  // Setting the current node be the first node
    previous_node = this->head; // Setting the previous node be the first node too

    // Accessing the last node
    while (current_node->get_next() != NULL)
    {
        previous_node = current_node;            // Setting the previous node be the current node
        current_node = current_node->get_next(); // Setting the current node be the next node
    }

    // Deleting the last node of the list
    previous_node->set_next(NULL); // Setting the previous node point to NULL
    delete current_node;           // Deleting the current node
    this->tail = previous_node;    // Setting the tail point to the previous node

    this->size--; // Updating the size
}

template <typename ltype>
void Doubly::LinkedList<ltype>::Delete_position(int position)
{
    // initializing a current node and a previous node
    Doubly::Node<ltype> *current_node = this->head, *previous_node;

    // Checking if the list is empty
    if (this->head == NULL)
        cout << "You tried to delete a node while the list is empty." << endl;

    // Checking if the position is not valid
    if (position < 0 || position > this->size - 1)
    {
        cout << "List has " << this->size << " elements but you entered " << position << " as a position to be deleted." << endl;
        exit(1);
    }

    // Accessing the node at the given position
    if (position == 0)
        this->Delete_start(); // Delete the start
    else if (position == this->size)
        this->Delete_end(); // Delete the end
    else
    {
        for (unsigned int i = 0; i < position; i++)
        {
            previous_node = current_node;            // Setting the previous node be the current node
            current_node = current_node->get_next(); // Setting the current node be the next node
        }
        // Deleting the node at the given position
        previous_node->set_next(current_node->get_next()); // Setting the previous node point to the next node of the current node
        current_node->get_next()->set_prev(previous_node); // Setting the next node of the current node point back to the previous node
        delete current_node;                               // Delete the current node

        this->size--; // Updating the size
    }
}

template <typename ltype>
void Doubly::LinkedList<ltype>::Delete_all()
{
    // Initializing a current node and a previous node
    Doubly::Node<ltype> *current_node, *previous_node;

    // Checking if the list is empty
    if (this->head == NULL)
        cout << "List is already empty." << endl;

    // Deleting every node
    current_node = this->head;  // Setting the current node be the first node
    previous_node = this->head; // Setting the previous node be the first node
    while (current_node != NULL)
    {
        previous_node = current_node;            // Setting the previous node be the current node
        current_node = current_node->get_next(); // Setting the current node be the next node
        delete previous_node;                    // Delete the previous node
    }
    this->size = 0;    // Updating the size
    this->head = NULL; // Setting the head point to NULL
    this->tail = NULL; // Setting the tail point to NULL
}

template <typename ltype>
void Doubly::LinkedList<ltype>::Delete_part(int start, int end)
{
    // Initializing a current node, a previous node, a start_node and an end node
    Doubly::Node<ltype> *current_node = this->head, *previous_node;
    Doubly::Node<ltype> *start_node, *end_node;

    if (end == END)
        end = this->size - 1;

    // Checking if the start and end positions are not valid
    if (start > end || start < 0 || start > this->size - 1 || end < 0 || end > this->size - 1)
    {
        cout << "The given positions are not valid. List has " << this->size << " elements." << endl;
        exit(1);
    }

    // Checking if the list is empty
    if (this->head == NULL)
        cout << "You tried to delete a part of the list while the list is empty." << endl;

    // Accesing the node at the given start position
    for (unsigned int i = 0; i < start; i++)
    {
        if (i == start - 1)
            start_node = current_node;           // Setting the start node be the current node
        current_node = current_node->get_next(); // Setting the current node be the next node
    }

    // Deleting every node until the given end position
    for (unsigned int i = start; i < end; i++)
    {
        if (i == end - 1)
            end_node = current_node->get_next(); // Setting the end node be the next node of the current node
        previous_node = current_node;            // Setting the previous node be the current node
        current_node = current_node->get_next(); // Setting the current node be the next node
        delete previous_node;                    // Deleting the previous node
    }
    if (start > 0)
    {
        start_node->set_next(end_node); // Setting the start node point to the next node
        if (end < this->size - 1)
            end_node->set_prev(start_node); // Setting the end node point back to the start node
        else
            this->tail = start_node; // Setting the tail point to the start node
    }
    else
    {
        this->head = end_node; // Setting the head point to the end node
        if (end < this->size - 1)
            end_node->set_prev(NULL); // Setting the end node point back to NULL
        else
            tail->set_prev(NULL);
    }

    this->size = end - start; // Updating the size
}

template <typename ltype>
Doubly::Node<ltype> *Doubly::LinkedList<ltype>::Get_first_node() const
{
    // Return the first node
    return this->head;
}

template <typename ltype>
Doubly::Node<ltype> *Doubly::LinkedList<ltype>::Get_last_node() const
{
    // Return the last node
    return this->tail;
}

template <typename ltype>
Doubly::Node<ltype> *Doubly::LinkedList<ltype>::Get_node_at(const unsigned int index) const
{
    // Initializing a current node
    Doubly::Node<ltype> *current_node = this->head;

    // Checking if the index is not valid
    if (index < 0 || index > this->size)
    {
        cout << "List has " << this->size << " elements but you entered " << index << " as an access position." << endl;
        exit(1);
    }

    // Accessing node at the given position
    for (unsigned int i = 0; i < index; i++)
        current_node = current_node->get_next(); // Setting the current node be the next node

    // Return the current node
    return current_node;
}

template <typename ltype>
Doubly::Node<ltype> *Doubly::LinkedList<ltype>::Get_node_by_data(const ltype data) const
{
    // Initializing a current node
    Doubly::Node<ltype> *current_node = this->head;

    // Searching for the given data
    while (current_node != NULL)
    {
        if (current_node->get_data() == data)
            return current_node;
        current_node = current_node->get_next();
    }
    return NULL;
}

template <typename ltype>
ltype Doubly::LinkedList<ltype>::Extract_start()
{
    // Initializing a data variable that keeps the data of the first node
    ltype data = this->head->get_data();

    // Deleting the first node
    this->Delete_start();

    // Return the data
    return data;
}

template <typename ltype>
ltype Doubly::LinkedList<ltype>::Extract_end()
{
    // Initializing a data variable that keeps the data of the last node
    ltype data = this->Get_last_node()->get_data();

    // Deleting the last node
    this->Delete_end();

    // Return the data
    return data;
}

template <typename ltype>
ltype Doubly::LinkedList<ltype>::Extract_position(const unsigned int index)
{
    // Checking if the given index is not valid
    if (index < 0 || index > this->size)
    {
        cout << "List has " << this->size << " elements but you entered " << index << " as an access position." << endl;
        exit(1);
    }

    // Initializing a data variable that keeps the data of the node at the given position
    ltype data = this->Get_node_at(index)->get_data();

    // Deleting the given node
    this->Delete_position(index);

    // Return the data
    return data;
}

template <typename ltype>
Doubly::LinkedList<ltype> Doubly::LinkedList<ltype>::Extract_from(int start, int end)
{
    // Initializing a new linked list as the result of the function
    Doubly::LinkedList<ltype> result_list;

    // Initializing a variable that keeps the the data of the nodes
    ltype data;

    // Accessing all the nodes from the given start position up to the given end position
    for (unsigned int i = start; i <= end; i++)
    {
        data = this->Get_node_at(i)->get_data();
        result_list.Insert_at_end(data); // Creating the result list
    }

    // Deleting the given part of the main list
    this->Delete_part(start, end + 1);

    return result_list;
}

template <typename ltype>
void Doubly::LinkedList<ltype>::Replace_start(const ltype data)
{
    // Changing the data of the first node
    this->head->set_data(data);
}

template <typename ltype>
void Doubly::LinkedList<ltype>::Replace_end(const ltype data)
{
    // Initializing a last node as the last node of the list
    Doubly::Node<ltype> *last_node = this->Get_last_node();

    // Changing the data of the last node
    last_node->set_data(data);
}

template <typename ltype>
void Doubly::LinkedList<ltype>::Replace_position(const ltype data, const unsigned int index)
{
    // Initializing a current node as the node at the given position
    Doubly::Node<ltype> *current_node = this->Get_node_at(index);

    // Changing the data of the current node
    current_node->set_data(data);
}

template <typename ltype>
void Doubly::LinkedList<ltype>::Sort()
{
    // Initializing a left node and a right node
    Doubly::Node<ltype> *left_node, *right_node;
    ltype temp;

    // Bubble Sort Algorithm for Linke List
    for (unsigned int i = 0; i < this->size; i++)
        for (int j = 0; j < this->size - i - 1; j++)
        {
            left_node = this->Get_node_at(j);
            right_node = this->Get_node_at(j + 1);
            if (left_node->get_data() > right_node->get_data())
            {
                temp = left_node->get_data();
                left_node->set_data(right_node->get_data());
                right_node->set_data(temp);
            }
        }
}

template <typename ltype>
Doubly::LinkedList<ltype> Doubly::LinkedList<ltype>::Sorted()
{
    // Initializing a linked list
    Doubly::LinkedList<ltype> result_list = this->Copy();

    // Sort the list
    result_list.Sort();

    return result_list;
}

template <typename ltype>
Doubly::LinkedList<ltype> Doubly::LinkedList<ltype>::Copy() const
{
    // Initializing a new linked list
    Doubly::LinkedList<ltype> new_linked_list;

    // Initializing a current node
    Doubly::Node<ltype> *current_node = this->head;

    // Copying every node of the list to the new list
    while (current_node != NULL)
    {
        new_linked_list.Insert(current_node->get_data());
        current_node = current_node->get_next();
    }

    return new_linked_list;
}

template <typename ltype>
ltype Doubly::LinkedList<ltype>::Min()
{
    // Initializing a data variable that keeps the minimum element
    ltype min_data;

    // Initializing a current node
    Doubly::Node<ltype> *current_node = this->head;
    min_data = current_node->get_data();

    // Searching for the minimum element
    while (current_node->get_next() != NULL)
    {
        current_node = current_node->get_next(); // Setting the current node be the next node
        if (current_node->get_data() < min_data)
            min_data = current_node->get_data();
    }
    return min_data;
}

template <typename ltype>
ltype Doubly::LinkedList<ltype>::Max()
{
    // Initializing a data variable that keeps the maximum element
    ltype max_data;

    // Initializing a current node
    Doubly::Node<ltype> *current_node = this->head;
    max_data = current_node->get_data();

    // Searching for the maximum element
    while (current_node->get_next() != NULL)
    {
        current_node = current_node->get_next(); // Setting the current node be the next node
        if (current_node->get_data() > max_data)
            max_data = current_node->get_data();
    }
    return max_data;
}

template <typename ltype>
int Doubly::LinkedList<ltype>::Length() const
{
    return this->size;
}

template <typename ltype>
bool Doubly::LinkedList<ltype>::Is_empty()
{
    return this->size == 0;
}

template <typename ltype>
int Doubly::LinkedList<ltype>::Count(const ltype data)
{
    // Initializing a variable that keeps how many times the given data exists in the list
    int times = 0;

    // Initializing a current node
    Doubly::Node<ltype> *current_node = this->head;

    // Searching for the given data
    while (current_node != NULL)
    {
        if (current_node->get_data() == data)
            times++;
        current_node = current_node->get_next(); // Setting the current node be the next node
    }
    return times;
}

template <typename ltype>
int Doubly::LinkedList<ltype>::Index_of(const ltype data)
{
    // Initializing a current node
    Doubly::Node<ltype> *current_node = this->head;

    // Searching for the given data
    for (unsigned int i = 0; i < this->size; i++)
    {
        if (current_node->get_data() == data)
            return i;
        current_node = current_node->get_next(); // Setting the current node be the
    }
    return -1;
}

template <typename ltype>
void Doubly::LinkedList<ltype>::Clear()
{
    // Initializing a current node and a previous node
    Doubly::Node<ltype> *current_node, *previous_node;

    // Deleting every node
    current_node = this->head;  // Setting the current node be the first node
    previous_node = this->head; // Setting the previous node be the first node
    while (current_node != NULL)
    {
        previous_node = current_node;            // Setting the previous node be the current node
        current_node = current_node->get_next(); // Setting the current node be the next node
        delete previous_node;                    // Delete the previous node
    }
    this->size = 0;    // Updating the size
    this->head = NULL; // Setting the head point to NULL
    this->tail = NULL; // Setting the tail point to NULL
}

template <typename ltype>
void Doubly::LinkedList<ltype>::Extend_start(const Doubly::LinkedList<ltype> &other_list)
{
    // Initializing a variable that keeps the data of the nodes
    ltype data;

    // Checking if the list is the same
    if (other_list.Get_first_node() == this->Get_first_node())
    {
        // Create a new list
        Doubly::LinkedList<ltype> new_list = other_list.Copy();

        // Creating copies of all the nodes of the other list starting from the end
        for (unsigned int i = other_list.Length() - 1; i >= 0; i--)
        {
            // Getting all the data from the other list starting from the end
            data = new_list.Get_node_at(i)->get_data();

            // Adding the new node at the beginning of the main list
            this->Insert_at_start(data);
        }
    }
    else
    {
        // Creating copies of all the nodes of the other list starting from the end
        for (unsigned int i = other_list.Length() - 1; i >= 0; i--)
        {
            // Getting all the data from the other list starting from the end
            data = other_list.Get_node_at(i)->get_data();

            // Adding the new node at the beginning of the main list
            this->Insert_at_start(data);
        }
    }
}

template <typename ltype>
void Doubly::LinkedList<ltype>::Extend_end(const Doubly::LinkedList<ltype> &other_list)
{
    // Initializing a variable that keeps the data of the nodes
    ltype data;

    // Checking if the list is the same
    if (other_list.Get_first_node() == this->Get_first_node())
    {
        // Create a new list
        Doubly::LinkedList<ltype> new_list = other_list.Copy();

        // Creating copies of all the nodes of the other list starting from the end
        for (unsigned int i = 0; i < new_list.Length(); i++)
        {
            // Getting all the data from the other list starting from the end
            data = new_list.Get_node_at(i)->get_data();

            // Adding the new node at the beginning of the main list
            this->Insert_at_end(data);
        }
    }
    else
    {
        // Creating copies of all the nodes of the other list starting from the end
        for (unsigned int i = 0; i < other_list.Length(); i++)
        {
            // Getting all the data from the other list starting from the end
            data = other_list.Get_node_at(i)->get_data();

            // Adding the new node at the beginning of the main list
            this->Insert_at_end(data);
        }
    }
}

template <typename ltype>
void Doubly::LinkedList<ltype>::Extend_at(const Doubly::LinkedList<ltype> &other_list, const unsigned int position)
{
    // Initializing a variable that keeps the data of the nodes
    ltype data;

    // Checking if the list is the same
    if (other_list.Get_first_node() == this->Get_first_node())
    {
        // Create a new list
        Doubly::LinkedList<ltype> new_list = other_list.Copy();

        // Creating copies of all the nodes of the other list starting from the end
        for (unsigned int i = other_list.Length() - 1; i >= 0; i--)
        {
            // Getting all the data from the other list starting from the end
            data = new_list.Get_node_at(i)->get_data();

            // Adding the new node at the beginning of the main list
            this->Insert_at_position(data, position);
        }
    }
    else
    {
        // Creating copies of all the nodes of the other list starting from the end
        for (unsigned int i = other_list.Length() - 1; i >= 0; i--)
        {
            // Getting all the data from the other list starting from the end
            data = other_list.Get_node_at(i)->get_data();

            // Adding the new node at the beginning of the main list
            this->Insert_at_position(data, position);
        }
    }
}

template <typename ltype>
void Doubly::LinkedList<ltype>::operator=(Doubly::LinkedList<ltype> &other_list)
{
    // Initializing a current node as the fist node of the other list
    Doubly::Node<ltype> *current_node = other_list.Get_first_node();

    // Delete the main list
    this->Clear();

    // Copying every node to the main list
    while (current_node != NULL)
    {
        this->Insert(current_node->get_data());
        current_node = current_node->get_next(); // Setting the current node be the next node
    }
}

template <typename ltype>
ltype &Doubly::LinkedList<ltype>::operator[](int index)
{
    // Checking if the index is not valid
    if (index < 0 || index >= this->size)
    {
        cout << "List index out of bound." << endl;
        exit(1);
    }
    return this->Get_node_at(index)->get_data();
}

template <typename ltype>
bool Doubly::LinkedList<ltype>::Contains(const ltype data)
{
    // Initializing a current node
    Doubly::Node<ltype> *current_node = this->head;

    // Searching for the given data
    while (current_node != NULL)
    {
        if (current_node->get_data() == data)
            return true;
        current_node = current_node->get_next();
    }
    return false;
}