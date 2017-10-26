/*
Write a program that defines a multimap of authors and
their works. Use find to find an element in the multimap and erase that
element. Be sure your program works correctly if the element you look for
is not in the map.
*/
#include <map>
#include <string>
#include <iostream>
using namespace std;

typedef std::string Author;
typedef std::string Work;
int main()
{
    multimap<Author, Work> aw;
    aw.insert(make_pair("james", "look"));
    aw.insert(make_pair("james", "fish"));
    aw.insert(make_pair("james", "cooking"));
    aw.insert(make_pair("jack", "fish"));

    multimap<Author, Work>::iterator iter = aw.find("likui");
    if (iter == aw.end())
    {
        cout << "not exist" << endl;
    }
    else
    {
        aw.erase(iter);
    }
    return 0;
}