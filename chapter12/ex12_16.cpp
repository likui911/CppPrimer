/*
Compilers don’t always give easy-to-understand error
messages if we attempt to copy or assign a unique_ptr. Write a program
that contains these errors to see how your compiler diagnoses them.
*/
#include <memory>
using namespace std;

int main()
{
    unique_ptr<int> pInt1(new int(100));
    /*
    unique_ptr<int> pInt2(pInt1);
    
    error: use of deleted function 
    'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]'
     unique_ptr<int> pInt2(pInt1);                             ^
    */

    return 0;
}