#include <iostream>

using namespace std;
int main()
{
    int i=0,&r=i;
    auto a =r; // int

    const int ci = i,&cr=i;
    auto b = ci;//int
    auto c = cr; //int
    auto d =&r;//int *
    auto e = &ci;//const int *

    const auto f = ci;//const int
    auto &g = ci;//const int&
    const auto &j = 42;//const int&

    return 0;
}