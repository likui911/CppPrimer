#include <iostream>
#include <string>

#ifndef EX_7_8_H
#define EX_7_8_H

struct Person
{
    std::string name;
    std::string address;
};

// nonmember functions
std::istream &read(std::istream &is, Person &p)
{
    is >> p.name >> p.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &p)
{
    os << p.name << " " << p.address << std::endl;
    return os;
}

#endif // !EX_7_8_H
