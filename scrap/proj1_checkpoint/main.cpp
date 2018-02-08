#include <stack>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <exception>

#include "functions.hpp"

// lambda expressions in c++ begin with [], so [](params) ... C++14
// fn cmd f9 is build
// shift ctrl R is run

// note: need delimiters and # to mark end, also see project sheet

int main(int argc, char const *argv[])
{
    std::ifstream input;
    input.open("input");
    if (!input)
    {
        std::cout << "Failed to open input file or input file not found." << std::endl;
        exit(1);
    }
    std::stack<char> stack;
    std::string postfix = "";
    char symbol;
    while(input >> symbol && !CharIsPoundSign(symbol))
    {
        if (CharIsDelimiter(symbol))
        {
            continue;
        }
        else if (CharIsOperand(symbol))
        {
            postfix += symbol;
            std::cout << postfix << std::endl;
        }
        else if (CharIsLeftParentheses(symbol))
        {
            stack.push(symbol);
        }
        else if (CharIsRightParentheses(symbol))
        {
            while(!CharIsLeftParentheses(stack.top()))
            {
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
    }

    while (!stack.empty())
    {
        postfix += stack.top();
        std::cout << postfix << std::endl;
        stack.pop();
    }

    input.close();

////////////////////////////////////////////////////////////////////////////////
#if 0
    std::ifstream input2;
    input2.open("input2");
    if (!input2)
    {
        std::cout << "Failed to open input file or input file not found." << std::endl;
        exit(1);
    }

    std::stack<int> stack2;
    std::string infix = "";
    char symbol2;
    // eventually need to ask user for value of symbols and parse

    // assume at this point that the values have been parsed.
    while(input2 >> symbol2 && !CharIsPoundSign(symbol2))
    {
        if (CharIsDelimiter(symbol2))
        {
            continue;
        }
        else if (CharIsOperator(symbol2))
        {
            // pop top 2 on stack and evaluate with symbol
            // pop evaluated value back on stack
        }
        else if (CharIsOperand(symbol2))
        {
            // convert symbol to int and push to stack
        }




    }

#endif
    return 0;
}
