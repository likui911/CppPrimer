/*
*Write a program to find and remove the odd-valued
*elements in a forward_list<int>.
*/
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> fw_i{1, 2, 3, 4, 5, 6, 7, 8, 9};
    forward_list<int>::iterator prev = fw_i.before_begin();
    forward_list<int>::iterator curr = fw_i.begin();
    while (curr != fw_i.end())
    {
        if ((*curr) % 2 != 0)
        {
            curr = fw_i.erase_after(prev); //after erase,prev unchanged
        }
        else
        {
            prev = curr;
            curr++;
        }
    }
    return 0;
}