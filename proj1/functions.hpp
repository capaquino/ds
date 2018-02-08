//
// Created by nad on 1/24/18.
//
#pragma once

#include <string>

bool CharIsDelimiter(char c)
{
    if (c == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CharIsPoundSign(char c)
{
    if (c == '#')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CharIsOperand(char c)
{
    if ((c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CharIsOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    else
    {
        return false;
    }

}

int GetPriority(char c)
{
    switch (c)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
    }
    return -1;
}

bool HasEqualOrGreaterPrecedence(char first, char second)
{
    if (GetPriority(first) >= GetPriority(second))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CharIsLeftParentheses(char c)
{
    if (c == '(' )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CharIsRightParentheses(char c)
{
    if (c == ')' )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CharIsNumeric(char c)
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CharIsAlpha(char c)
{
    if ((c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool StringIsSymbol(std::string s)
{
    for (const char c : s)
    {
        if (!CharIsAlpha(c))
        {
            return false;
        }
    }
    return true;
}

bool StringIsNumeric(std::string s)
{
    for (const char c : s)
    {
        if (!CharIsNumeric(c))
        {
            return false;
        }
    }
    return true;
}

bool StringIsOperator(std::string s)
{
    for (const char c : s)
    {
        if (!CharIsOperator(c))
        {
            return false;
        }
    }
    return true;
}

bool StringIsOperand(std::string s)
{
    for (const char c : s)
    {
        if (!CharIsOperand(c))
        {
            return false;
        }
    }
    return true;
}

int Evaluate(std::string s, int a, int b)
{
    if (s == "+")
    {
        return a + b;
    }
    else if (s == "-")
    {
        return a - b;
    }
    else if (s == "*")
    {
        return a * b;
    }
    else if (s == "/")
    {
        return a / b;
    }
    else
    {
        return -9999;
    }
}
