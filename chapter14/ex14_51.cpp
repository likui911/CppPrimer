#include <iostream>

using namespace std;

/*
Exercise 14.51: Show the conversion sequences (if any) needed to call
each version of calc and explain why the best viable function is selected.
Code:
void calc(int);
void calc(LongDouble);
double dval;
calc(dval); // which calc?
*/

struct LongDouble
{
    LongDouble(double d = 0.0) : x(d) {}
    operator double() { return x; }
    operator float() { return x; }
    double x;
};

void calc(int)
{
    cout << "int" << endl;
}

void calc(LongDouble)
{
    cout << "LongDouble" << endl;
}
int main()
{

    double dval = 10.1;
    /*
    exact match
    const conversion
    promotion   
    arithmetic or pointer conversion
    class-type conversion
    */
    calc(dval); // calc(int) arithmetic conversion
    return 0;
}