#include <iostream>
#include <fstream>
#include <string>

#include "directedgraph.hpp"

int main()
{
    bool f_input_read = false;
    std::string input;
    char selection;
    DirectedGraph dg;
    int V, E;

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
            input >> V >> E;
            std::cout << "V: " << V << std::endl;
            std::cout << "E: " << E << std::endl;

            for (int i = 0; i < V; i++)
            {
                dg.AddVertex();
            }

            for (int i = 0; i < E; i++)
            {
                int Vi, Vj, Wij;
                input >> Vi >> Vj >> Wij;
                dg.AddEdge(Vi, Vj, Wij);
            }

            input.close();
            f_input_read = true;
        }

        else if (selection == '2')
        {
            if (f_input_read == true)
            {
                dg.ShortestPath(1); //TODO: Prompt instead of fixed
                // Source for shortest paths
                // Prompt to enter a source vertex denoted by an integer in the
                // range of 1 to V (the vertex with the highest number)

                // Print
                for (int i=1; i<=V; i++)
                {
                    std::cout << std::endl;
                    dg.PrintPath(i);
                }
                std::cout << std::endl << std::endl;
                dg.PrintVerteces();
            }

            else
            {
                std::cout << "Input file not read.";
            }


        }
        else if (selection == '3')
        {
            std::cout << std::endl << "Not implemented yet." << std::endl;
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
