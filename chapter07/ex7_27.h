#include <iostream>
#include <string>

#ifndef EX7_27_H
#define EX7_27_H
class Screen
{
  typedef std::string::size_type pos;

public:
  Screen() = default;
  Screen(pos wd, pos hd, char c) : width(wd), height(hd), contents(wd * hd, c){};

  Screen &move(pos r, pos c);
  Screen &set(char c);
  Screen &set(pos r, pos c, char ch);
  const Screen &display(std::ostream &os) const;

private:
  pos cursor = 0;
  pos width = 0, height = 0;
  std::string contents;
};
#endif // EX7_27_H
