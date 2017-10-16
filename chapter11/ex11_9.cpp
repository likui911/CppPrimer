/*
Define a map that associates words with a list of line
numbers on which the word might occur.
*/
#include <map>
#include <list>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    map<string, list<size_t>> occur;

    string line;
    int lineno;
    while (getline(cin, line))
    {
        ++lineno; //generate lineno
        stringstream ss{line};
        string temp;
        while (ss >> temp)
        {
            occur[temp].push_back(lineno);
        }
    }

    for (auto &m : occur)
    {
        cout << m.first<<" : ";
        for (auto &i : m.second)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}