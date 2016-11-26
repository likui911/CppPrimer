#include <iostream>
#include <string>

#ifndef EX_7_5_H
#define EX_7_5_H
struct Person
{
    std::string name;
    std::string address;

    const std::string getName() const { return name; }
    const std::string getAddress() const { return address; }
};
#endif