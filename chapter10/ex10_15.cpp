/*
Write a lambda that captures an int from its enclosing
function and takes an int parameter The lambda should return the sum of
the captured int and the int parameter
*/
#include <iostream>
using namespace std;

int main()
{
    int sz = 10;
    auto fun = [sz](int i) { return sz + i; };
    cout<<fun(15)<<endl;
    return 0;
}