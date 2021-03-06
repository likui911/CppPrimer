#include <iostream>

using namespace std;

int main()
{
    int ia[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // version 1,using range for
    cout << "Version 1:" << endl;
    for (auto &p : ia)
    {
        for (int q : p)
        {
            cout << q << " ";
        }
        cout << endl;
    }

    // version 2,using ordinary for range
    cout << "Version 2:" << endl;
    for (auto i = 0; i < 3; ++i)
    {
        for (auto j = 0; j < 4; ++j)
        {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }

    // version 3,using pointer
    cout << "Version 3:" << endl;
    for (auto *p = ia; p != ia + 3; ++p)
    {
        for (auto *q = *p; q != *p + 4; ++q)
        {
            cout << *q << " ";
        }
        cout << endl;
    }
    return 0;
}