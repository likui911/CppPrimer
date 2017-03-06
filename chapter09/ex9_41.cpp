/*
Write a program that initializes a string from a
vector<char>.
*/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<char> vec = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    vector<char>::iterator iter = vec.begin();
    //通过vec第一个元素的指针和vec的长度来构造s
    string s = string(&(*iter), vec.size());
    cout << s << endl;
    return 0;
}