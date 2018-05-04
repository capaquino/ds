#include <iostream>
#include <fstream>
#include <string>
// ^ main() includes
#include <vector>
#include <queue>
#include <list>
// ^ WeightedGraph includes

typedef std::pair<int,int> Edge;

class WeightedGraph
{
private:
    int numVerteces;
    // why cant i use a vector instead of a list here?
    std::list<Edge> *adjList;
public:
    WeightedGraph(int v) : numVerteces(v)
    {
        // allocates memory for adjaceny list
    }

    void AddEdge(int vi, int vj, int wij)
    {

    }

    void Prims()
    {

    }
};



int main()
{
    // Read input file
    std::ifstream input;
    input.open("cs316p4.txt");
    if (!input)
    {
        std::cout << "Failed to open \"cs316pr4.txt\" file or not found."
        << std::endl;
        exit(1);
    }

    // Get verteces and edges, which are the first two values.
    int V, E;
    input >> V >> E;

    // auto wg = WeightedGraph(V);

    for (int i = 0; i < E; i++)
    {
        int Vi, Vj, Wij;
        input >> Vi >> Vj >> Wij;
        //wg.AddEdge(Vi, Vj, Wij);
    }

    input.close();

    // Display menu
    std::string keyboardInput;
    char selection;

    do {
        std::cout << std::endl << "============= Menu =============";
        std::cout << std::endl;
        std::cout << std::endl << " (1) Print MST starting at an arbitrary vertex.";
        std::cout << std::endl << " (2) Print DFT starting at an arbitrary vertex.";
        std::cout << std::endl << " (3) Quit.";
        std::cout << std::endl;
        std::cout << std::endl << "================================";
        std::cout << std::endl << "Enter a selection and press <enter>.";
        std::cout << std::endl << "> ";

        getline(std::cin, keyboardInput);
        selection = keyboardInput.at(0);

        if (selection == '1')
        {
            // wg.Prims()
            std::cout << std::endl << "Not implemented yet." << std::endl;
        }

        else if (selection == '1')
        {
            // DFT
            std::cout << std::endl << "Not implemented yet." << std::endl;
        }
        else if (selection == '2')
        {
            std::cout << std::endl << "Not implemented yet." << std::endl;
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
