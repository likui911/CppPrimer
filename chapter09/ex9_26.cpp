/*
Using the following definition of ia, copy ia into a vector
and into a list. Use the single-iterator form of erase to remove the
elements with odd values from your list and the even values from your
vector.
*/
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> vec_i(begin(ia), end(ia));
    list<int> lis_i(begin(ia), end(ia));

    vector<int>::iterator vbeg = vec_i.begin(), vend = vec_i.end();
    list<int>::iterator lbeg = lis_i.begin(), lend = lis_i.end();

    //remove even elements from vector<int>
    while (vbeg != vend)
    {
        if ((*vbeg) % 2 == 0)
            vbeg = vec_i.erase(vbeg);
        else
            ++vbeg;
    }

    //remove odd elements from list<int>
    while (lbeg != lend)
    {
        if ((*lbeg) % 2 != 0)
            lbeg = lis_i.erase(lbeg);
        else
            ++lbeg;
    }
    //testing output
    for (int i : vec_i)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i : lis_i)
    {
        cout << i << " ";
    }
    return 0;
}