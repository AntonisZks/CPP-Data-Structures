#include <iostream>
#include "LinkedList.hpp"
using namespace std;

/* SINGLY LINKED LIST NODE METHODS */
template <typename type>
void Singly::Node<type>::set_data(type &data)
{
    // Setting the data
    this->data = data;
}

template <typename type>
void Singly::Node<type>::set_next(Singly::Node<type> *const next_node)
{
    // Setting the next node
    this->next = next_node;
}

template <typename type>
void Singly::Node<type>::set(type &data, Singly::Node<type> *const next_node)
{
    // Creating the node
    this->set_data(data);
    this->set_next(next_node);
}

template <typename type>
type &Singly::Node<type>::get_data()
{
    // Returning the current data of the node
    return this->data;
}

template <typename type>
Singly::Node<type> *Singly::Node<type>::get_next()
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
template <typename type>
void Doubly::Node<type>::set_data(type &data)
{
    // Setting the data
    this->data = data;
}

template <typename type>
void Doubly::Node<type>::set_next(Doubly::Node<type> *const next_node)
{
    // Setting the next node
    this->next = next_node;
}

template <typename type>
void Doubly::Node<type>::set_prev(Doubly::Node<type> *const prev_node)
{
    // Setting the previous node
    this->prev = prev_node;
}

template <typename type>
void Doubly::Node<type>::set(type &data, Doubly::Node<type> *const prev_node, Doubly::Node<type> *const next_node)
{
    // Creating the node
    this->set_data(data);
    this->set_next(next_node);
    this->set_prev(prev_node);
}

template <typename type>
type &Doubly::Node<type>::get_data()
{
    // Returning the current data of the node
    return this->data;
}

template <typename type>
Doubly::Node<type> *Doubly::Node<type>::get_next()
{
    // Returning the current next node or NULL if there is no next node
    if (this->next == NULL)
        return NULL;
    return this->next;
}

template <typename type>
Doubly::Node<type> *Doubly::Node<type>::get_prev()
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
template <typename type>
Singly::LinkedList<type>::LinkedList()
{
    // Initializing the linked list
    this->head = NULL;
    this->size = 0;
    // cout << "Singly Linked List Constructed with " << this->size << " elements." << endl;
}

template <typename type>
Singly::LinkedList<type>::LinkedList(const Singly::LinkedList<type> &other)
{
    // Initializing a current node as the first node of the other list
    Singly::Node<type> *current_node = other.Get_first_node();

    this->head = NULL; // Setting the head point to NULL
    while (current_node != NULL)
    {
        this->Insert(current_node->get_data());  // Copying the elements
        current_node = current_node->get_next(); // Setting the current node be the next node
    }
}

template <typename type>
Singly::LinkedList<type>::~LinkedList()
{
    // Initializing a current node
    Singly::Node<type> *current_node;

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

template <typename type>
void Singly::LinkedList<type>::Insert_at_start(type data)
{

    // Initializing a new node
    Singly::Node<type> *new_node = new Singly::Node<type>;

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

template <typename type>
void Singly::LinkedList<type>::Insert_at_end(type data)
{
    // Initializing a new node and a current node
    Singly::Node<type> *new_node = new Singly::Node<type>, *current_node = this->head;

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

template <typename type>
void Singly::LinkedList<type>::Insert_at_position(type data, const int position)
{
    // Initializing a new node and a current node
    Singly::Node<type> *new_node = new Singly::Node<type>, *current_node = this->head;

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
    for (int i = 0; i < position - 1; i++)
        current_node = current_node->get_next();

    new_node->set_next(current_node->get_next()); // Setting the new node point to the next node
    current_node->set_next(new_node);             // Setting the previous node point to the new node
    this->size++;                                 // Updating the size
}

template <typename type>
void Singly::LinkedList<type>::Insert(type data, const int index)
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

template <typename type>
void Singly::LinkedList<type>::Delete_start()
{
    // Initializing a current node
    Singly::Node<type> *current_node = this->head; // The current node is the first node of the list

    // Checking if the list is empty
    if (this->head == NULL)
        cout << "You tried to delete a node while the list is empty." << endl;

    // Deleting the first node
    this->head = this->head->get_next(); // Setting the head point to the second node
    delete current_node;                 // Delete the first node
    this->size--;                        // Updating the size
}

template <typename type>
void Singly::LinkedList<type>::Delete_end()
{
    // initializing a current node and a previous node
    Singly::Node<type> *current_node, *previous_node;

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

template <typename type>
void Singly::LinkedList<type>::Delete_position(const int position)
{
    // initializing a current node and a previous node
    Singly::Node<type> *current_node = this->head, *previous_node;

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
        for (int i = 0; i < position; i++)
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

template <typename type>
void Singly::LinkedList<type>::Delete_all()
{
    // Initializing a current node and a previous node
    Singly::Node<type> *current_node, *previous_node;

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

template <typename type>
void Singly::LinkedList<type>::Delete_part(int start, int end)
{
    // Initializing a current node, a previous node, a start_node and an end node
    Singly::Node<type> *current_node = this->head, *previous_node;
    Singly::Node<type> *start_node, *end_node;

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
    for (int i = 0; i < start; i++)
    {
        if (i == start - 1)
            start_node = current_node;           // Setting the start node be the current node
        current_node = current_node->get_next(); // Setting the current node be the next node
    }

    // Deleting every node until the given end position
    for (int i = start; i < end; i++)
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

template <typename type>
Singly::Node<type> *Singly::LinkedList<type>::Get_first_node() const
{
    // Return the first node
    return this->head;
}

template <typename type>
Singly::Node<type> *Singly::LinkedList<type>::Get_last_node() const
{
    // initializing a current node
    Singly::Node<type> *current_node = this->head;

    // Accessing the last node
    while (current_node->get_next() != NULL)
        current_node = current_node->get_next(); // Setting the current node be the next node

    // Return the last node
    return current_node;
}

template <typename type>
Singly::Node<type> *Singly::LinkedList<type>::Get_node_at(const int index) const
{
    // Initializing a current node
    Singly::Node<type> *current_node = this->head;

    // Checking if the index is not valid
    if (index < 0 || index > this->size)
    {
        cout << "List has " << this->size << " elements but you entered " << index << " as an access position." << endl;
        exit(1);
    }

    // Accessing node at the given position
    for (int i = 0; i < index; i++)
        current_node = current_node->get_next(); // Setting the current node be the next node

    // Return the current node
    return current_node;
}

template <typename type>
Singly::Node<type> *Singly::LinkedList<type>::Get_node_by_data(const type data) const
{
    // Initializing a current node
    Singly::Node<type> *current_node = this->head;

    // Searching for the given data
    while (current_node != NULL)
    {
        if (current_node->get_data() == data)
            return current_node;
        current_node = current_node->get_next();
    }
    return NULL;
}

template <typename type>
type Singly::LinkedList<type>::Extract_start()
{
    // Initializing a data variable that keeps the data of the first node
    type data = this->head->get_data();

    // Deleting the first node
    this->Delete_start();

    // Return the data
    return data;
}

template <typename type>
type Singly::LinkedList<type>::Extract_end()
{
    // Initializing a data variable that keeps the data of the last node
    type data = this->Get_last_node()->get_data();

    // Deleting the last node
    this->Delete_end();

    // Return the data
    return data;
}

template <typename type>
type Singly::LinkedList<type>::Extract_position(const int index)
{
    // Checking if the given index is not valid
    if (index < 0 || index > this->size)
    {
        cout << "List has " << this->size << " elements but you entered " << index << " as an access position." << endl;
        exit(1);
    }

    // Initializing a data variable that keeps the data of the node at the given position
    type data = this->Get_node_at(index)->get_data();

    // Deleting the given node
    this->Delete_position(index);

    // Return the data
    return data;
}

template <typename type>
Singly::LinkedList<type> Singly::LinkedList<type>::Extract_from(int start, int end)
{
    // Initializing a new linked list as the result of the function
    Singly::LinkedList<type> result_list;

    // Initializing a variable that keeps the the data of the nodes
    type data;

    // Accessing all the nodes from the given start position up to the given end position
    for (int i = start; i <= end; i++)
    {
        data = this->Get_node_at(i)->get_data();
        result_list.Insert_at_end(data); // Creating the result list
    }

    // Deleting the given part of the main list
    this->Delete_part(start, end + 1);

    return result_list;
}

template <typename type>
void Singly::LinkedList<type>::Replace_start(const type data)
{
    // Changing the data of the first node
    this->head->set_data(data);
}

template <typename type>
void Singly::LinkedList<type>::Replace_end(const type data)
{
    // Initializing a last node as the last node of the list
    Singly::Node<type> *last_node = this->Get_last_node();

    // Changing the data of the last node
    last_node->set_data(data);
}

template <typename type>
void Singly::LinkedList<type>::Replace_position(const type data, const int index)
{
    // Initializing a current node as the node at the given position
    Singly::Node<type> *current_node = this->Get_node_at(index);

    // Changing the data of the current node
    current_node->set_data(data);
}

template <typename type>
void Singly::LinkedList<type>::Sort()
{
    // Initializing a left node and a right node
    Singly::Node<type> *left_node, *right_node;
    type temp;

    // Bubble Sort Algorithm for Linke List
    for (int i = 0; i < this->size; i++)
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

template <typename type>
Singly::LinkedList<type> Singly::LinkedList<type>::Sorted()
{
    // Initializing a linked list
    Singly::LinkedList<type> result_list = this->Copy();

    // Sort the list
    result_list.Sort();

    return result_list;
}

template <typename type>
Singly::LinkedList<type> Singly::LinkedList<type>::Copy() const
{
    // Initializing a new linked list
    Singly::LinkedList<type> new_linked_list;

    // Initializing a current node
    Singly::Node<type> *current_node = this->head;

    // Copying every node of the list to the new list
    while (current_node != NULL)
    {
        new_linked_list.Insert(current_node->get_data());
        current_node = current_node->get_next();
    }

    return new_linked_list;
}

template <typename type>
type Singly::LinkedList<type>::Min()
{
    // Initializing a data variable that keeps the minimum element
    type min_data;

    // Initializing a current node
    Singly::Node<type> *current_node = this->head;
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

template <typename type>
type Singly::LinkedList<type>::Max()
{
    // Initializing a data variable that keeps the maximum element
    type max_data;

    // Initializing a current node
    Singly::Node<type> *current_node = this->head;
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

template <typename type>
int Singly::LinkedList<type>::Length() const
{
    return this->size;
}

template <typename type>
bool Singly::LinkedList<type>::Is_empty()
{
    return this->size == 0;
}

template <typename type>
int Singly::LinkedList<type>::Count(const type data)
{
    // Initializing a variable that keeps how many times the given data exists in the list
    int times = 0;

    // Initializing a current node
    Singly::Node<type> *current_node = this->head;

    // Searching for the given data
    while (current_node != NULL)
    {
        if (current_node->get_data() == data)
            times++;
        current_node = current_node->get_next(); // Setting the current node be the next node
    }
    return times;
}

template <typename type>
int Singly::LinkedList<type>::Index_of(const type data)
{
    // Initializing a current node
    Singly::Node<type> *current_node = this->head;

    // Searching for the given data
    for (int i = 0; i < this->size; i++)
    {
        if (current_node->get_data() == data)
            return i;
        current_node = current_node->get_next(); // Setting the current node be the
    }
    return -1;
}

template <typename type>
void Singly::LinkedList<type>::Clear()
{
    // Initializing a current node and a previous node
    Singly::Node<type> *current_node, *previous_node;

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

template <typename type>
void Singly::LinkedList<type>::Extend_start(const Singly::LinkedList<type> &other_list)
{
    // Initializing a variable that keeps the data of the nodes
    type data;

    // Checking if the list is the same
    if (other_list.Get_first_node() == this->Get_first_node())
    {
        // Create a new list
        Singly::LinkedList<type> new_list = other_list.Copy();

        // Creating copies of all the nodes of the other list starting from the end
        for (int i = other_list.Length() - 1; i >= 0; i--)
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
        for (int i = other_list.Length() - 1; i >= 0; i--)
        {
            // Getting all the data from the other list starting from the end
            data = other_list.Get_node_at(i)->get_data();

            // Adding the new node at the beginning of the main list
            this->Insert_at_start(data);
        }
    }
}

template <typename type>
void Singly::LinkedList<type>::Extend_end(const Singly::LinkedList<type> &other_list)
{
    // Initializing a variable that keeps the data of the nodes
    type data;

    // Checking if the list is the same
    if (other_list.Get_first_node() == this->Get_first_node())
    {
        // Create a new list
        Singly::LinkedList<type> new_list = other_list.Copy();

        // Creating copies of all the nodes of the other list starting from the end
        for (int i = 0; i < new_list.Length(); i++)
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
        for (int i = 0; i < other_list.Length(); i++)
        {
            // Getting all the data from the other list starting from the end
            data = other_list.Get_node_at(i)->get_data();

            // Adding the new node at the beginning of the main list
            this->Insert_at_end(data);
        }
    }
}

template <typename type>
void Singly::LinkedList<type>::Extend_at(const Singly::LinkedList<type> &other_list, int position)
{
    // Initializing a variable that keeps the data of the nodes
    type data;

    // Checking if the list is the same
    if (other_list.Get_first_node() == this->Get_first_node())
    {
        // Create a new list
        Singly::LinkedList<type> new_list = other_list.Copy();

        // Creating copies of all the nodes of the other list starting from the end
        for (int i = other_list.Length() - 1; i >= 0; i--)
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
        for (int i = other_list.Length() - 1; i >= 0; i--)
        {
            // Getting all the data from the other list starting from the end
            data = other_list.Get_node_at(i)->get_data();

            // Adding the new node at the beginning of the main list
            this->Insert_at_position(data, position);
        }
    }
}

template <typename type>
void Singly::LinkedList<type>::operator=(Singly::LinkedList<type> &other_list)
{
    // Initializing a current node as the fist node of the other list
    Singly::Node<type> *current_node = other_list.Get_first_node();

    // Delete the main list
    this->Clear();

    // Copying every node to the main list
    while (current_node != NULL)
    {
        this->Insert(current_node->get_data());
        current_node = current_node->get_next(); // Setting the current node be the next node
    }
}

template <typename type>
type &Singly::LinkedList<type>::operator[](int index)
{
    // Checking if the index is not valid
    if (index < 0 || index >= this->size)
    {
        cout << "List index out of bound." << endl;
        exit(1);
    }
    return this->Get_node_at(index)->get_data();
}

template <typename type>
bool Singly::LinkedList<type>::Contains(const type data)
{
    // Initializing a current node
    Singly::Node<type> *current_node = this->head;

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
template <typename type>
Doubly::LinkedList<type>::LinkedList()
{
    // Initializing the linked list
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
}

template <typename type>
Doubly::LinkedList<type>::LinkedList(const Doubly::LinkedList<type> &other)
{
    // Initializing a current node as the first node of the other list
    Doubly::Node<type> *current_node = other.Get_first_node();

    this->head = NULL; // Setting the head point to NULL
    while (current_node != NULL)
    {
        this->Insert(current_node->get_data());  // Copying the elements
        current_node = current_node->get_next(); // Setting the current node be the next node
    }
}

template <typename type>
Doubly::LinkedList<type>::~LinkedList()
{
    // Initializing a current node
    Doubly::Node<type> *current_node;

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

template <typename type>
void Doubly::LinkedList<type>::Insert_at_start(type data)
{

    // Initializing a new node
    Doubly::Node<type> *new_node = new Doubly::Node<type>;

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

template <typename type>
void Doubly::LinkedList<type>::Insert_at_end(type data)
{
    // Initializing a new node and a current node
    Doubly::Node<type> *new_node = new Doubly::Node<type>, *current_node = this->head;

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

template <typename type>
void Doubly::LinkedList<type>::Insert_at_position(type data, const int position)
{
    // Initializing a new node and a current node
    Doubly::Node<type> *new_node = new Doubly::Node<type>, *current_node = this->head;

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
    for (int i = 0; i < position - 1; i++)
        current_node = current_node->get_next();

    new_node->set_next(current_node->get_next()); // Setting the new node point to the next node
    current_node->get_next()->set_prev(new_node); // Setting the next node of the current node point back to the new node
    current_node->set_next(new_node);             // Setting the previous node point to the new node
    new_node->set_prev(current_node);             // Setting the new node point back to the current node
    this->size++;                                 // Updating the size
}

template <typename type>
void Doubly::LinkedList<type>::Insert(type data, const int index)
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

template <typename type>
void Doubly::LinkedList<type>::Delete_start()
{
    // Initializing a current node
    Doubly::Node<type> *current_node = this->head; // The current node is the first node of the list

    // Checking if the list is empty
    if (this->head == NULL)
        cout << "You tried to delete a node while the list is empty." << endl;

    // Deleting the first node
    this->head = this->head->get_next(); // Setting the head point to the second node
    delete current_node;                 // Delete the first node
    this->head->set_prev(NULL);          // Set the head point back to NULL
    this->size--;                        // Updating the size
}

template <typename type>
void Doubly::LinkedList<type>::Delete_end()
{
    // initializing a current node and a previous node
    Doubly::Node<type> *current_node, *previous_node;

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

template <typename type>
void Doubly::LinkedList<type>::Delete_position(int position)
{
    // initializing a current node and a previous node
    Doubly::Node<type> *current_node = this->head, *previous_node;

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
        for (int i = 0; i < position; i++)
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

template <typename type>
void Doubly::LinkedList<type>::Delete_all()
{
    // Initializing a current node and a previous node
    Doubly::Node<type> *current_node, *previous_node;

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

template <typename type>
void Doubly::LinkedList<type>::Delete_part(int start, int end)
{
    // Initializing a current node, a previous node, a start_node and an end node
    Doubly::Node<type> *current_node = this->head, *previous_node;
    Doubly::Node<type> *start_node, *end_node;

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
    for (int i = 0; i < start; i++)
    {
        if (i == start - 1)
            start_node = current_node;           // Setting the start node be the current node
        current_node = current_node->get_next(); // Setting the current node be the next node
    }

    // Deleting every node until the given end position
    for (int i = start; i < end; i++)
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

template <typename type>
Doubly::Node<type> *Doubly::LinkedList<type>::Get_first_node() const
{
    // Return the first node
    return this->head;
}

template <typename type>
Doubly::Node<type> *Doubly::LinkedList<type>::Get_last_node() const
{
    // Return the last node
    return this->tail;
}

template <typename type>
Doubly::Node<type> *Doubly::LinkedList<type>::Get_node_at(const int index) const
{
    // Initializing a current node
    Doubly::Node<type> *current_node = this->head;

    // Checking if the index is not valid
    if (index < 0 || index > this->size)
    {
        cout << "List has " << this->size << " elements but you entered " << index << " as an access position." << endl;
        exit(1);
    }

    // Accessing node at the given position
    for (int i = 0; i < index; i++)
        current_node = current_node->get_next(); // Setting the current node be the next node

    // Return the current node
    return current_node;
}

template <typename type>
Doubly::Node<type> *Doubly::LinkedList<type>::Get_node_by_data(const type data) const
{
    // Initializing a current node
    Doubly::Node<type> *current_node = this->head;

    // Searching for the given data
    while (current_node != NULL)
    {
        if (current_node->get_data() == data)
            return current_node;
        current_node = current_node->get_next();
    }
    return NULL;
}

template <typename type>
type Doubly::LinkedList<type>::Extract_start()
{
    // Initializing a data variable that keeps the data of the first node
    type data = this->head->get_data();

    // Deleting the first node
    this->Delete_start();

    // Return the data
    return data;
}

template <typename type>
type Doubly::LinkedList<type>::Extract_end()
{
    // Initializing a data variable that keeps the data of the last node
    type data = this->Get_last_node()->get_data();

    // Deleting the last node
    this->Delete_end();

    // Return the data
    return data;
}

template <typename type>
type Doubly::LinkedList<type>::Extract_position(const int index)
{
    // Checking if the given index is not valid
    if (index < 0 || index > this->size)
    {
        cout << "List has " << this->size << " elements but you entered " << index << " as an access position." << endl;
        exit(1);
    }

    // Initializing a data variable that keeps the data of the node at the given position
    type data = this->Get_node_at(index)->get_data();

    // Deleting the given node
    this->Delete_position(index);

    // Return the data
    return data;
}

template <typename type>
Doubly::LinkedList<type> Doubly::LinkedList<type>::Extract_from(int start, int end)
{
    // Initializing a new linked list as the result of the function
    Doubly::LinkedList<type> result_list;

    // Initializing a variable that keeps the the data of the nodes
    type data;

    // Accessing all the nodes from the given start position up to the given end position
    for (int i = start; i <= end; i++)
    {
        data = this->Get_node_at(i)->get_data();
        result_list.Insert_at_end(data); // Creating the result list
    }

    // Deleting the given part of the main list
    this->Delete_part(start, end + 1);

    return result_list;
}

template <typename type>
void Doubly::LinkedList<type>::Replace_start(const type data)
{
    // Changing the data of the first node
    this->head->set_data(data);
}

template <typename type>
void Doubly::LinkedList<type>::Replace_end(const type data)
{
    // Initializing a last node as the last node of the list
    Doubly::Node<type> *last_node = this->Get_last_node();

    // Changing the data of the last node
    last_node->set_data(data);
}

template <typename type>
void Doubly::LinkedList<type>::Replace_position(const type data, const int index)
{
    // Initializing a current node as the node at the given position
    Doubly::Node<type> *current_node = this->Get_node_at(index);

    // Changing the data of the current node
    current_node->set_data(data);
}

template <typename type>
void Doubly::LinkedList<type>::Sort()
{
    // Initializing a left node and a right node
    Doubly::Node<type> *left_node, *right_node;
    type temp;

    // Bubble Sort Algorithm for Linke List
    for (int i = 0; i < this->size; i++)
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

template <typename type>
Doubly::LinkedList<type> Doubly::LinkedList<type>::Sorted()
{
    // Initializing a linked list
    Doubly::LinkedList<type> result_list = this->Copy();

    // Sort the list
    result_list.Sort();

    return result_list;
}

template <typename type>
Doubly::LinkedList<type> Doubly::LinkedList<type>::Copy() const
{
    // Initializing a new linked list
    Doubly::LinkedList<type> new_linked_list;

    // Initializing a current node
    Doubly::Node<type> *current_node = this->head;

    // Copying every node of the list to the new list
    while (current_node != NULL)
    {
        new_linked_list.Insert(current_node->get_data());
        current_node = current_node->get_next();
    }

    return new_linked_list;
}

template <typename type>
type Doubly::LinkedList<type>::Min()
{
    // Initializing a data variable that keeps the minimum element
    type min_data;

    // Initializing a current node
    Doubly::Node<type> *current_node = this->head;
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

template <typename type>
type Doubly::LinkedList<type>::Max()
{
    // Initializing a data variable that keeps the maximum element
    type max_data;

    // Initializing a current node
    Doubly::Node<type> *current_node = this->head;
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

template <typename type>
int Doubly::LinkedList<type>::Length() const
{
    return this->size;
}

template <typename type>
bool Doubly::LinkedList<type>::Is_empty()
{
    return this->size == 0;
}

template <typename type>
int Doubly::LinkedList<type>::Count(const type data)
{
    // Initializing a variable that keeps how many times the given data exists in the list
    int times = 0;

    // Initializing a current node
    Doubly::Node<type> *current_node = this->head;

    // Searching for the given data
    while (current_node != NULL)
    {
        if (current_node->get_data() == data)
            times++;
        current_node = current_node->get_next(); // Setting the current node be the next node
    }
    return times;
}

template <typename type>
int Doubly::LinkedList<type>::Index_of(const type data)
{
    // Initializing a current node
    Doubly::Node<type> *current_node = this->head;

    // Searching for the given data
    for (int i = 0; i < this->size; i++)
    {
        if (current_node->get_data() == data)
            return i;
        current_node = current_node->get_next(); // Setting the current node be the
    }
    return -1;
}

template <typename type>
void Doubly::LinkedList<type>::Clear()
{
    // Initializing a current node and a previous node
    Doubly::Node<type> *current_node, *previous_node;

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

template <typename type>
void Doubly::LinkedList<type>::Extend_start(const Doubly::LinkedList<type> &other_list)
{
    // Initializing a variable that keeps the data of the nodes
    type data;

    // Checking if the list is the same
    if (other_list.Get_first_node() == this->Get_first_node())
    {
        // Create a new list
        Doubly::LinkedList<type> new_list = other_list.Copy();

        // Creating copies of all the nodes of the other list starting from the end
        for (int i = other_list.Length() - 1; i >= 0; i--)
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
        for (int i = other_list.Length() - 1; i >= 0; i--)
        {
            // Getting all the data from the other list starting from the end
            data = other_list.Get_node_at(i)->get_data();

            // Adding the new node at the beginning of the main list
            this->Insert_at_start(data);
        }
    }
}

template <typename type>
void Doubly::LinkedList<type>::Extend_end(const Doubly::LinkedList<type> &other_list)
{
    // Initializing a variable that keeps the data of the nodes
    type data;

    // Checking if the list is the same
    if (other_list.Get_first_node() == this->Get_first_node())
    {
        // Create a new list
        Doubly::LinkedList<type> new_list = other_list.Copy();

        // Creating copies of all the nodes of the other list starting from the end
        for (int i = 0; i < new_list.Length(); i++)
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
        for (int i = 0; i < other_list.Length(); i++)
        {
            // Getting all the data from the other list starting from the end
            data = other_list.Get_node_at(i)->get_data();

            // Adding the new node at the beginning of the main list
            this->Insert_at_end(data);
        }
    }
}

template <typename type>
void Doubly::LinkedList<type>::Extend_at(const Doubly::LinkedList<type> &other_list, const int position)
{
    // Initializing a variable that keeps the data of the nodes
    type data;

    // Checking if the list is the same
    if (other_list.Get_first_node() == this->Get_first_node())
    {
        // Create a new list
        Doubly::LinkedList<type> new_list = other_list.Copy();

        // Creating copies of all the nodes of the other list starting from the end
        for (int i = other_list.Length() - 1; i >= 0; i--)
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
        for (int i = other_list.Length() - 1; i >= 0; i--)
        {
            // Getting all the data from the other list starting from the end
            data = other_list.Get_node_at(i)->get_data();

            // Adding the new node at the beginning of the main list
            this->Insert_at_position(data, position);
        }
    }
}

template <typename type>
void Doubly::LinkedList<type>::operator=(Doubly::LinkedList<type> &other_list)
{
    // Initializing a current node as the fist node of the other list
    Doubly::Node<type> *current_node = other_list.Get_first_node();

    // Delete the main list
    this->Clear();

    // Copying every node to the main list
    while (current_node != NULL)
    {
        this->Insert(current_node->get_data());
        current_node = current_node->get_next(); // Setting the current node be the next node
    }
}

template <typename type>
type &Doubly::LinkedList<type>::operator[](int index)
{
    // Checking if the index is not valid
    if (index < 0 || index >= this->size)
    {
        cout << "List index out of bound." << endl;
        exit(1);
    }
    return this->Get_node_at(index)->get_data();
}

template <typename type>
bool Doubly::LinkedList<type>::Contains(const type data)
{
    // Initializing a current node
    Doubly::Node<type> *current_node = this->head;

    // Searching for the given data
    while (current_node != NULL)
    {
        if (current_node->get_data() == data)
            return true;
        current_node = current_node->get_next();
    }
    return false;
}