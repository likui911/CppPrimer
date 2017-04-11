/*
Write a program that takes the names of an input file
and two output files. The input file should hold integers. Using an
istream_iterator read the input file. Using ostream_iterators, write the odd
numbers into the first output file. Each value should be followed by a
space. Write the even numbers into the second file. Each of these values
should be placed on a separate line.
*/

#include <fstream>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ifstream ifs("./chapter10/in_file.txt");
    ofstream ofs_odd("./chapter10/out_odd.txt"), ofs_even("./chapter10/out_even.txt");

    istream_iterator<int> iss(ifs), eof;
    ostream_iterator<int> out_odd(ofs_odd, " "), out_even(ofs_even, " ");

    //遍历每一个值，如果是偶数调用out_even
    //如果是奇数，调用out_odd
    for_each(iss, eof, [&out_odd, &out_even](const int i) {
        *(((i % 2 == 0) ? out_even : out_odd)++) = i;
    });

    return 0;
}