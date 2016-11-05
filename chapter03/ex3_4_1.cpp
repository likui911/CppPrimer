#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << "string a and b are equal !" << endl;
    }
    else
    {
        if (a >= b)
        {
            cout << "a bigger than b !" << endl;
        }

        else
        {
            cout << "b bigger than a !" << endl;
        }
    }
    return 0;
}