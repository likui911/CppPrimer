#include <iostream>

using namespace std;

int largerOne(const int a, const int *b)
{
    return a > *b ? a : *b;
}

int main()
{
    int b = 55;
    cout << largerOne(33, &b) << endl;
    return 0;
}