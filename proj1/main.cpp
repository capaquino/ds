#include <stack>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <exception>
#include <string>
#include "functions.hpp"

#include <sstream>
#include <vector>
// lambda expressions in c++ begin with [], so [](params) ... C++14
// fn cmd f9 is build
// shift ctrl R is run

int main(int argc, char const *argv[])
{
    std::string input;
    std::getline(std::cin, input);

// Status: Complete

    char prevSymbol;
    std::stack<char> stack;
    std::string postfix = "";
    for (const char symbol : input)
    {
        if (CharIsPoundSign(symbol))
        {
            break;
        }
        else if (CharIsDelimiter(symbol))
        {
            continue;
        }
        else if (CharIsOperand(symbol))
        {
            if (CharIsNumeric(symbol))
            {
                if (CharIsOperator(prevSymbol))
                {
                    postfix += ' ';
                }
                postfix += symbol;
                std::cout << postfix << std::endl;
            }
            else // its an alphabetical character
            {
                postfix += ' ';
                postfix += symbol;
                std::cout << postfix << std::endl;
            }
        }
        else if (CharIsLeftParentheses(symbol))
        {
            stack.push(symbol);
        }
        else if (CharIsRightParentheses(symbol))
        {
            while(!CharIsLeftParentheses(stack.top()))
            {
                postfix += ' ';
                postfix += stack.top();
                std::cout << postfix << std::endl;
                stack.pop();
            }
            stack.pop();
        }
        else if (CharIsOperator(symbol))
        {
            while (!stack.empty() && HasEqualOrGreaterPrecedence(stack.top(), symbol))
            {
                postfix += ' ';
                postfix += stack.top();
                std::cout << postfix << std::endl;
                stack.pop();
            }
            stack.push(symbol);
        }
        else
        {
            postfix += '!';
            std::cout << '!' << std::endl;
        }
        prevSymbol = symbol; // for formatting whitespaces
    }

    while (!stack.empty())
    {
        postfix += ' ';
        postfix += stack.top();
        std::cout << postfix << std::endl;
        stack.pop();
    }

////////////////////////////////////////////////////////////////////////////////

#if 0
    std::string input2;
    std::getline(std::cin, input2);

    // actual numbers need to be grouped and split into valid tokens
    // symbols need to assigned integer values

    std::stack<int> stack2; // should still be able to use functions.hpp on these
    std::string infix = "";

    for (const char symbol : input2)
    {
        if (CharIsDelimiter(symbol))
        {
            continue;
        }
        else if (CharIsOperator(symbol))
        {
            // pop top 2 on stack and evaluate with symbol
            // pop evaluated value back on stack
        }
        else if (CharIsOperand(symbol))
        {
            // convert symbol to int and push to stack
        }
    }
    #endif
    return 0;
}




#if 0
    std::vector<std::string> syms;
    std::string sym;
    std::istringstream tokenStream(input);
    while (std::getline(tokenStream, sym, ' '))
    {
        syms.push_back(sym);
    }

    // vector of string reps of our tokens is now available

    // vector
    // stoi
    // std::foreach
#endif
