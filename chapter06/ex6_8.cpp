#include "chapter06.h"
#include <iostream>
using namespace std;

int fact(int num)
{
    int ret = 1;
    while (num > 1)
    {
        ret *= num;
        num--;
    }
    return ret;
}

int main()
{
    while (1)
    {
        cout << "Please input a number: " << endl;
        int num;
        cin >> num;
        cout << fact(num) << endl;
    }

    return 0;
}