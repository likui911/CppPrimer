/*
Given the following sketch of a class, write a copy
constructor that copies all the members. Your constructor should
dynamically allocate a new string (§ 12.1.2, p. 458) and copy the object
to which ps points, rather than copying ps itself.
    class HasPtr
    {
    public:
        HasPtr(const std::string &s = std::string()) 
                : ps(new std::string(s)), i(0) {}

    private:
        std::string *ps;
        int i;
    };  
*/
#include <string>
using namespace std;

class HasPtr
{
  public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) {}

  private:
    std::string *ps;
    int i;
};