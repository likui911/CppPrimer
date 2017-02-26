#include <fstream>
#include <iostream>

#include "../chapter07/ex7_26.h"
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::cerr;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);  //输入文件
    ofstream output(argv[2]); //输出文件

    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        while (read(input, trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
    input.close();
    output.close();
    return 0;
}