/* Filename: Graph.cpp */

/* This file includes all the basic function prototypes
   for a Graph Data Structure. Use of the Singly Linked List
   Data Structure. More details about Singly Linked List in file:
   "LinkedList.hpp" */

#include <iostream>
#include "Graph.hpp"
using namespace std;

template <typename type>
Unweighted::Vertex<type>::Vertex(type &data, Singly::LinkedList<type> &neighbors)
{
    // Initializing the vertex
    this->data = data;
    this->neighbors = neighbors;
}

template <typename item>
ostream &operator<<(ostream &out, const Unweighted::Vertex<item> &vertex)
{
    out << vertex.get_data();
    return out;
}

template <typename type>
Unweighted::Undirected::Graph<type>::Graph(int size)
{
    // Initializing the graph
    this->size = size;
    for (int i = 0; i < this->size; i++)
        this->vertices.Insert(Unweighted::Vertex<type>());
}

template <typename type>
Singly::LinkedList<Unweighted::Vertex<type>> Unweighted::Undirected::Graph<type>::Get_vertices() const
{
    return this->vertices;
}

template <typename type>
Unweighted::Vertex<type> &Unweighted::Undirected::Graph<type>::Get_vertex_by_data(type data)
{
    // Initializing a current list node
    Singly::Node<Unweighted::Vertex<type>> *current_node = this->vertices.Get_first_node();
    Unweighted::Vertex<type> new_vertex;

    // Searching for the node that contains the given data
    while (current_node != NULL)
    {
        if (current_node->get_data().get_data() == data)
            new_vertex = current_node->get_data();

        current_node = current_node->get_next();
    }
    return new_vertex;
}

template <typename type>
void Unweighted::Undirected::Graph<type>::Add_vertex(type data)
{
    // Initializing a new vertex
    Unweighted::Vertex<type> new_vertex;
    new_vertex.set_data(data);

    // Adding the new vertex to the graph
    this->vertices.Insert(new_vertex);
    this->size++; // Updating the size
}

template <typename type>
void Unweighted::Undirected::Graph<type>::Connect_vertices(type data1, type data2)
{
    if (this->Are_connected(data1, data2))
        return;

    int done = 0;
    Singly::Node<Unweighted::Vertex<type>> *current_node = this->vertices.Get_first_node();

    while (current_node != NULL || done < 2)
    {
        if (current_node->get_data().get_data() == data1)
        {
            current_node->get_data().get_neighbors().Insert(data2);
            done++;
        }
        if (current_node->get_data().get_data() == data2)
        {
            current_node->get_data().get_neighbors().Insert(data1);
            done++;
        }
        current_node = current_node->get_next();
    }
}

template <typename type>
bool Unweighted::Undirected::Graph<type>::Are_connected(type data1, type data2)
{
    Singly::Node<Unweighted::Vertex<type>> *current_node = this->vertices.Get_first_node();

    while (current_node != NULL)
    {
        if (current_node->get_data().get_data() == data1)
            return current_node->get_data().get_neighbors().Contains(data2);

        else if (current_node->get_data().get_data() == data2)
            return current_node->get_data().get_neighbors().Contains(data1);
        cout << current_node->get_data() << endl;

        current_node = current_node->get_next();
    }
    return false;
}

template <typename type>
void Unweighted::Undirected::Graph<type>::print() const
{
    Singly::Node<Unweighted::Vertex<type>> *current_node = this->vertices.Get_first_node();
    Singly::Node<type> *cur_node;

    while (current_node != NULL)
    {
        cout << current_node->get_data() << ": ";
        cout << current_node->get_data().get_neighbors();
        cout << endl;
        current_node = current_node->get_next();
    }
}

template <typename type>
ostream &operator<<(ostream &out, const Unweighted::Undirected::Graph<type> graph)
{
    Singly::Node<Unweighted::Vertex<type>> *current_node = graph.Get_vertices().Get_first_node();
    Singly::Node<type> *cur_node;

    while (current_node != NULL)
    {
        out << current_node->get_data() << ": ";
        out << current_node->get_data().get_neighbors();
        out << endl;
        current_node = current_node->get_next();
    }
    return out;
}