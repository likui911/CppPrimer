/*
Write a lambda that takes two ints and returns their sum.
*/
#include <iostream>
using namespace std;

int main()
{
    int a = 13, b = 14;
    auto fun = [](int i, int j) { return i + j; };
    cout << fun(a, b) << endl;
    return 0;
}