// Write a program to store each line from a file in a
// vector<string>. Now use an istringstream to read each element from the
// vector a word at a time.
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

using std::istringstream;
using std::ifstream;
using std::string;
using std::vector;

int main()
{
    ifstream in_file("./chapter08/00.txt");
    vector<string> vec_s;
    string line;
    if (in_file)
    {
        while (getline(in_file, line))
        {
            //storage each line in vector<string>
            vec_s.push_back(line);
        }
    }

    for (string line : vec_s)
    {
        istringstream iss(line);
        string word;
        while (iss >> word)
        {
            //read each element from the vector<string>
            std::cout << word << std::endl;
        }
    }
    in_file.close();
    return 0;
}