#include <iostream>
template <typename T>
void f1(T lhs, T rhs) {}

template <typename T1, typename T2>
void f2(T1 t1, T2 t2)
{
    ;
}

int main()
{
    int i = 0, j = 42, *p1 = &i, *p2 = &j;
    const int *cp1 = &i, *cp2 = &j; //low-level const
    int *const cp3 = &i;            //top-level const

    //deduced conflicting types for parameter 'T' ('int*' and 'const int*')
    // f1(p1, cp1);

    //top-level const ignored
    f1(p1, cp3);
}