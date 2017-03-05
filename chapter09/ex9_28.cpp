/*
Write a function that takes a forward_list<string> and two
additional string arguments. The function should find the first string and
insert the second immediately following the first. If the first string is not
found, then insert the second string
*/
#include <forward_list>
#include <string>
#include <iostream>

using namespace std;

void find_insert(forward_list<string> &fwd, const string &fir, const string &sec)
{
    forward_list<string>::iterator prev = fwd.before_begin();
    forward_list<string>::iterator curr = fwd.begin();
    while (curr != fwd.end())
    {
        if ((*curr) == fir)
        {
            //发现fir的处理
            curr=fwd.insert_after(curr,sec);
            return;
        }
        prev=curr;
        curr++;
    }
    //未发现fir的处理
    fwd.insert_after(prev,sec);
}

int main()
{
    forward_list<string> fwd{"additional", "before_begin", "function", "immediately"};
    find_insert(fwd, "function", "method");
    for(string s:fwd)
    {
        cout<<s<<endl;
    }
    return 0;
}