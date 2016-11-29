#include <iostream>

class Screen
{
    typedef std::string::size_type pos;

  public:
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' '){};
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c){};

    char get() const { return contents[cursor]; }
    inline char get(pos r, pos c) const;
    Screen &move(pos r, pos c);

  private:
    pos cursor = 0;            //move cursor
    pos height = 0, width = 0; //screen size
    std::string contents;      //screen contents
};

Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}