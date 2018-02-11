#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Quote
{
  public:
    Quote() = default;
    Quote(string const &b, double p) : bookNo(b), price(p) {}
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual ~Quote() = default;

  private:
    string bookNo;

  protected:
    double price = 0.0;
};

class Disc_quote : public Quote
{
  public:
    Disc_quote() = default;
    Disc_quote(string const &b, double p, size_t q, double d) : Quote(b, p), quantity(q), discount(d) {}
    virtual double net_price(size_t) const = 0;

  protected:
    size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
  public:
    using Disc_quote::Disc_quote;
    virtual double net_price(std::size_t cnt) const override
    {
        if (cnt >= quantity)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }
};

double print_total(ostream &os, Quote const &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

int main()
{
    //ex15_28
    {
        vector<Quote> vec;
        Bulk_quote bulk("C++ Primer 5th", 128.0, 5, 0.2);
        cout << bulk.net_price(10) << endl;
        vec.push_back(bulk);
        //调用的其实是Quote的net_price函数
        cout << vec[0].net_price(10) << endl;
    }
    //ex15_29
    {
        vector<shared_ptr<Quote>> vec;
        shared_ptr<Quote> bulk = make_shared<Bulk_quote>("C++ Primer 5th", 128.0, 5, 0.2);
        cout<<bulk->net_price(10)<<endl;
        vec.push_back(bulk);
        cout<<vec[0]->net_price(10)<<endl;
    }
    return 0;
}