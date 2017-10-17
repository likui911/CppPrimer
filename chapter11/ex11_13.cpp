/*
There are at least three ways to create the pairs in the
program for the previous exercise. Write three versions of that program,
creating the pairs in each way. Explain which form you think is easiest to
write and understand, and why.
*/
#include <utility>

using namespace std;

int main()
{
    //todo
    pair<int,int> p1({{1,2},{3,4}});
    pair<int,int> p2=make_pair(1,2);
    pair<int,int> p3(1,2);
    return 0;
}