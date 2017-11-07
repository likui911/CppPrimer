/*
Define an Employee class that contains an employee name
and a unique employee identifier. Give the class a default constructor and
a constructor that takes a string representing the employee’s name. Each
constructor should generate a unique ID by incrementing a static data member
*/
#include <string>
using namespace std;

class Employee
{
  public:
    Employee() : Employee(""){}

    Employee(string n) : name{n}
    {
        static int seria = 1;
        id = seria++;
    }

  private:
    string name;
    int id;
};

int main()
{
    Employee e1;
    Employee e2("kui");
    return 0;
}