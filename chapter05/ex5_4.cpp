#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "abcdefghijklmn";
    string::iterator iter = s.begin();
    while (iter != s.end())
    {
        cout << *iter << endl;
        ++iter;
    }
    return 0;
}