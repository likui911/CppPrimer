#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec_i{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    vector<int>::iterator elm1 = vec_i.begin(), elm2 = elm1 + 2;
    elm1 = vec_i.erase(elm1, elm2);

    //what happens if elem1 and elem2 are equal?
    elm2 = elm1;
    vec_i.erase(elm1, elm2); //不做任何操作
    //What if elem2 or both elem1 and elem2 are the off-the-end iterator?
    vec_i.erase(vec_i.end(), vec_i.end()); //不做操作
    vec_i.erase(elm1, vec_i.end());        //删除elm1后的所有元素

    for (int i : vec_i)
    {
        cout << i << " ";
    }
    return 0;
}