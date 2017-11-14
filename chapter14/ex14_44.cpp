/*
Write your own version of a simple desk calculator that can handle binary operations.
*/
#include <functional>
#include <map>
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::function;
using std::map;
using std::string;

int add(int a, int b)
{
    return a + b;
}

auto minus = [](int a, int b) -> int { return a - b; };

struct divide
{
    int operator()(int a, int b) { return a / b; }
};

int mutiply(int a, int b)
{
    return a * b;
}

int main()
{
    //wrap any kind of callable element 
    map<string, function<int(int, int)>> binops;
    binops.insert({"+", add});
    binops.insert({"-", minus});
    binops.insert({"*", mutiply});
    binops.insert({"/", divide()});
    string op;
    int a, b;
    while (cin >> op >> a >> b)
    {
        cout << binops[op](a, b) << endl;
    }

    return 0;
}