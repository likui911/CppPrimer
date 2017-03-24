/*
Write a lambda that captures a local int variable and
decrements that variable until it reaches 0. Once the variable is 0
additional calls should no longer decrement the variable. The lambda
should return a bool that indicates whether the captured variable is 0.
*/
#include <iostream>

using namespace std;

int main()
{
    int local_int = 7;
    auto fun = [&]() {
        if (local_int == 0)
        {
            return true;
        }
        else
        {
            local_int--;
            return false;
        }
    };

    while (!fun())
    {
        cout << local_int << endl;
    }
    return 0;
}