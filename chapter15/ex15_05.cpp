/*
Define your own version of the Bulk_quote class
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

class BulkQuote : public Quote
{
  public:
    BulkQuote() = default;
    BulkQuote(const string &book, double p, size_t qty, double disc)
        : Quote(book, p), min_qty(qty), discount(disc){};
    double net_price(std::size_t n) const override;

  private:
    size_t min_qty;
    double discount;
};

double BulkQuote::net_price(size_t n) const
{
    if (n > min_qty)
    {
        return n * (1 - discount) * price;
    }
    return n * price;
}

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() // calls Quote::isbn
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

int main()
{
    Quote q("abc", 10);
    print_total(cout, q, 10);
    BulkQuote b("def", 10, 5, 0.3);
    print_total(cout, b, 10);
    return 0;
}