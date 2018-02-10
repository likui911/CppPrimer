#include <string>
#include <iostream>

using namespace std;

class Quote
{
  public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price)
    {
    }
    std::string isbn() const
    {
        return bookNo;
    }
    virtual double net_price(std::size_t n) const
    {
        return n * price;
    }
    virtual ~Quote() = default;

  private:
    std::string bookNo;

  protected:
    double price = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() // calls Quote::isbn
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

class Disc_quote : public Quote
{
  public:
    Disc_quote() = default;
    Disc_quote(const string &book, double price, size_t qty, double disc)
        : Quote(book, price), quantity(qty), discount(disc)
    {
    }
    double net_price(size_t n) const = 0;

  protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
  public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double price, size_t qty, double disc)
        : Disc_quote(book, price, qty, disc)
    {
    }

    double net_price(size_t n)const override
    {
        if (n >= quantity)
            return n * (1 - discount) * price;
        else
            return n * price;
    }
};

int main()
{
    Bulk_quote bulk=Bulk_quote("Good",1.2,10,0.2);
    //cannot declare variable 'disc' to be of abstract type 'Disc_quote'
    //ex15_17
    //Disc_quote disc;
    print_total(cout,bulk,5);
    return 0;
}