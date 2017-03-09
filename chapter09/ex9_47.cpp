/*
Write a program that finds each numeric character and
then each alphabetic character in the string "ab2c3d7R4E6". Write two
versions of the program. The first should use find_first_of, and the
second find_first_not_of.
*/
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s="ab2c3d7R4E6";
    string::size_type pos=0;
    //find all numeric character 
    while((pos=s.find_first_of("1234567890",pos))!=string::npos)
    {
        cout<<s[pos];
        pos++;
    }
    
     //find all alphabetic character 
    cout<<endl;
    pos=0;
    while((pos=s.find_first_not_of("1234567890",pos))!=string::npos)
    {
        cout<<s[pos];
        pos++;
    }
    return 0;
}