#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool valid(const string &num)
{
    if (num.length() != 6)
        return false;
    
    for (auto c : num)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

string format(const string &num)
{

    return num.substr(0, 3) + "-" + num.substr(3, 5);
}

int main()
{
    ifstream in_file("./chapter08/record.txt");
    ofstream out_file("./chapter08/record_out.txt");
    if (!in_file)
    {
        cerr << "read file error" << endl;
        return -1;
    }

    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    // read the input a line at a time until cin hits end-of-file (or another error)
    while (getline(in_file, line))
    {
        PersonInfo info;
        record.clear(); //清空istringstream
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    //validate and reformat the phone numbers
    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones)
        {
            if (!valid(nums))
            {
                badNums << " " << nums;
            }
            else
            {
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty())
        {
            out_file << entry.name << " " << formatted.str() << endl;
        }
        else
        {
            cerr << "input error: " << entry.name << " invalid nums:" << badNums.str() << endl;
        }
    }
    return 0;
}