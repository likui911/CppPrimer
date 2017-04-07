/*
In the exercises for § 10.3.2 (p. 392) you wrote a
version of biggies that uses partition. Rewrite that function to use
check_size and bind.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &a, string::size_type sz)
{
    return a.size() > sz;
}

int main()
{

    vector<string> vecs{};
    string s;
    while (cin >> s)
    {
        vecs.push_back(s);
    }

    sort(vecs.begin(), vecs.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
    unique(vecs.begin(), vecs.end());
    auto it = find_if(vecs.begin(), vecs.end(), bind(check_size, _1, 6));

    for (; it != vecs.end(); ++it)
    {
        cout << *it << " ";
    }
    return 0;
}