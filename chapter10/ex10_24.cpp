/*
 Use bind and check_size to find the first element in a
 vector of ints that has a value greater than the length of a specified
 string value.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() < sz;
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5};
    string str("abc");
    auto wc = find_if(vec.begin(), vec.end(), bind(check_size, ref(str), _1));
    if (wc == vec.end())
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    return 0;
}