#include <iostream>
#include <string>

using namespace std;

class Quote
{
  public:
    Quote()
    {
        cout << "Quote Constructor" << endl;
    }
    Quote(const Quote &)
    {
        cout << "Quote Copy Constructor" << endl;
    }
    ~Quote()
    {
        cout << "Quote Destructor" << endl;
    }
};

class Bulk_quote : public Quote
{
  public:
    Bulk_quote()
    {
        //首先会调用基类Quote的默认构造函数
        cout << "Bulk_quote Constructor" << endl;
    }
    Bulk_quote(const Bulk_quote &bulk) : Quote(bulk)
    {
        //先调用父类Quote的拷贝构造函数
        cout << "Bulk_quote Copy Constructor" << endl;
    }
    ~Bulk_quote()
    {
        //执行完此析构函数后再调用Quote的析构函数
        cout << "Bulk_quote Destructor" << endl;
    }
};

int main()
{
    {
        Bulk_quote bulk;
        Bulk_quote bulk1(bulk);
    }

    return 0;
}