/*
Explain the difference between these two conversion operators:
struct Integral {
    operator const int();
    operator int() const;
};
*/
#include <iostream>

using namespace std;

struct Integral
{
    Integral(int i = 0) : value(i) {}

    // operator const int()
    // {
    //     cout << "operator const int" << endl;
    //     return value;
    // }

    operator int() const
    {
        cout << "operator int const" << endl;
        return value;
    }

    operator int()
    {
        cout<<"operator int"<<endl;
        return value;
    }
  private:
    int value;
};

int main()
{
    const Integral i(10);
    i+10;//operator int const
    Integral j(9);
    j+10;//operator const int
    return 0;
}