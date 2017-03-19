/*
Rewrite exercise 10.12 from § 10.3.1 (p. 387) to use a
lambda in the call to sort instead of the compareIsbn function.
*/
#include "../chapter07/ex7_21.h"
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    Sales_data s1("abc"),s2("def"),s3("efg");
    vector<Sales_data> vec{s3,s2,s1};
    sort(vec.begin(),vec.end(),[](const Sales_data &sd1,const Sales_data &sd2){return sd1.isbn()<sd2.isbn();});
    for(auto s:vec)
    {
        cout<<s.isbn()<<endl;
    }
    return 0;
}