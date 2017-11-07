#include <string>
using namespace std;

class Employee
{
  public:
    Employee() : Employee("") {}

    Employee(string n) : name{n}
    {
        id = incr_seria();
    }

    Employee(const Employee &e)
    {
        name = e.name;
        id = incr_seria();
    }

  private:
    int incr_seria()
    {
        static int seria = 1;
        return seria++;
    }
    static int seria;
    string name;
    int id;
};

int main()
{
    Employee e1("kui");
    Employee e2(e1);
    Employee e3;
    return 0;
}