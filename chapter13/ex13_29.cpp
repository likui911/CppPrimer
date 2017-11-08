/*
Explain why the calls to swap inside swap(HasPtr&,HasPtr&) do not cause a recursion loop
*/

#include <string>
#include <iostream>
using namespace std;

class HasPtr
{
  public:
    friend void swap(HasPtr &lhs, HasPtr &rhs);
    HasPtr(const string &s = string())
        : ps(new string(s)), i(0), use(new size_t(1)) {}

    HasPtr(const HasPtr &p)
        : ps(p.ps), i(p.i), use(p.use) { ++*use; }

    //...

  private:
    string *ps;
    int i;
    size_t *use;
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.use, rhs.use);
}
///////////////////////

int main()
{
    HasPtr p1;
    HasPtr p2,p3(p2);
    swap(p1, p3);
    return 0;
}
