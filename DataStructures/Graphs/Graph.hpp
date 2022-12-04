/* Filename: Graph.hpp */

/* This file includes all the basic function prototypes
   for a Graph Data Structure. Use of the Singly Linked List
   Data Structure. More details about Singly Linked List in file:
   "LinkedList.hpp" */

#ifndef GRAPH_HEADER
#define GRAPH_HEADER

#include <iostream>
#include "../Lists/LinkedList.hpp"
using namespace std;

namespace Unweighted
{
    /* BASIC STRUCT FOR AN UNWEIGHTED GRAPH VERTEX */
    template <typename type>
    struct Vertex
    {
    public:
        // Constructors and Destructor
        Vertex(type &data, Singly::LinkedList<type> &neighbors);
        Vertex() {}
        ~Vertex() {}

        // Setters
        void set_data(type data) { this->data = data; }
        void set_neighbors(Singly::LinkedList<type> &neighbors) { this->neighbors = neighbors; }

        // Getters
        type get_data() const { return this->data; }
        Singly::LinkedList<type>& get_neighbors() { return this->neighbors; }

        // Printing
        /* Cout method for vertex in file: "Graph.cpp" */

    private:
        type data;
        Singly::LinkedList<type> neighbors;
    };

    namespace Undirected
    {
        template <typename type>
        class Graph
        {
        public:
            // Constructors and Destructor
            Graph(int size);
            Graph() { this->size = 0; }
            ~Graph() {}

            // Getters
            Singly::LinkedList<Unweighted::Vertex<type>> Get_vertices() const;
            int Get_size() const { return this->size; }
            Unweighted::Vertex<type>& Get_vertex_by_data(type data);

            // Adding methods
            void Add_vertex(type data);
            void Connect_vertices(type data1, type data2);

            // Other Methods
            bool Are_connected(type data1, type data2);
            
            // Printing
            void print() const;

        private:
            Singly::LinkedList<Unweighted::Vertex<type>> vertices;
            int size;
        };
    }
}

#endif /* GRAPH_HEADER */