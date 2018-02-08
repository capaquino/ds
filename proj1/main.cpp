#include <stack>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <exception>
#include <string>
#include "functions.hpp"

#include <sstream>
#include <vector>
#include <map>
// lambda expressions in c++ begin with [], so [](params) ... C++14
// fn cmd f9 is build
// shift ctrl R is run

int main(int argc, char const *argv[])
{
    #if 0
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
#endif
////////////////////////////////////////////////////////////////////////////////

// symbol: variable
// Numeric: 0-9
// Alpha : A-Z or a-z
// Token : Value after string split

    // actually need infix, convert to postfix, then evaluate.
    std::string postfixInput;
    std::getline(std::cin, postfixInput);

    std::istringstream tokenStream(postfixInput);
    std::vector<std::string> tokens;
    std::string token;
    while (std::getline(tokenStream, token, ' '))
    {
        tokens.push_back(token);
    }

    // determine symbols
    std::map<std::string, int> tokenValueMap;

    for (const std::string currentToken : tokens)
    {
        if (StringIsSymbol(currentToken)) // if its a symbol we need user value
        {
            std::cout << "What is the value of " << currentToken << "?" << std::endl;
            std::string integerTextInput;
            std::getline(std::cin, integerTextInput);

            if (StringIsNumeric(integerTextInput)) // validate user input is a number
            {
                int tokenValue =  std::stoi(integerTextInput);
                tokenValueMap[currentToken] = tokenValue;
                std::cout << currentToken << "'s value was saved." << std::endl;
            }
            else // if user input was invalid, can try restarting: currentToken = prevToken.
            {
                std::cout << "Input must only contain numeric characters" << std::endl;
            }
        }
        else if (StringIsNumeric(currentToken)) // if already a number, don't ask.
        {
            // add to int vector
            int tokenValue =  std::stoi(currentToken);
            tokenValueMap[currentToken] = tokenValue;
        }
        else if (StringIsOperator(currentToken)) // don't do anything
        {
            continue;
        }
        else // i dont think we need to evaluate the # sign... if so, add else if for it.
        {
            std::cout << "Token was not valid. Exiting program..." << std::endl;
            return 1;
        }
    }

    // Print out token : int value dictionary
    std::cout << std::endl;
    for (std::string t : tokens)
    {
        if (!StringIsOperator(t))
        {
            std::cout << t << " : " << tokenValueMap[t] << std::endl;
        }
    }
    std::cout << std::endl;



    // Evaluate string
    std::stack<int> intStack;

    for (const std::string currentToken : tokens)
    {
        if (StringIsOperand(currentToken))
        {
            // fetch dictionary value and put on int stack
            intStack.push(tokenValueMap[currentToken]);
        }
        else if (StringIsOperator(currentToken))
        {
            int op1 = intStack.top();
            intStack.pop();
            int op2 = intStack.top();
            intStack.pop();
            intStack.push(Evaluate(currentToken, op2, op1)); // order matters.
            // pop top 2 on stack and evaluate symbol
            // pop evaluated value back on stack.
        }
        else
        {
            std::cout << "Unexpected behavior." << std::endl;
        }
    }

    std::cout << "The expression evaluates to " << intStack.top() << "." << std::endl;


#if 0
    std::stack<int> stack2; // should still be able to use functions.hpp on these
    std::string infix = "";

    for (const char symbol : postfixInput)
    {
        if (CharIsOperator(symbol))
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
////////////////////////////////////////////////////////////////////////////////

    return 0;
}




#if 0
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(input);
    while (std::getline(tokenStream, token, ' '))
    {
        tokens.push_back(token);
    }

    // vector of string reps of our tokens is now available

    // vector
    // stoi
    // std::foreach
#endif
