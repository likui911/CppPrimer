#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
bool compare(const T &v1, const T &v2)
{
    if(v1<v2)
    {
        return -1;
    }
    if(v2<v1)
    {
        return 1;
    }
    return 0;
}

template<unsigned N,unsigned M>
bool compare(const char(&p1)[N],const char(&p2)[M])
{
    return strcmp(p1,p2);
}


int main()
{
    double a=1.1;
    double b=1.11;
    cout<<compare(a,b)<<endl;
    cout<<compare("america","china")<<endl;
    return 0;
}