/*
Define your own reference-counted version of HasPtr.
*/
#include <string>
#include <iostream>
using namespace std;

class HasPtr
{
  public:
    HasPtr(const string &s = string())
        : ps(new string(s)), i(0), use(new size_t(1)) {}

    HasPtr(const HasPtr &p)
        : ps(p.ps), i(p.i), use(p.use) { ++*use; }

    HasPtr &operator=(const HasPtr &rhs)
    {
        ++*rhs.use;      //rhs引用+1
        if (--*use == 0) //lhs引用-1
        {
            delete ps;
            delete use;
        }
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this;
    }

    ~HasPtr()
    {
        if (--*use == 0)
        {
            delete ps;
            delete use;
        }
    }

  private:
    string *ps;
    int i;
    size_t *use;
};