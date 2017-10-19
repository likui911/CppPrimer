/*
Write the type of map_it from the loop on page 430
without using auto or decltype.
*/
#include <map>
#include <iostream>

using namespace std;

int main()
{
    map<string, size_t> word_count;
    // get an iterator positioned on the first element
    map<string, size_t>::const_iterator map_it = word_count.cbegin();
    // compare the current iterator to the off-the-end iterator
    while (map_it != word_count.cend())
    {
        // dereference the iterator to print the element key--value pairs
        cout << map_it->first << " occurs "
             << map_it->second << " times" << endl;
        ++map_it; // increment the iterator to denote the next element
    }
}