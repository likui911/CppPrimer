/*
Use reverse_iterators to print a vector in reverse order.
*/
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8,9,0};
    for(auto iter=vec.crbegin();iter!=vec.crend();++iter)
    {
        cout<<*iter<<endl;
    }
    return 0;
}