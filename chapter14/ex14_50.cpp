/*
Exercise 14.50: Show the possible class-type conversion sequences for
the initializations of ex1 and ex2. Explain whether the initializations are legal
or not.
Code:
struct LongDouble {
    LongDouble(double = 0.0);
    operator double();
    operator float();
};
LongDouble ldObj;
int ex1 = ldObj;
float ex2 = ldObj;
*/

struct LongDouble
{
    LongDouble(double = 0.0);
    operator double();
    operator float();
};
int main()
{
    LongDouble ldObj;
    //ambiguous
    //int ex1 = ldObj;
    float ex2 = ldObj;
    return 0;
}
