/*
Write a program to concatenate two string literals,
putting the result in a dynamically allocated array of char. Write a program
to concatenate two library strings that have the same value as the literals
used in the first program.
*/
#include <cstring>
#include <iostream>
using namespace std;

void fun(const char *str1, const char *str2)
{
    size_t n = strlen(str1) + strlen(str2);
    char *result = new char[n + 1]{'\0'};
    strncat(result, str1, strlen(str1));
    strncat(result, str2, strlen(str2));
    cout << result << endl;
    delete[] result;
}
int main()
{
    fun("hello ", "world");
    string s1{"c++ "};
    string s2{"programming"};
    fun(s1.c_str(),s2.c_str());
    return 0;
}