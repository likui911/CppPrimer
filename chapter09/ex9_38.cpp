/*
Write a program to explore how vectors grow in the
library you use.
*/
#include <vector>
#include <iostream>

using namespace std;

int main()
{   
    vector<int> vec_i;
    //vector为空时，size和capacity都为0
    cout<<vec_i.size()<<" "<<vec_i.capacity()<<endl;
    for(int i=0;i<50;++i)
        vec_i.push_back(i);
    //capacity大于等于size
    cout<<vec_i.size()<<" "<<vec_i.capacity()<<endl;
    //capacity适应size后，capacity等于size，不保证
    vec_i.shrink_to_fit();
    cout<<vec_i.size()<<" "<<vec_i.capacity();


    return 0;
}