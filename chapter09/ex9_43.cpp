/*
Write a function that takes three strings, s, oldVal, and
newVal. Using iterators, and the insert and erase functions replace all
instances of oldVal that appear in s by newVal. Test your function by using
it to replace common abbreviations, such as “tho” by “though” and “thru”
by “through”.
*/
#include <string>
#include <iostream>

using namespace std;

void replace(string &s, const string &oldVal, const string &newVal)
{
    string::iterator iter = s.begin();
    while (iter != s.end())
    {
        string temp = string(&(*iter), oldVal.size());
        if (temp == oldVal)
        {
            //檫除旧值
            iter = s.erase(iter, iter + oldVal.size());
            //插入新值
            iter = s.insert(iter, newVal.cbegin(), newVal.cend());
            iter += newVal.size();
            //继续下一个循环
            continue;
        }
        iter++;
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