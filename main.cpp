#include <iostream>
#include <string>
#include "DataStructures/DataStructures.hpp"
using namespace std;

int main(void)
{
    Singly::LinkedList<string> keys;

    keys.Insert("Key1");
    keys.Insert("Key2");
    keys.Insert("Key3");

    int value = 0;

    Dictionary<string, int> dict;

    dict.Create_from_keys(keys, value);

    dict.set_smart_printing(true);

    cout << dict["Key0"] << endl;

    return 0;
}