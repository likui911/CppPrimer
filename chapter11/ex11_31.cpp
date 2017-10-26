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

int main()
{
    multimap<string, string> authors{
        {"alan", "DMA"},
        {"pezy", "LeetCode"},
        {"alan", "CLRS"},
        {"wang", "FTP"},
        {"pezy", "CP5"},
        {"wang", "CPP-Concurrency"},
        {"pezy", "CP5"}};

    string author{"likui"};
    string work{"Cpp"};

    for (auto found = authors.find(author);
         found != authors.end() && found->first == author; ++found)
    {
        if (found->second == work)
        {
            authors.erase(found);
        }
    }
    return 0;
}