/*
Write your own version of the biggies function using lambdas.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string::size_type sz = 5;
    auto fun = [sz](vector<string> &vec) {
        //sort the vector
        stable_sort(vec.begin(), vec.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
        //remove duplicated elements
        auto it = unique(vec.begin(), vec.end());
        vec.erase(it, vec.end());
        return find_if(vec.begin(), vec.end(), [sz](const string &a) { return a.size() >= sz; });
    };
    
    vector<string> vecs{};
    string s;
    while (cin >> s)
    {
        vecs.push_back(s);
    }

    for (auto it = fun(vecs); it != vecs.end(); ++it)
    {
        cout << *it << " ";
    }
    return 0;
}