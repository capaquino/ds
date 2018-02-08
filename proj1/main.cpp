#include <cstdio>
#include <string>
#include <vector>
#include <stack>

#include "functions.hpp"

char getInput() // kinda garbage
{
	int value = 0;
	std::cin >> value;

	bool badValue = std::cin.fail() == 1;

	while (badValue)
	{
		std::cin.clear();
		std::cin.ignore(250, '\n');
		std::cin >> value;
		badValue = std::cin.fail() == 1;
	}
	std::cin.get();
	return value;
}

int main()
{
    std::vector<std::string> postfix;
    bool PostfixAvailable = false;
    char selection;

    do {
        std::cout << std::endl << "============ Menu ============";
        std::cout << std::endl;
        std::cout << std::endl << " (1) Convert Infix to Postfix ";
        std::cout << std::endl << " (2) Evaluate Expression      ";
        std::cout << std::endl << " (3) Exit                     " << std::endl;
        std::cout << std::endl << "==============================" << std::endl;

        selection = getInput();

        if (selection == '1')
        {
            postfix = InfixToPostfix();
            if (!PostfixAvailable)
            {
                PostfixAvailable = true;
            }
        }

        else if (selection == '2')
        {
            if (PostfixAvailable)
            {
                EvaluatePostfix(postfix);
            }
            else
            {
                std::cout << std::endl << "Postfix expression unavailable, press <1> to convert your infix expression to postfix." << std::endl;
            }
        }
        else if (selection == '3')
        {
            std::cout << std::endl << "Bye!" << std::endl;
        }
        else
        {
            std::cout << std::endl << "Your shit is getting skipped.!" << std::endl;
        }

    } while(selection != '3');

    return 0;
}
