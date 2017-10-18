/*
Extend the map of children to their family name that you
wrote for the exercises in § 11.2.1 (p. 424) by having the vector store a
pair that holds a child’s name and birthday.
*/
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <utility>
using namespace std;

int main()
{

    map<string, vector<pair<string, string>>> families;
    cout << "usage: lastname firstname birthday\\n"
         << endl;
    string lastname, firstname, birthday;
    while (cin >> lastname >> firstname >> birthday)
    {
        families[lastname].push_back(make_pair(firstname, birthday));
    }

    cout << "The result:\n";
    for (auto const &elem : families)
    {
        for (auto &p : elem.second)
        {
            cout << p.first << " - " << p.second << endl;
        }
    }

    return 0;
}