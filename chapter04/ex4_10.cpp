#include <iostream>

using namespace std;

int main()
{
    int i;
    while (cin >> i)
    {
        if (i == 42)
        {
            cout << "i equal to 42" << endl;
            break;
        }
        cout << i << endl;
    }

    return 0;
}