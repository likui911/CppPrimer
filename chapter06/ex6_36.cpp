#include <iostream>
#include <string>

using namespace std;

string (&get_string(string (&arr)[10]))[10]
{
    return arr;
}

int main()
{
    string sa[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    cout << get_string(sa)[0][0] << endl;
    return 0;
}