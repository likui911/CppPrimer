#include <iostream>

using namespace std;

int fact(int n)
{
    int ret = 1;
    while (n > 1)
    {
        ret *= n;
        n--;
    }
    return ret;
}

int main()
{
    int a = fact(5);
    cout << a << endl;
    return 0;
}