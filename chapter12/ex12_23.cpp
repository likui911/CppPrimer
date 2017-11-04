/*
Write a program to concatenate two string literals,
putting the result in a dynamically allocated array of char. Write a program
to concatenate two library strings that have the same value as the literals
used in the first program.
*/
#include <cstring>

void concatenate(const char *str1, const char *str2)
{
    size_t n = strlen(str1) + strlen(str2);
    char *result = new char[n + 1];
    
}
int main()
{

    return 0;
}