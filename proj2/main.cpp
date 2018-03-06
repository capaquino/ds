#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // bool f_some_flag = false;
    std::string input;
    char selection;

    do {
        std::cout << std::endl << "============= Menu =============";
        std::cout << std::endl;
        std::cout << std::endl << " (1) Open input files.          ";
        std::cout << std::endl << " (2) Source for shortest paths. ";
        std::cout << std::endl << " (3) Paths from A to B          ";
        std::cout << std::endl << " (4) Exit                       ";
        std::cout << std::endl;
        std::cout << std::endl << "================================";
        std::cout << std::endl << "Enter a selection and press <enter>.";
        std::cout << std::endl << "> ";

        getline(std::cin, input);
        selection = input.at(0);

        if (selection == '1')
        {
            std::ifstream input;
            input.open("input"); //TODO: Prompt for file name.
            if (!input)
            {
                std::cout << "Failed to open input file or input file not found."
                << std::endl;
                exit(1);
            }

            // Get verteces and edges, which are the first two values.
            unsigned V, E;
            input >> V >> E;
            std::cout << "V: " << V << std::endl;
            std::cout << "E: " << E << std::endl;

            // DiGraph digraph = DiGraph();
            for (int i = 0; i < V; i++)
            {
                // digraph.AddVertex(i+1); // this function could be smart and
                // add verteces starting at 1...
            }

            for (int i = 0; i < E; i++)
            {
                int Vi, Vj, Wij; // First vertex, Second vertex, edge weight.
                input >> Vi >> Vj >> Wij;
                // digraph.AddEdge(Vi, Vj, Wij);
            }

            input.close();
        }

        else if (selection == '2')
        {
            // Source for shortest paths
            // Prompt to enter a source vertex denoted by an integer in the
            // range of 1 to V (the vertex with the highest number)
        }
        else if (selection == '3')
        {

        }
        else if (selection == '4')
        {
            std::cout << std::endl << "Exiting..." << std::endl;
        }
        else
        {
            std::cout << std::endl << "Invalid selection, enter <1>, <2>, <3> "
            "or <4>, then press <enter>." << std::endl;
        }

    } while(selection != '4');

    return 0;
}
