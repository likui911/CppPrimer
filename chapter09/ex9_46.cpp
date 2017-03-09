/*
Rewrite the previous exercise using a position and length
to manage the string s. This time use only the insert function.
*/

#include <string>
#include <iostream>
using namespace std;

string func(const string &name, const string &prefix, const string &suffix)
{
    string s=name;
    s.insert(0,prefix,0,prefix.size());
    s.insert(s.size(),suffix,0,suffix.size());
    return s;
}

int main()
{
    string name = func("Jack", "Mr. ", " III");
    cout << name << endl;
    return 0;
}