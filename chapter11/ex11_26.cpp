/*
What type can be used to subscript a map? What type
does the subscript operator return? Give a concrete example—that is,
define a map and then write the types that can be used to subscript the map
and the type that would be returned from the subscript operator.
*/
#include <map>
using namespace std;

int main()
{
    map<int, int> m{{0, 1}, {1, 2}};
    std::map<int, int>::key_type index = 0;
    std::map<int, int>::mapped_type returned = m[index];

    return 0;
}