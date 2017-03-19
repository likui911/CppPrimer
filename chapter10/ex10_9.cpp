/*
Implement your own version of elimDups. Test your
program by printing the vector after you read the input, after the call to
unique, and after the call to erase.
*/
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

void elimDups(vector<string> &s)
{
    sort(s.begin(), s.end());
    auto it = unique(s.begin(), s.end());
    s.erase(it, s.end());
}

int main()
{
    vector<string> str{};
    string s;
    while (cin >> s)
        str.push_back(s);
    elimDups(str);
    for (auto s : str)
        cout << s << " ";
    return 0;
}