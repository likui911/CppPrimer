/*
Exercise 15.7: Define a class that implements a limited discount strategy,
which applies a discount to books purchased up to a given limit. If the
number of copies exceeds that limit, the normal price applies to those
purchased beyond the limit
*/

#include <string>
#include <iostream>
using namespace std;

class Quote
{
  public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
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

class LimitQuote : public Quote
{
  public:
    LimitQuote() = default;
    LimitQuote(const string &book, double s_price, int rest, double disc)
        : Quote(book, s_price), max_rst(rest), discount(disc) {}
    double net_price(size_t n) const override;

  private:
    double discount;
    int max_rst;
};

double LimitQuote::net_price(size_t n) const
{
    if (n > max_rst)
    {
        //超出的部分按照原价出售
        return (n - max_rst) * price + max_rst * (1 - discount) * price;
    }
    return (1 - discount) * price * n;
}

void print_total(ostream &os, const Quote &item, size_t n)
{
    os << item.isbn() << " # " << item.net_price(n) << endl;
}

int main()
{
    LimitQuote l1("c++ primer", 10, 5, 0.3);
    print_total(cout, l1, 5);
    print_total(cout, l1, 10);
    return 0;
}