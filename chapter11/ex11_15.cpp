/*
What are the mapped_type, key_type, and value_type of a
map from int to vector<int>?
*/
#include <map>
#include <string>
#include <utility>
#include <set>

using namespace std;

int main()
{
    std::map<std::string, int> map;
    std::map<std::string, int>::key_type s1 = "hello";
    std::map<std::string, int>::mapped_type i1 = 1;
    //set's key_type==value_type
    std::set<int>::value_type i2 = 2;
    return 0;
}