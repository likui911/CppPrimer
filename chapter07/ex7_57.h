#include <iostream>

#ifdef EX7_57_H
#define EX7_57_H
class Account
{
  public:
    void caculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);

  private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
};

void Account::rate(double newRate)
{
    interestRate = newRate;
}
double Account::initRate()
{
    return 42.3;
}
double Account::interestRate = initRate();

#endif // !EX7_57_H