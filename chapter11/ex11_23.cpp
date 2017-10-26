/*
Rewrite the map that stored vectors of children’s names
with a key that is the family last name for the exercises in § 11.2.1 (p.
424) to use a multimap.
*/
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    map<string, string> families;
    cout << "usage: lastname firstname \n"
         << endl;

    string lastname, firstname;
    while (cin >> lastname >> firstname)
    {
        families.emplace(lastname, firstname);
    }

    cout << "The result:\n";
    for (auto const &elem : families)
    {
        cout << elem.second << " - " << elem.first << endl;
    }
    return 0;
}
