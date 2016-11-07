#include <iostream>

using namespace std;

int main()
{
    /*
    *While(*cp) judge weather *cp is 0 or not. when *cp is not 0, 
    *it will print the character until 0.
    */
    const char ca[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    //const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while (*cp)
    {
        cout << *cp << endl;
        ++cp;
    }
    return 0;
}