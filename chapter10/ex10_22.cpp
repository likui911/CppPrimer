/*
Rewrite the program to count words of size 6 or less
using functions in place of the lambdas.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool is_shorter(const string &s, string::size_type sz)
{
    return s.size() <= sz;
}

int main()
{
    auto less_6 = bind(is_shorter, _1, 6);
    vector<string> vecs{};
    string temp;
    while (cin >> temp)
        vecs.push_back(temp);

    sort(vecs.begin(), vecs.end(), [](const string &a, const string &b) { return a.size() > b.size(); });
    
    auto wc = find_if(vecs.begin(), vecs.end(), less_6);
  
    cout <<"total "<< vecs.end()-wc <<" words less than 6"<< endl;

    return 0;
}