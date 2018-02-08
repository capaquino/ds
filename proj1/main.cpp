#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

#include "functions.hpp"

int main()
{

    /*** Get infix expression from user ***/
    std::string input;
    std::getline(std::cin, input);

    // Parse, based on the ' ' and place separated string tokens into vector.
    std::istringstream tokenStream(input);
    std::vector<std::string> tokens;
    std::string token;
    while (std::getline(tokenStream, token, ' '))
    {
        tokens.push_back(token);
    }

    /*** Convert to postfix ***/
    std::stack<std::string> stack;
    std::vector<std::string> postfix;
    for (const std::string symbol : tokens)
    {
        if (StringIsPoundSign(symbol))
        {
            break;
        }
        else if (StringIsOperand(symbol))
        {
            postfix.push_back(symbol);
        }
        else if (StringIsLeftParentheses(symbol))
        {
            stack.push(symbol);
        }
        else if (StringIsRightParentheses(symbol))
        {
            while (!StringIsLeftParentheses(stack.top()))
            {
                postfix.push_back(stack.top());
                stack.pop();
            }
            stack.pop();
        }
        else if (StringIsOperator(symbol))
        {
            while (!stack.empty() && StringHasEqualOrGreaterPrecedence(stack.top(), symbol))
            {
                postfix.push_back(stack.top());
                stack.pop();
            }
            stack.push(symbol);
        }
        else
        {
            postfix.push_back("ERROR");
        }
    }

    // Empty what remains in the stack to complete the postfix expression
    while (!stack.empty())
    {
        postfix.push_back(stack.top());
        stack.pop();
    }

    /*** Print postfix to console ***/
    for (const std::string p : postfix)
    {
        std::cout << p << " ";
    }
    std::cout << std::endl;

////////////////////////////////////////////////////////////////////////////////

    /*** Map string tokens to integer values ***/
    std::map<std::string, int> tokenValueMap;
    for (const std::string currentToken : postfix)
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

    /*** Print out token : int value dictionary ***/
    std::cout << std::endl;
    for (std::string t : postfix)
    {
        if (!StringIsOperator(t))
        {
            std::cout << t << " : " << tokenValueMap[t] << std::endl;
        }
    }
    std::cout << std::endl;



    /*** Evaluate string ***/
    std::stack<int> intStack;

    for (const std::string currentToken : postfix)
    {
        if (StringIsOperand(currentToken))
        {   // fetch dictionary value and put on int stack
            intStack.push(tokenValueMap[currentToken]);
        }
        else if (StringIsOperator(currentToken))
        {   // pop top 2 on stack and evaluate symbol
            // pop evaluated value back on stack.
            int op1 = intStack.top();
            intStack.pop();
            int op2 = intStack.top();
            intStack.pop();
            intStack.push(Evaluate(currentToken, op2, op1)); // order matters.
        }
        else
        {
            std::cout << "Unexpected behavior." << std::endl;
        }
    }

    /*** Print out what the expression evaluates to ***/
    std::cout << "The expression evaluates to " << intStack.top() << "." << std::endl;

////////////////////////////////////////////////////////////////////////////////

    return 0;
}
