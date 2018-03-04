#include <iostream>
#include <vector>
using namespace std;

template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
    return *beg;
}

int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8,9,0};
    cout<<fcn3(vec.begin(),vec.end())<<endl;
    return 0;
}