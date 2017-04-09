/*
Write a program using stream iterators to read a text file
into a vector of strings.
*/
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

int main()
{
    ifstream ifs;
    ifs.open("./chapter10/ex10_29.txt");

    vector<string> vec_s;

    istream_iterator<string> iter_str(ifs);
    istream_iterator<string> eos;

    ifs.close();

    while (iter_str != eos)
    {
        vec_s.push_back(*iter_str++);
    }

    //使用copy函数和back_inserter来实现
    //copy(iter_str,eos,back_inserter(vec_s));

    //testing
    for (string s : vec_s)
    {
        cout << s << endl;
    }

    return 0;
}