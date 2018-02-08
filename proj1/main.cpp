#include <cstdio>
#include <string>
#include <vector>
#include <stack>

#include "functions.hpp"

int main()
{
    std::vector<std::string> postfix;
    bool f_postfixAvailable = false;
    std::string input;
    char selection;

    do {
        std::cout << std::endl << "============ Menu ============";
        std::cout << std::endl;
        std::cout << std::endl << " (1) Convert Infix to Postfix ";
        std::cout << std::endl << " (2) Evaluate Expression      ";
        std::cout << std::endl << " (3) Exit                     ";
        std::cout << std::endl;
        std::cout << std::endl << "==============================";
        std::cout << std::endl << "Enter a selection and press <enter>.";
        std::cout << std::endl << "> ";

        getline(std::cin, input);
        selection = input.at(0);

        if (selection == '1')
        {
            postfix = InfixToPostfix();
            if (!f_postfixAvailable)
            {
                f_postfixAvailable = true;
            }
        }

        else if (selection == '2')
        {
            if (f_postfixAvailable)
            {
                EvaluatePostfix(postfix);
            }
            else
            {
                std::cout << std::endl << "Postfix expression unavailable, "
                    "press <1> to convert your infix expression to postfix. "
                    "Then, press <2> to evaluate that postfix expression."
                    << std::endl;
            }
        }
        else if (selection == '3')
        {
            std::cout << std::endl << "Exiting..." << std::endl;
        }
        else
        {
            std::cout << std::endl << "In valid selection, enter <1>, <2>, or "
                "<3>, then press <enter>." << std::endl;
        }

    } while(selection != '3');

    return 0;
}
