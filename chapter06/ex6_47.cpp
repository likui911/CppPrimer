/*
Revise the program you wrote in the exercises in § 6.3.2
(p. 228) that used recursion to print the contents of a vector to
conditionally print information about its execution. For example, you might
print the size of the vector on each call. Compile and run the program with
debugging turned on and again with it turned off.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector<string>::iterator beg, vector<string>::iterator end)
{
#ifndef NDEBUG
    cout << end - beg << endl;
#endif //DEBUG模式下，输出vector的长度

    while (beg != end)
    {
        cout << *beg << " ";
        ++beg;
    }
    cout << endl;
}

int main()
{
    vector<string> vs = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};
    print(vs.begin(), vs.end());
    return 0;
}

