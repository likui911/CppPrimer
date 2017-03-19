/*
Rewrite the previous exercise to use stable_partition,
which like stable_sort maintains the original element order in the
paritioned sequence.
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
        sort(vec.begin(),vec.end());
        //remove duplicated elements
        auto it = unique(vec.begin(), vec.end());
        vec.erase(it, vec.end());
        //partition vector
        it = stable_partition(vec.begin(),vec.end(),[sz](const string &a) { return a.size() < sz;});
        return it;
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