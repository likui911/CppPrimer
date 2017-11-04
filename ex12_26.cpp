/*
Rewrite the program on page 481 using an allocator.
*/
#include <string>
#include <memory>
#include <iostream>
using namespace std;

//page 481
// void fun(size_t n)
// {
//     string *const p = new string[n];
//     string s;
//     string *q = p;
//     while (cin >> s && q !=(p + n))
//         *q++ = s;
//     const size_t size = q - p;
//     delete[] p;
// }

void fun(size_t n)
{
    allocator<string> alloc;
    string *const p = alloc.allocate(n);
    string s;
    string *q = p;
    while (cin >> s && q != (p + n))
        alloc.construct(q++, s);

    for (int i = 0; i < n; ++i)
    {
        alloc.destroy(p + i);
    }
    alloc.deallocate(p, n);
}

int main()
{
    fun(3);
    return 0;
}