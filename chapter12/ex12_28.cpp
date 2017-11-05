/*
Write a program to implement text queries without
defining classes to manage the data. Your program should take a file and
interact with a user to query for words in that file. Use vector, map, and set
containers to hold the data for the file and to generate the results for the queries
*/
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

using line_no = vector<string>::size_type;

void query(const string &str, vector<string> &file, map<string, set<line_no>> &str_map)
{
    if (str_map.count(str) > 0)
    {
        auto ret = str_map.at(str);
        cout << "elements occurs " << ret.size() << " times" << endl;
        for (auto i : ret)
        {
            cout << "\t"
                 << "(line" << i + 1 << ") " << file[i - 1] << endl;
        }
    }
    else
    {
        cout << "elements " << str << " not exist" << endl;
    }
}

int main()
{
    ifstream ifs{"./chapter09/99.txt"};
    vector<string> file; //text lines context
    string line;
    while (getline(ifs, line))
    {
        file.push_back(line);
    }
    map<string, set<line_no>> str_map;
    for (int i = 0; i < file.size(); ++i)
    {
        stringstream ss{file[i]};
        string s;
        while (ss >> s)
        {
            str_map[s].insert(i + 1);
        }
    }

    cout << "pls input the string you what to query:" << endl;
    string s;
    while (cin >> s)
    {
        query(s, file, str_map);
    }
    return 0;
}