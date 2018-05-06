#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
// ^ main() includes

#include "3648_316p4.h"

/*****************************************************************************
 *
 * Nathan Dornback
 * nad46@zips.uakron.edu
 * 2823648
 *
 * The graph found in cs316p4.txt is the textual representation of Figure 9.50
 * found in the book. Running Prims() with source equal to 1 should result in
 * exactly the spanning tree found in Figures 9.50-9.51.
 *
 * Additionally, cs316p4.txt also has an initial line containing the number
 * of verteces and edges present in the graph.
 *
 *****************************************************************************/

int main()
{
    // Read input file
    std::ifstream fileInput;
    fileInput.open("cs316p4.txt");
    if (!fileInput)
    {
        std::cout << "Failed to open \"cs316pr4.txt\" file or not found."
        << std::endl;
        exit(1);
    }

    // Get verteces and edges, which are the first two values.
    int V, E;
    fileInput >> V >> E;

    //printf("V: %d\nE: %d\n\n", V, E);
    std::cout << "V: " << V << std::endl << "E: " << E << std::endl;

    auto wg = WeightedGraph(V);

    for (int i = 0; i < E; i++)
    {
        int Vi, Vj, Wij;
        fileInput >> Vi >> Vj >> Wij;
        //printf("%d to %d costs %d\n", Vi, Vj, Wij);
        std::cout << Vi << " to " << Vj << " costs " << Wij << std::endl;
        wg.AddEdge(Vi, Vj, Wij);
    }

    fileInput.close();

    // Display menu
    std::string keyboardInput;
    char selection;

    do {
        std::cout << std::endl << "============= Menu =============";
        std::cout << std::endl;
        std::cout << std::endl << " (1) Print MST starting at an arbitrary vertex.";
        std::cout << std::endl << " (2) Print DFT order starting at an arbitrary vertex.";
        std::cout << std::endl << " (3) Quit.";
        std::cout << std::endl;
        std::cout << std::endl << "================================";
        std::cout << std::endl << "Enter a selection and press <enter>.";
        std::cout << std::endl << "> ";

        getline(std::cin, keyboardInput);
        selection = keyboardInput.at(0);

        if (selection == '1')
        {
            std::cout << "Please enter a starting vertex\n> ";
            std::string input;
            getline(std::cin, input);
            int startingVertex;
            std::stringstream(input) >> startingVertex;
            std::cout << "* * * Prim's algorithm creates the following MST * * *\n\n";
            wg.Prims(startingVertex);
            std::cout << "\nPress <enter> to display the menu again.\n";
            getline(std::cin, input);
        }
        else if (selection == '2')
        {
            std::cout << "Please enter a starting vertex\n> ";
            std::string input;
            getline(std::cin, input);
            int startingVertex;
            std::stringstream(input) >> startingVertex;
            std::cout << "* * * The DFT algorithm traverses our tree as follows * * *\n\n";
            wg.DFT(startingVertex);
            std::cout << "\n\nPress <enter> to display the menu again.\n";
            getline(std::cin, input);
        }
        else if (selection == '3')
        {
            std::cout << std::endl << "Exiting..." << std::endl;
        }
        else
        {
            std::cout << std::endl << "Invalid selection, enter <1>, <2>, "
            "or <3>, then press <enter>." << std::endl;
        }

    } while(selection != '3');

    return 0;
}
