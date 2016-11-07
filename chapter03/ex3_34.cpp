#include <iostream>

int main()
{
    int a = 10;
    int *p1 = &a, *p2 = &a;
    p1 += p2 - p1;
    return 0;
}