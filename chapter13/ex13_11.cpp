/*
Add a destructor to your HasPtr class from the previous exercises.
*/
#include <string>
using namespace std;

class HasPtr
{
  public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) {}
    HasPtr &operator=(const HasPtr &p)
    {
        i = p.i;
        ps = new std::string(*p.ps);
        return *this;
    }
    ~HasPtr()
    {
        delete ps;
    }

  private:
    std::string *ps;
    int i;
};