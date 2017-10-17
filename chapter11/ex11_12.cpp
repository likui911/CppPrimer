/*
Write a program to read a sequence of strings and ints,
storing each into a pair. Store the pairs in a vector.
*/
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    string s;
    int i;
    vector<pair<string, int>> vec;
    while (cin >> s >> i)
    {
        pair<string, int> p{s, i};
        vec.push_back(p);
    }

    for(auto &p:vec)
    {
        cout<<p.first<<" - "<<p.second<<endl;
    }
    return 0;
}