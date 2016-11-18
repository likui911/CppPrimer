#include <iostream>

using namespace std;

int absolute(int n)
{
    return n > 0 ? n : -n;
}

int main()
{
    int n;
    cout << "pls input a integer: " << endl;
    cin >> n;
    cout << absolute(n) << endl;
    return 0;
}