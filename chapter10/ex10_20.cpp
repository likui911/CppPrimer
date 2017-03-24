/*
The library defines an algorithm named count_if. Like
find_if, this function takes a pair of iterators denoting an input range and
a predicate that it applies to each element in the given range. count_if
returns a count of how often the predicate is true. Use count_if to rewrite
the portion of our program that counted how many words are greater than
length 6.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> vec{};
    string s;
    while (cin >> s)
    {
        vec.push_back(s);
    }
    string::size_type sz = 6;
    string::size_type nums = count_if(vec.begin(), vec.end(), [sz](const string &s) { return s.size() >= sz; });
    cout<<vec.size()<<endl;
    cout << nums << endl;
    return 0;
}