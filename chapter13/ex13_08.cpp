/*
Write the assignment operator for the HasPtr class from
exercise 13.5 in § 13.1.1 (p. 499). As with the copy constructor, your
assignment operator should copy the object to which ps points
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

  private:
    std::string *ps;
    int i;
};