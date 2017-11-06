/*
A good way to understand copy-control members and constructors is to define a simple class with 
these members in which each member prints its name:
    struct X {
        X() {std::cout << "X()" << std::endl;}
        X(const X&) {std::cout << "X(const X&)" << std::endl;}
    };

*/
#include <iostream>
#include <vector>
using namespace std;

struct X
{
    X() { std::cout << "X()" << std::endl; }
    X(const X &) { std::cout << "X(const X&)" << std::endl; }
    X &operator=(const X &) { std::cout << "operator=" << std::endl; }
    ~X() { std::cout << "destructor X" << std::endl; }
};

void ref_fun(X &x)
{
}

void nonref_fun(X x)
{
}

int main()
{
    X x;
    //pass x as nonreference
    nonref_fun(x);
    //pass x as reference
    ref_fun(x);
    //dynamic allocate X
    X *x1{new X};
    delete x1;
    //put X in container
    {
        vector<X> vec(10);
    }
    return 0;
}