#include <vector>
using namespace std;

class NoDefault
{
  public:
    NoDefault(int i) {}
};

int main()
{
    vector<NoDefault> vec;
    return 0;
}