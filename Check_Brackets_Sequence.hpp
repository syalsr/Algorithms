#pragma once

#include <stack>
#include <sstream>
#include <optional>

bool check_open_brackets(char c)
{
    return c == '(' || c == '[';
}

bool check_close_brackets(char c)
{
    return c == ')' || c == ']';
}

char reverse_bracket(char c)
{
    if(c == 41)
        return '(';
    else if(c == 40)
        return ')';
    if(c == 93)
        return '[';
    else if(c == 91)
        return ']';

    /*return  (c == '(' ? ')' : '(') ||
            (c == '[' ? ']' : '[');*/
}

std::optional<std::stack<char>> check_brakets_sequence(std::stringstream& ss)
{
    std::stack<char> st;
    char c;
    ss >> c;
    st.push(c);
    while(ss >> c)
    {
        //(())
        if(check_open_brackets(c))
            st.push(c);
        else if(check_close_brackets(c))
        {
            if(!st.empty() && st.top() == reverse_bracket(c))
                st.pop();
            else
                st.push(c);
        }

    }
    if(st.empty())
        return {};
    return st;
}

