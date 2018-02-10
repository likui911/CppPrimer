#include <iostream>
using namespace std;

struct Base
{
    Base() { cout << "construct" << endl; }
    Base(int x, int y = 1) : ix(x), iy(y) { cout << ix << iy << endl; }

  private:
    int ix;
    int iy;
};

class Derived : public Base
{
  private: //构造函数继承不会改变访问级别
    //c++11 派生类能够重用基类的构造函数
    //下面是显示的提供了声明，编译器会在派生类中生成一个参数完全一致的构造函数
    using Base::Base; //有默认参数的，会继承多个，省略掉默认参数
  public:
    Derived(int x) //Base(int x,int y=1)有相同的参数，不会继承
    {
        cout << "Derived" << endl;
    }
};

int main()
{
    // Derived d;
    Derived d(1);
    Derived dd(1, 2);
    return 0;
}