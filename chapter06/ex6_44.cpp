#include <iostream>
#include <string>

using namespace std;

inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    string a = "hi";
    string b = "world";
    if (isShorter(a, b))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}