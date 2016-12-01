#include <iostream>
#include <string>

int height;
class Screen
{
  public:
    typedef std::string::size_type pos;
    void setHeight(pos);
    pos height = 0;
    //typedef std::string::size_type pos;
};
Screen::pos verify(Screen::pos);

void Screen::setHeight(pos var)
{
    height = verify(var);
}