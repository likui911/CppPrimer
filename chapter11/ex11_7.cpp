/*
Define a map for which the key is the family’s last name
and the value is a vector of the children’s names. Write code to add new
families and to add new children to an existing family.
*/
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    map<string, vector<string>> families;
    cout << "usage: lastname firstname \\n"
         << endl;
    string lastname, firstname;
    while (cin >> lastname >> firstname)
    {
        families[lastname].push_back(firstname);
    }

    cout << "The result:\n";
    for (auto const &elem : families)
    {
        for (auto p : elem.second)
        {
            cout << p << endl;
        }
    }

    return 0;
}