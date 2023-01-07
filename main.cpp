#include <iostream>
#include <string>
#include "DataStructures/DataStructures.hpp"
using namespace std;

int main(void)
{
    Singly::LinkedList<string> friends;

    friends.Insert("Tomas");
    friends.Insert("Stavros");
    friends.Insert("Thanos");

    Dictionary<string, Singly::LinkedList<string>> info;
    info.Set_smart_printing(true);

    info.Add("Friends", friends);

    cout << info << endl;

    friends.Sort();

    info.Add("Friends", friends);

    cout << info << endl;

    return 0;
}