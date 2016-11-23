#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector<string>::iterator beg, vector<string>::iterator end)
{
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