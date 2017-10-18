/*
There are at least three ways to create the pairs in the
program for the previous exercise. Write three versions of that program,
creating the pairs in each way. Explain which form you think is easiest to
write and understand, and why.
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
        //pair<string, int> p{s, i};
        //pair<int,int> p2=make_pair(s,i);
        vec.push_back({s,i});
    }

    for(auto &p:vec)
    {
        cout<<p.first<<" - "<<p.second<<endl;
    }
    return 0;
}