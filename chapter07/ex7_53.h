#include <iostream>

#ifdef EX_7_53_H
#define EX_7_53_H

class Debug
{
  public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
    constexpr Debug(bool b, bool i, bool o) : hw(b), io(i), other(o) {}
    constexpr any() { return hw || io || other; }

    void set_hw(bool b) { hw = b; }
    void set_io(bool b) { io = b; }
    void set_other(bool b) { other = b; }

  private:
    bool hw; //hardware errors
    bool io; //io errors
    bool other;
};
#endif