/*
Write a class like PrintString that reads a line of input
from an istream and returns a string representing what was read. If the
read fails, return the empty string.
*/
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
class ReadInput
{
  public:
    ReadInput(istream &is = cin) : ss(is) {}

    string operator()()
    {
        string line;
        getline(ss, line);
        return line;
    }

  private:
    istream &ss;
};

int main()
{
    vector<string> vec;
    ifstream ifs("./chapter14/ex14_35.cpp");
    ReadInput is(ifs);
    for (string tmp; !(tmp = is()).empty();)
    {
        vec.push_back(tmp);
    }
    for (auto s : vec)
    {
        cout << s << endl;
    }
    return 0;
}