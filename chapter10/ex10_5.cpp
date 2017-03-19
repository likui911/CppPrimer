#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    char s1[12] = "hello world";
    char s2[12] = "hello world";
    bool eq = equal(begin(s1), end(s1), begin(s2));
    cout << eq << endl;
    return 0;
}