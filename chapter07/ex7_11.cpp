#include "ex7_11.h"

using namespace std;

int main()
{
    Sales_data s1=Sales_data();
    Sales_data s2=Sales_data("C++ Primer");
    Sales_data s3=Sales_data("C++ Primer",2,23.5);
    
    print(cout,s1);
    print(cout,s2);
    print(cout,s3);

    return 0;
}