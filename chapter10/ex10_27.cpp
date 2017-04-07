/*
In addition to unique (§ 10.2.3, p. 384), the library
defines function named unique_copy that takes a third iterator denoting a
destination into which to copy the unique elements. Write a program that
uses unique_copy to copy the unique elements from a vector into an initially
empty list.
*/
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    vector<string> vec{"unique_copy","copy","unique","copy","to"};
    sort(vec.begin(),vec.end());
    list<string> li{};
    // back_inserter 等价于 push_back
    unique_copy(vec.begin(),vec.end(),back_inserter(li));
    for(auto s:li)
    {
        cout<<s<<" ";
    }
    return 0;
}