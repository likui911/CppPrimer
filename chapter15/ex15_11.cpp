/*
Add a virtual debug function to your Quote class hierarchy that displays 
the data members of the respective classes.
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
    virtual void debug()
    {
        cout << bookNo << " # " << price;
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
    double net_price(size_t n) const override
    {
        if (n > max_rst)
        {
            return n * price;
        }
        return (1 - discount) * price * n;
    }
    void debug() override
    {
        Quote::debug();
        cout << " # " << max_rst << " # " << max_rst << " # " << discount;
    }

  private:
    double discount;
    int max_rst;
};

int main()
{
    Quote q1("abc", 10);
    q1.debug();
    cout << endl;
    LimitQuote q2("abc", 10, 10, 0.3);
    q2.debug();
    return 0;
}