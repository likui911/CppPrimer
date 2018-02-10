#include <iostream>
using namespace std;

struct Base
{
    Base() { cout << "construct" << endl; };
};

class Derived : public Base
{
    //c++11 派生类能够重用基类的构造函数
    //下面是显示的提供了声明，编译器会在派生类中生成一个参数完全一致的构造函数
    //using Base::Base; 
};

int main()
{
    Derived d;
    return 0;
}