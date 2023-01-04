#include <iostream>
#include <string>
#include "DataStructures/DataStructures.hpp"
using namespace std;

int main(void)
{
    Singly::LinkedList<int> list;

    for (unsigned int i = 1; i <= 10; i++)
        list.Insert_at_end(i);

    cout << list << endl;

    return 0;
}