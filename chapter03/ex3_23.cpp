#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec_int(10);

    for(int i=0;i<10;++i)
    {
        cin>>vec_int[i];
    }

    for(auto it=vec_int.begin();it!=vec_int.end();++it)
    {
        *it = *it *2;
    }

    for(auto it=vec_int.begin();it!=vec_int.end();++it)
    {
        cout<<*it<<endl;
    }

    return 0;
}
