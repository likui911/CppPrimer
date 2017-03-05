#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> v{1,2,3,4,5};
    auto begin = v.begin();
    while (begin != v.end()) {
        ++begin;         
        //如果没有将insert后的return结果赋给begin的话，begin是invalid
        //因为对list进行insert操作会破坏iterator
        //v.insert(begin, 42);
        begin=v.insert(begin,42); 
        ++begin;
    }

    //testing
    for(int i:v)
    {
        cout<<i<<" ";
    }
    return 0;
}