/*
What would happen if we defined sorted as:
Code:
    Foo Foo::sorted() const & {
        Foo ret(*this);
        return ret.sorted();
    }

*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Foo
{
  public:
    Foo sorted() &&;      // may run on modifiable rvalues
    Foo sorted() const &; // may run on any kind of Foo
                          // other members of Foo
    void push_back(int n) { data.push_back(n); }
    vector<int>::const_iterator begin() const { return data.begin(); }
    vector<int>::const_iterator end() const { return data.end(); }

  private:
    vector<int> data;
};
// this object is an rvalue, so we can sort in place
Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const &
{
    //在函数内，ret是左值，会调用当前函数
    //因此是个死循环
    Foo ret(*this);
    return ret.sorted();
}

//返回一个右值
Foo retVal()
{
    Foo f;
    for (int i = 10; i >= 0; --i)
    {
        f.push_back(i);
    }
    return f;
}

int main()
{

    Foo f(retVal());
    f.sorted(); //调用&sorted

    return 0;
}