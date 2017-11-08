/*
Write and test a swap function for your valuelike version of HasPtr. 
Give your swap a print statement that notes when it is executed
*/
#include <string>
#include <iostream>
using namespace std;

class HasPtr
{
  public:
    friend void swap(HasPtr &lhs, HasPtr &rhs);
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const std::string &s, int d) : ps(new std::string(s)), i(d) {}
    HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) {}
    HasPtr(HasPtr &&p) noexcept
    {
        i = p.i;
        ps = p.ps;
        p.ps = nullptr;
    }
    bool operator<(const HasPtr &p) const
    {
        return this->i < p.i;
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

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main()
{
    HasPtr p1("kui", 2);
    HasPtr p2("li", 1);
    //todo
    if(p2<p1)
    {
        cout<<"true"<<endl;
    }
    return 0;
}