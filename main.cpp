#include <iostream>
#include <string>
#include "DataStructures/DataStructures.hpp"
using namespace std;
using namespace Doubly;

int main(void)
{
    llist<int> list;

    for (int i = 0; i < 10; i++)
        list.Insert(i);

    Dictionary<string, llist<int>> dictionary;

    dictionary.Add("Key1", list);
    dictionary.Add("Key2", list);
    dictionary.Add("Key3", list);
    dictionary.Set_smart_printing(true);

    cout << dictionary << endl;

    return 0;
}