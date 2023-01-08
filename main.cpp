#include <iostream>
#include <string>
#include "DataStructures/DataStructures.hpp"
using namespace std;

int main(void)
{
    Dictionary<string, string> info;

    info.Add("name", "Antonis");
    info.Add("age", "19");
    info.Add("gender", "male");

    cout << info << endl;

    Dictionary<string, string> info2 = info;

    cout << info2 << endl;

    return 0;
}