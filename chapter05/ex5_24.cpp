#include <iostream>

using namespace std;

double div(int a, int b)
{
    if (b == 0)
        throw runtime_error("Divide Zero");
    return (double)a / b;
}
int main()
{
    int a, b;
    double result;
    cout << "Pls input two integers:" << endl;
    cin >> a >> b;
    result = div(a, b);
    cout << result << endl;
    return 0;
}