/*
How many destructor calls occur in the following code fragment?
    bool fcn(const Sales_data *trans, Sales_data accum)
    {
        Sales_data item1(*trans), item2(accum);
        return item1.isbn() != item2.isbn();
    }
*/
#include <iostream>
using namespace std;

class Sales_data
{
  public:
    Sales_data() {}
    ~Sales_data() { cout << "~Sales_data" << endl; }
    int isbn() const { return i; };

  private:
    int i;
};

bool fcn(const Sales_data *trans, Sales_data accum)
{
    //item1 item2 's destructor
    //temporary accum 's destructor
    Sales_data item1(*trans), item2(accum);
    return item1.isbn() != item2.isbn();
}

int main()
{
    Sales_data s1, s2;
    if (fcn(&s1, s2))
    {
        cout << "process end" << endl;
    }
    return 0;
}