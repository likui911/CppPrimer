/*
A letter has an ascender if, as with d or f, part of the
letter extends above the middle of the line. A letter has a descender if, as
with p or g, part of the letter extends below the line. Write a program that
reads a file containing words and reports the longest word that contains
neither ascenders nor descenders.


*/
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    ifstream ifs("./chapter09/99.txt");
    if (!ifs)
        return -1;

    string word, longest;
    while (ifs >> word)
    {
        if (word.find_first_not_of("aceimnorsuvwxyz") == string::npos &&
            word.size() > longest.size())
        {
            longest = word;
        }
    }
    cout << longest;

    return 0;
}