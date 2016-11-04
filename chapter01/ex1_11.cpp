#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cout << "Please input two nums:" << endl;
    cin >> a >> b;

    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    while (a <= b)
    {
        cout << a << " ";
        a++;
    }

    return 0;
}