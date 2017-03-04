#include <vector>
#include <iostream>

using namespace std;

typedef vector<int>::iterator iter;

iter find(iter begin, iter end, int inc)
{
    while (begin != end)
    {
        if (*begin == inc)
            //如果找到了，返回当前的iter
            return begin;
        begin++;
    }
    //如果未找到，返回end
    return end;
}