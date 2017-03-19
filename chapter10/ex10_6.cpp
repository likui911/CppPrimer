/*
Using fill_n, write a program to set a sequence of int
values to 0.
*/
#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec{1,2,3,4};
    //iterator header,insert iterator
    auto it = back_inserter(vec);
    fill_n(it,15,0);
    for(auto i:vec)
    {
        cout<<i<<endl;
    }
    return 0;
}