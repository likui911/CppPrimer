/*
Write a program that uses stable_sort and isShorter to
sort a vector passed to your version of elimDups. Print the vector to verify
that your program is correct.
*/
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool isShorter(const string &s1, const string &s2)
{
    return s1 < s2;
}

void elimDups(vector<string> &vec)
{
    stable_sort(vec.begin(), vec.end(), isShorter);
    auto it = unique(vec.begin(), vec.end());
    vec.erase(it);
}

int main()
{
    vector<string> vec{};
    string str;
    while (cin >> str)
    {
        vec.push_back(str);
    }
    elimDups(vec);
    for (auto s : vec)
    {
        cout << s << endl;
    }
    return 0;
}