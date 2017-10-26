/*
Using the multimap from the previous exercise, write a
program to print the list of authors and their works alphabetically.
*/
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <utility>
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

    //copy all value to multiset
    multiset<pair<string, string>> authors_set;
    for (auto iter = authors.begin(); iter != authors.end(); ++iter)
    {
        authors_set.insert(*iter);
    }

    for (auto iter = authors_set.begin(); iter != authors_set.end(); ++iter)
    {
        cout << iter->first << "  " << iter->second << endl;
    }

    return 0;
}