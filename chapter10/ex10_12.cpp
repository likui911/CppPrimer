/*
Write a function named compareIsbn that compares the
isbn() members of two Sales_data objects. Use that function to sort a
vector that holds Sales_data objects.
*/
#include "../chapter07/ex7_21.h"
#include <vector>
#include <algorithm>

using namespace std;

bool compareIsbn(const Sales_data &sd1,const Sales_data &sd2)
{
    return sd1.isbn()<sd2.isbn();
}

int main()
{
    Sales_data s1("abc"),s2("def"),s3("efg");
    vector<Sales_data> vec{s3,s2,s1};
    sort(vec.begin(),vec.end(),compareIsbn);
    for(auto s:vec)
    {
        cout<<s.isbn()<<endl;
    }
    return 0;
}