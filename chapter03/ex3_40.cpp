#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const char *str1 = "Hello";
    const char *str2 = "World";

    //constexpr 定义size问题
    char str3[80];

    strcpy(str3, str1);
    strcat(str3, str2);
    cout << str3 << endl;
    return 0;
}