#include <iostream>
#include <string>

#ifndef EX_7_22_H
#define EX_7_22_H

/*
* hide the Person’s implementation
*/
class Person
{
  public:
    Person() = default;
    Person(std::string &n) : name(n){};
    Person(std::string &n, std::string &s) : address(s){};
    Person(std::istream &is) { read(is, *this); };

    std::string getName() { return name; };
    std::string getAddress() { return address; };

    std::istream &read(std::istream &is, Person &p);
    std::ostream &print(std::ostream &os, Person &p);

  private:
    std::string name;
    std::string address;
};

std::istream &Person::read(std::istream &is, Person &p)
{
    is >> p.name >> p.address;
    return is;
}

std::ostream &Person::print(std::ostream &os, Person &p)
{
    os << p.name << "" << p.address << std::endl;
    return os;
}
#endif