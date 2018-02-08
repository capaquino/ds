//
// Created by nad on 1/24/18.
//
#pragma once

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
        (c >= 'a' && c <= 'z'))//||
        //(c >= '0' && c <= '9'))
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

int Evaluate(char c, int a, int b)
{
    if (c == '+')
    {
        return a + b;
    }
    else if (c == '-')
    {
        return a - b;
    }
    else if (c == '*')
    {
        return a * b;
    }
    else if (c == '/')
    {
        return a / b;
    }
    else
    {
        return -9999;
    }
}
