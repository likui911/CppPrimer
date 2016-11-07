#include <iostream>
using namespace std;

int main()
{
    int a[10], b[10];
    cout << "Pls input the array a of 10 elements" << endl;
    for (int i = 0; i < 10; ++i)
    {
        cin >> *(a + i);
    }
    cout << "Pls input the array b of 10 elements" << endl;
    for (int i = 0; i < 10; ++i)
    {
        cin >> *(b + i);
    }

    // check if the two array equal
    for (int i = 0; i < 10; ++i)
    {
        if (*(a + i) != *(b + i))
        {
            cout << "Not Equal" << endl;
            break;
        }
    }
    cout << "Equal" << endl;
    return 0;
}