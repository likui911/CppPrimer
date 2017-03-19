/*
Use a stack to process parenthesized expressions. When
you see an open parenthesis, note that it was seen. When you see a close
parenthesis after an open parenthesis, pop elements down to and including
the open parenthesis off the stack. push a value onto the stack to indicate
that a parenthesized expression was replaced.
*/

#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    auto &expr = "This is (ooophy(awome)((((wooooo))))) and (ocxs) over";
    auto repl = '#';
    auto seen = 0;

    stack<char> stk;

    for (auto c : expr)
    {
        stk.push(c);
        //遇到(seen加1
        if (c == '(')
            ++seen;
        //遇到)seen减1的同时将两者之间的字符pop
        if (c == ')')
        {
            while (seen && stk.top() != '(')
            {
                stk.pop();
            }
            stk.pop();//将(字符pop
            stk.push(repl);//插入repl字符
            --seen;
        }
    }
    string temp;
    for (; !stk.empty(); stk.pop())
    {
        temp.insert(temp.begin(),stk.top());
    }
    cout<<temp;

    return 0;
}