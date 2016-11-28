#include <iostream>
#include <string>

#ifndef EX_7_4_H
#define EX_7_4_H
struct Person
{
    Person() = default;
    Person(std::string &n) : name(n){};
    Person(std::string &n, std::string &s) : address(s){};
    
    std::string name;
    std::string address;
};

#endif