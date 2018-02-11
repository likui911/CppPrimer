#include <iostream>
#include <string>
#include <memory>
#include <set>

using namespace std;

class Quote
{
  public:
    Quote() = default;
    Quote(string const &b, double p)
        : bookNo(b), price(p)
    {
    }
    //&引用限定符，左值
    //&&引用限定符，右值
    virtual Quote *clone() const &
    {
        return new Quote(*this);
    }
    virtual Quote *clone() &&
    {
        return new Quote(std::move(*this));
    }

    string isbn() const
    {
        return bookNo;
    }

    virtual double net_price(size_t n) const
    {
        return n * price;
    }
    virtual ~Quote() = default;

  private:
    string bookNo;

  protected:
    double price = 0.0;
};

class Bulk_quote : public Quote
{
  public:
    Bulk_quote() = default;
    Bulk_quote(string const &b, double p, size_t q, double d)
        : Quote(b, p), quantity(q), discount(d)
    {
    }
    virtual Bulk_quote *clone() const & override
    {
        return new Bulk_quote(*this);
    }
    virtual Bulk_quote *clone() && override
    {
        return new Bulk_quote(std::move(*this));
    }
    virtual double net_price(size_t cnt) const override
    {
        if (cnt >= quantity)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }

  protected:
    size_t quantity = 0;
    double discount = 0.0;
};

double print_total(ostream &os, Quote const &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

class Basket
{
  public:
    void addItem(const Quote &sale)
    {
        items.insert(shared_ptr<Quote>(sale.clone()));
    }
    void addItem(Quote &&sale)
    {
        items.insert(shared_ptr<Quote>(std::move(sale).clone()));
    }
    double total_receipt(std::ostream &os) const
    {
        double sum = 0.0;
        for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
        {
            sum += print_total(os, **iter, items.count(*iter));
        }
        os << "Total Sale: " << sum << endl;
        return sum;
    }

  private:
    static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() > rhs->isbn();
    }
    multiset<shared_ptr<Quote>, decltype(compare) *> items{compare};
};

int main()
{   
    Quote quote("computer",121);
    Bulk_quote bulk("C++",121.8,10,0.3);
    Basket basket;
    basket.addItem(quote);
    basket.addItem(bulk);
    basket.total_receipt(cout);

    return 0;
}