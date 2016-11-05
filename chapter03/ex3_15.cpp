#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> vec_str;
    string input;
    while (cin >> input)
    {
        vec_str.push_back(input);
    }

    for (auto s : vec_str)
    {
        cout << s << " ";
    }
    return 0;
}