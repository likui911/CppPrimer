#include "ex7_27.h"
#include <string>

Screen &Screen::move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;
}

Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

Screen &Screen::set(pos r, pos c, char ch)
{
    contents[r * width + c] = ch;
    return *this;
}

const Screen &Screen::display(std::ostream &os) const
{
    os << contents;
    return *this;
}

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";
    myScreen.set(4, 1, '#').display(std::cout);
    std::cout << "\n";

    return 0;
}