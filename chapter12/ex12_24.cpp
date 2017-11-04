/*
Write a program that reads a string from the standard
input into a dynamically allocated character array. Describe how your
program handles varying size inputs. Test your program by giving it a
string of data that is longer than the array size you’ve allocated.
*/
#include <string>
#include <iostream>

using namespace std;

int main()
{
    cout << ">> number value" << endl;
    int n;
    cin >> n; //字符数目
    char *s = new char[n + 1]{'\0'};
    cin >> s; //输入字符串
    cout << "<<" << s << endl;
    delete[] s;
    return 0;
}