/*
Write a funtion that takes a string representing a name
and two other strings representing a prefix, such as “Mr.” or “Ms.” and a
suffix, such as “Jr.” or “III”. Using iterators and the insert and append
functions, generate and return a new string with the suffix and prefix
added to the given name.
*/
#include <string>
#include <iostream>
using namespace std;

string func(const string &name, const string &prefix, const string &suffix)
{
    string s=name;
    s.insert(s.begin(),prefix.cbegin(),prefix.cend());
    s.append(suffix);
    return s;
}

int main()
{
    string name=func("Jack","Mr. "," III");
    cout<<name<<endl;
    return 0;
}