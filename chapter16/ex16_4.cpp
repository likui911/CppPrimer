#include <vector>
#include <iostream>
using namespace std;
template <typename InputIter, typename T>
InputIter find(InputIter first, InputIter last, const T &val)
{
    while (first != last)
    {
        if (*first == val)
        {
            return first;
        }
        ++first;
    }
    return last;
}

int main()
{
    vector<int> veci{1, 2, 3, 4, 5, 6, 6, 7, 8, 9};
    auto iter=find(veci.begin(),veci.end(),5);
    if(iter!=veci.end())
    {
        cout<<"find"<<endl;
    }
    return 0;
}