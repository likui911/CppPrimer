#include <iostream>
#include <vector>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return b != 0 ? a / b : 0;
}

int main()
{
    using pFunc = int (*)(int, int);
    std::vector<pFunc> vpf;
    vpf.push_back(add);
    vpf.push_back(subtract);
    vpf.push_back(multiply);
    vpf.push_back(divide);

    int a = 10, b = 2;
    for (std::vector<pFunc>::iterator i = vpf.begin(); i != vpf.end(); ++i)
    {
        std::cout << (*i)(a, b) << endl;
    }
    return 0;
}