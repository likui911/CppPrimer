/*
Rewrite the word-counting program from § 11.1 (p. 421)
to use insert instead of subscripting. Which program do you think is easier
to write and read? Explain your reasoning.
*/
#include <map>
#include <iostream>
#include <utility>

using namespace std;

int main()
{
    // count the number of times each word occurs in the input
    map<string, size_t> word_count; // empty map from string to size_t
    string word;
    while (cin >> word)
    {
        pair<map<string, size_t>::iterator, bool> ret = word_count.insert(make_pair(word, 1));
        if (!ret.second)
        {
            //typedef pair<const Key, T> value_type;
            //iterator	a bidirectional iterator to value_type
            ++(ret.first->second);
        }
    }

    for (const auto &w : word_count) // for each element in the map
        // print the results
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;
}