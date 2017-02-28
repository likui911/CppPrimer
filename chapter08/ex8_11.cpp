#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    // read the input a line at a time until cin hits end-of-file (or another error)
    while (getline(cin, line))
    {
        PersonInfo info;
        record.clear();//清空istringstream
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    for (PersonInfo p : people)
    {
        cout << p.name << endl;
    }
    return 0;
}