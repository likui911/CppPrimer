/*
*Rewrite the previous function using an index and replace.
*/
#include <string>
#include <iostream>

using namespace std;

void replace(string &s, const string &oldVal, const string &newVal)
{
    for (string::size_type i=0; i < s.size(); ++i)
    {
        if(s.substr(i,oldVal.size())==oldVal)
        {
            s.replace(i,oldVal.size(),newVal);
            i+=newVal.size()-1;
        }
    }
}

int main()
{
    string str{"To drive straight thru is a foolish, tho courageous act."};
    replace(str, "thru", "through");
    replace(str, "tho", "though");
    std::cout << str << std::endl;

    string str1{
        "To drive straight thruthru is a foolish, thotho courageous act."};
    replace(str1, "thru", "through");
    replace(str1, "tho", "though");
    std::cout << str1 << std::endl;

    string str2{"To drive straight thru is a foolish, tho courageous act."};
    replace(str2, "thru", "thruthru");
    replace(str2, "tho", "though");
    std::cout << str2 << std::endl;

    string str3{"my world is a big world"};
    replace(str3, "world",
            "worldddddddddddddddddddddddddddddddddddddddddddddddd");
    std::cout << str3 << std::endl;

    return 0;
}