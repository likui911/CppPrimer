#include <vector>
#include <list>
#include <string>

using namespace std;

int main()
{
    //c++11 does not allow convert string literal to char *
    list<const char *> lp = {"Money", "Likui"};
    vector<string> vec_s;
    vec_s.assign(lp.begin(), lp.end());
    return 0;
}