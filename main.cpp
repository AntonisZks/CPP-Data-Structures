#include <iostream>
#include <string>
#include "DataStructures/DataStructures.hpp"
using namespace std;

int main(void)
{
    Doubly::LinkedList<int> list1, list2, list3;
    Dictionary<int, Doubly::LinkedList<int>> links;

    for (int i = 0; i < 3; i++)
        list1.Insert(i);

    for (int i = 4; i < 9; i++)
        list2.Insert(i);

    for (int i = 10; i < 20; i++)
        list3.Insert(i);

    links.Add(1, list1);
    links.Add(2, list2);
    links.Add(3, list3);

    cout << links << endl;

    links.Remove(1);

    cout << links << endl;

    links.Get_value_of(2).Insert_at_end(5);
    cout << links.Get_value_of(2) << endl;

    return 0;
}