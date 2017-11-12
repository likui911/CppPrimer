/*
What if we defined sorted as:
Code:
    Foo Foo::sorted() const & { return Foo(*this).sorted(); }
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
    //临时变量调用&&版本sorted
    return Foo(*this).sorted();
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