#include <list>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    list<string> lis{"abc","def","abc","def","abc"};
    cout<<count(lis.begin(),lis.end(),"abc")<<endl;
    return 0;
}