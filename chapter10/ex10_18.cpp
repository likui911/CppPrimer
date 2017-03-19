/*
Rewrite biggies to use partition instead of find_if. We
described the partition algorithm in exercise 10.13 in § 10.3.1 (p. 387).
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
        it = partition(vec.begin(),vec.end(),[sz](const string &a) { return a.size() < sz;});
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