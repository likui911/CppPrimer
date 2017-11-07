/*
Assume that we want HasPtr to behave like a value. That is, each object should have its 
own copy of the string to which the objects point. We’ll show the definitions of the 
copy-control members in the next section. However, you already know everything you need 
to know to implement these members. Write the HasPtr copy constructor and copyassignment 
operator before reading on.
*/
#include <string>
using namespace std;

class HasPtr
{
  public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) {}
    HasPtr(HasPtr &&p) noexcept
    {
        i = p.i;
        ps = p.ps;
        p.ps = nullptr;
    }
    HasPtr &operator=(const HasPtr &p)
    {
        auto nps = new string(*p.ps);
        delete ps;
        ps = nps;
        i = p.i;
        return *this;
    }
    ~HasPtr() { delete ps; }

  private:
    std::string *ps;
    int i;
};