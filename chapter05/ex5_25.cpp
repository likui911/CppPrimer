#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cout << "Pls input two integers: ";
    while (cin >> a >> b)
    {
        try
        {
            if (b == 0)
                throw runtime_error("Divide By Zero");
            cout << (double)a / b << endl;
            cout << "Pls input two integers: ";
        }
        catch (runtime_error err)
        {
            cerr << err.what() << endl;
            cout << "Do you continue ? y or n " << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
            else
                cout << "Pls input two integers: ";
        }
    }
    return 0;
}