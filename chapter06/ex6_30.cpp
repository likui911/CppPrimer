#include <iostream>
#include <string>
using namespace std;

bool str_subrange(const string &str1, const string &str2)
{
    // same sizes: return normal equality test
    if (str1.size() == str2.size())
        return str1 == str2; // ok: == returns bool
    // find the size of the smaller string; conditional operator, see § 4.7 (p. 151)
    auto size = (str1.size() < str2.size())
                    ? str1.size()
                    : str2.size();
    // look at each element up to the size of the smaller string
    for (decltype(size) i = 0; i != size; ++i)
    {
        if (str1[i] != str2[i])
            return false;// error #1: no return value; compiler should detect this error
    }
    // error #2: control might flow off the end of the function without a return
    return true;
}

int main()
{
    string s1="abv";
    string s2 = "efgh";
    str_subrange(s1,s2);
    return 0;
}