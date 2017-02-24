#include <iostream>

std::istream &read(std::istream &is)
{
    std::string buf;
    while (is >> buf)
    {
        std::cout << buf << std::endl;
    }
    is.clear();
    return is;
}

int main()
{
    std::istream &is = read(std::cin);
    //得到istream状态
    std::cout<<is.rdstate()<<std::endl;
    return 0;
}