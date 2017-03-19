/*
The library defines an algorithm named partition that
takes a predicate and partitions the container so that values for which the
predicate is true appear in the first part and those for which the predicate
is false appear in the second part. The algorithm returns an iterator just
past the last element for which the predicate returned true. Write a
function that takes a string and returns a bool indicating whether the
string has five characters or more. Use that function to partition words.
Print the elements that have five or more characters.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool fiveMore(const string &s)
{
    return s.size() > 5;
}

int main()
{
    vector<string> ves{};
    string s;
    while (cin >> s)
    {
        ves.push_back(s);
    }
    auto it = partition(ves.begin(), ves.end(), fiveMore);
    for(auto i=ves.cbegin();i!=it;++i)
    {
        cout<<*i<<" ";
    }
    return 0;
}