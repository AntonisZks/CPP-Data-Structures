#include <iostream>
#include <string>
#include "DataStructures/DataStructures.hpp"
using namespace std;

int main(void)
{
    Unweighted::Undirected::Graph<string> g1;

    g1.Add_vertex("Bill");
    g1.Add_vertex("Vicky");
    g1.Add_vertex("Tom");

    g1.Connect_vertices("Bill", "Vicky");
    g1.Connect_vertices("Vicky", "Tom");
    g1.Connect_vertices("Bill", "Tom");
    
    cout << g1 << endl;
    
    g1.Connect_vertices("Vicky", "Bill");
    
    cout << g1 << endl;

    return 0;
}