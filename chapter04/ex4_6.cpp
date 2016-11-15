#include <iostream>

using namespace std;

int main()
{
    /*
    *write a expression to determine whether an int value is even or odd 
    */
    int i;
    cout << "Pls input a integer number:" << endl;
    cin >> i;
    if (i % 2 == 0)
    {
        cout << "even" << endl;
    }
    else
    {
        cout << "odd" << endl;
    }

    return 0;
}