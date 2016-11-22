#include <iostream>

using namespace std;

//argc,the number of strings in the array.
//argv,an array of pointers to C-style character strings.
int main(int argc, char **argv)
{
    string result = "";
    for (int i = 1; i < argc; ++i)
    {
        result += argv[i];
        result += " ";
    }
    cout << result << endl;
    return 0;
}