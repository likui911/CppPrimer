#include <iostream>
#include <string>
#include <vector>

#ifndef EX7_32_H
#define EX7_32_H

class Screen
{
    typedef std::string::size_type pos;
    friend class Window_mgr;

  public:
    Screen() = default;
    Screen(pos w, pos h) : width(w), height(h), contents(w * h, ' '){};
    Screen(pos w, pos h, char c) : width(w), height(h), contents(w * h, c){};

    Screen &move(pos r, pos c);
    Screen &set(char ch);
    Screen &set(pos r, pos c, char ch);
    void display(std::ostream &os) { os << contents; };

  private:
    pos cursor = 0;
    pos width = 0, height = 0;
    std::string contents;
};

class Window_mgr
{
  public:
    typedef std::vector<Screen>::size_type Screen_index;
    void clear(Screen_index);

  private:
    std::vector<Screen> screens{Screen(40, 80)};
};
#endif // !EX7_32_H

Screen &Screen::move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;
};

Screen &Screen::set(char ch)
{
    contents[cursor] = ch;
    return *this;
};
Screen &Screen::set(pos r, pos c, char ch)
{
    cursor = r * width + c;
    contents[cursor] = ch;
    return *this;
}

void Window_mgr::clear(Screen_index i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.width * s.height, ' ');
}