#include <iostream>
#include <string>

#ifndef EX_7_19_H
#define EX_7_19_H
class Person
{
  public:
    Person() = default;
    Person(std::string &n) : name(n){};
    Person(std::string &n, std::string &s) : address(s){};

  private:
    std::string name;
    std::string address;
};

#endif