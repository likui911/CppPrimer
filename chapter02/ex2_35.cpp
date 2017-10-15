/*
Determine the types deduced in each of the following
definitions. Once you’ve figured out the types, write a program to see
whether you were correct.
*/

int main()
{
    const int i = 42;
    auto j = i;        //int
    const auto &k = i; //const int&
    auto *p = &i;      //const int*
    //addtion
    auto p1 = &i;              //const int*
    const auto j2 = i, &k2 = i; //const int,int&
    return 0;
}