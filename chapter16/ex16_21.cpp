//Write your own version of DebugDelete
#include <iostream>
using namespace std;

class DebugDelete
{
  public:
    DebugDelete(ostream &os = std::cerr) : output(os)
    {
    }

    template <typename T>
    void operator()(T *p) const
    {
        output << "delete unique_ptr" << endl;
        delete p;
    }

  private:
    ostream &output;
};

int main()
{
    double *p = new double;
    DebugDelete d;
    d(p);
    int *ip = new int;
    DebugDelete()(ip);
    return 0;
}