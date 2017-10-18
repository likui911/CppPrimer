/*
Using a map iterator write an expression that assigns a
value to an element.
*/
#include <map>

int main()
{
    std::map<int, std::string> map;
    map[25] = "Alan";
    std::map<int, std::string>::iterator it = map.begin();
    it->second = "Wang";
    return 0;
}