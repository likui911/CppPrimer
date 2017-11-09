/*
Write and test a swap function for your valuelike version of HasPtr. 
Give your swap a print statement that notes when it is executed
*/
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class HasPtr
{
  public:
    friend void swap(HasPtr &lhs, HasPtr &rhs);
    friend ostream &operator<<(ostream &os, const HasPtr &ptr);

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

    HasPtr &operator=(HasPtr rhs)
    {
        swap(*this, rhs);
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

ostream &operator<<(ostream &os, const HasPtr &ptr)
{
    cout << *ptr.ps << " - " << ptr.i;
    return os;
}

int main()
{
    HasPtr p1("kui", 2);
    HasPtr p2("li", 1);

    vector<HasPtr> vec;
    vec.push_back(p1);
    vec.push_back(p2);

    //sort the HasPtr's vector,it will invoke the swap function
    sort(vec.begin(), vec.end());
    for (auto p : vec)
    {
        cout << p << endl;
    }
    return 0;
}