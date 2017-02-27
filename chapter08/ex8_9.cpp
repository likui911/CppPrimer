/*
* Use the function you wrote for the first exercise in § 8.1.2(p. 314)
* to print the contents of an istringstream object
*/
#include <iostream>
#include <string>
#include <sstream> //include istringstream
using std::cin;
using std::string;
using std::istringstream;

std::istream &read(std::istream &is)
{
    std::string buf;
    while (is >> buf)
    {
        std::cout << buf << std::endl;
    }
    is.clear();
    return is;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        istringstream istr(line);
        read(istr);
    }
    return 0;
}