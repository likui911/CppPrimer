#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void readToVect(const string &fileName, vector<string> &context)
{
    ifstream ifs(fileName);
    if (ifs)
    {
        string buf;
        while (getline(ifs, buf))
        {
            context.push_back(buf);
        }
    }
}

int main()
{
    string file_name = "D:\\Source\\CppPrimer\\chapter08\\00.txt";
    vector<string> context;
    readToVect(file_name, context);
    for (string s : context)
    {
        cout << s << endl;
    }
    return 0;
}