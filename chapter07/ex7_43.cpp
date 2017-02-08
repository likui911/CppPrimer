#include <iostream>
#include <vector>
using std::vector;

class NoDefault
{
  public:
    NoDefault(int n) : integral(n){};

  private:
    int integral;
};

class C
{
  public:
    C() : ndef(0){};

  private:
    NoDefault ndef;
};

int main()
{
    vector<NoDefault> vec(10);
    return 0;
}