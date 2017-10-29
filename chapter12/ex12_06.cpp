/*
Write a function that returns a dynamically allocated
vector of ints. Pass that vector to another function that reads the standard
input to give values to the elements. Pass the vector to another function to
print the values that were read. Remember to delete the vector at the
appropriate time.
*/

#include <vector>
#include <iostream>
using namespace std;

vector<int> *dynamic_vector()
{
    vector<int> *vec_ptr = new vector<int>();
    return vec_ptr;
}

void dynamic_processor(vector<int> *vec_ptr)
{
    int i;
    while (cin >> i)
    {
        vec_ptr->push_back(i);
    }
}

void dynamic_print(vector<int> *vec_ptr)
{
    for (auto i : *vec_ptr)
    {
        cout << i << endl;
    }
}

int main()
{
    vector<int> *vec_ptr = dynamic_vector();
    dynamic_processor(vec_ptr);
    dynamic_print(vec_ptr);
    delete vec_ptr;
    return 0;
}