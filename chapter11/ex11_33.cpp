/*
Implement your own version of the word-transformation program.

If the contents of the word-transformation file are
    brb be right back
    k okay?
    y why
    r are
    u you
    pic picture
    thk thanks!
    l8r later
and the text we are given to transform is
    where r u
    y dont u send me a pic
    k thk l8r
then the program should generate the following output:
    where are you
    why dont you send me a picture
    okay? thanks! later
*/
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <iterator>

using namespace std;

const string &transform(const string &s, const map<string, string> &m)
{
    stringstream ss{s};
    string word;
    bool isBegin = true;
    while (ss >> word)
    {
        if (isBegin)
            isBegin = false;
        else
            cout << " ";

        auto iter = m.find(word);
        if (iter != m.end())
            cout << iter->second;
        else
            cout << word;
    }
}

int main()
{
    map<string, string> mapped{
        {"brb", "be right back"},
        {"k", "okay?"},
        {"y", "why"},
        {"r", "are"},
        {"u", "you"},
        {"pic", "picture"},
        {"thk", "thanks!"},
        {"l8r", "later"}};

    string src{"where r u\ny dont u send me a pic\nk thk l8r\n"};
    stringstream ss{src};
    string line;
    while (getline(ss, line))
    {
        cout << transform(line, mapped) << endl;
    }

    return 0;
}