#include <iostream>
#include <fstream>
#include <string>
#include <climits> // INT_MAX
#include "3648_316p2.h"
//#include <cstdlib>

bool CharIsNumeric(char c)
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool StringIsNumeric(std::string s)
{
    for (const char c : s)
    {
        if (!CharIsNumeric(c))
        {
            return false;
        }
    }
    return true;
}


void DirectedGraph::AddVertex()
{
    _verteces.push_back(Vertex()); // vertex might need to be identifiable.
}

void DirectedGraph::AddEdge(int vi, int vj, int wij)
{
    // vi-1 vj-1 wij because of indexing and project requirement.

    // Update vi with vj
    Vertex* p_vj = &(_verteces.at(vj-1)); // pointer to vertex
    VertexCostPair to_vj {p_vj, wij}; // p_vertex, cost pair
    _verteces.at(vi-1).adjacentVerteces.push_back(to_vj); // update adjacency list
}

void DirectedGraph::PrintVerteces()
{
    for ( int i=0; i < _verteces.size(); i++)
    {
        std::cout << "Node " << i+1 << " has distance to source: " << _verteces.at(i).dist << std::endl;
    }
}

int DirectedGraph::GetVertexIndex(Vertex v)
{
    //return std::find(_verteces.begin(), _verteces.end(), v) - _verteces.begin();
    //for (auto it = _verteces.begin(); *it != v;
    for (int i = 0; i < _verteces.size(); i++)
    {
        if (_verteces.at(i) == v)
            return i+1;
    }
    return -1;

}

/* BOOK PSEUDOCODE
void Graph::printPath( Vertex v )
{
    if( v.path != NOT_A_VERTEX )
    {
        printPath( v.path );
        cout << " to ";
    }
cout << v; }
*/

void DirectedGraph::PrintPath(int vertexIndex)
{
    Vertex v = _verteces.at(vertexIndex-1); //getting copied

    if (v.path != NULL)
    {
        PrintPath(GetVertexIndex(*v.path));
        std::cout << " to ";
    }
    std::cout << vertexIndex;
}


/* BOOK PSEUDOCODE
void Graph::dijkstra( Vertex s )
{
    for each Vertex v
    {
        v.dist = INFINITY;
        v.known = false;
    }
    s.dist = 0;

    while( there is an unknown distance vertex )
    {
        Vertex v = smallest unknown distance vertex;
        v.known = true;
        for each Vertex w adjacent to v
            if( !w.known )
            {
                DistType cvw = cost of edge from v to w;
                if( v.dist + cvw < w.dist )
                {
                    // Update w
                    decrease( w.dist to v.dist + cvw );
                    w.path = v;
} } } }
*/



void DirectedGraph::ShortestPath(int sourceIndex)
{
    for (Vertex &v : _verteces)
    {
        v.dist = INT_MAX; // could do this in initializer list
        v.known = false; // default init'd to false anyway
    }

    _verteces.at(sourceIndex-1).dist = 0;

    // this for-loop is wrong if the source index is not 1.
    for (Vertex &v : _verteces) // this includes the source
    {
        if (!v.known)
        {
            v.known = true;

            // w.first == *Vertex
            // w.second == cost to w.first
            for ( VertexCostPair w : v.adjacentVerteces) //getting copied, but okay since w has pointer
            {
                // if (!w.first->known)
                if (v.dist + w.second < w.first->dist)
                {
                    w.first->dist = v.dist + w.second;
                    w.first->path = &v;
                }
            }
        }
    }
}


// Having a cycle causes program to seg fault 11
// -- Might not be a cycle, but just any node that points to source

// Removing edge that causes cycle solves problem, but now we see that any
// vertex that is sealed (does not point anywhere) has its path printed fine
// but its distance is still infinite. The update to dist must be getting
// missed.

// w.known is not being checked, and it is in the book pseudo code, but doing so
// seems to break things.
// -- if w.known is checked it shouldnt matter if there is a cycle cause it will
//    ignore known verteces.


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
            std::string fileInput;

            std::cout << "Enter the name of the file describing the graph, then press <enter>." << std::endl << "> ";
            getline(std::cin, fileInput);

            std::ifstream graphFile;
            graphFile.open(fileInput);

            if (!graphFile)
            {
                std::cout << "Failed to open input file or input file not found."
                << std::endl;
                exit(1);
            }

            // Get verteces and edges, which are the first two values.
            graphFile >> V >> E;
            std::cout << "V: " << V << std::endl;
            std::cout << "E: " << E << std::endl;

            for (int i = 0; i < V; i++)
            {
                dg.AddVertex();
            }

            for (int i = 0; i < E; i++)
            {
                int Vi, Vj, Wij;
                graphFile >> Vi >> Vj >> Wij;
                dg.AddEdge(Vi, Vj, Wij);
            }

            graphFile.close();
            f_input_read = true;
        }

        else if (selection == '2')
        {
            if (f_input_read == true)
            {
                // Source for shortest paths
                // Prompt to enter a source vertex denoted by an integer in the
                // range of 1 to V (the vertex with the highest number)
                std::string sourceSelectedInput;
                std::cout << "Identify the source node out of nodes 1 to V." << std::endl << "> ";
                getline(std::cin, sourceSelectedInput);

                if (StringIsNumeric(sourceSelectedInput))
                {
                    int source = atoi(sourceSelectedInput.c_str());
                    if (source < V && source > 0)
                    {
                        dg.ShortestPath(source); // this is actually going to be wrong if the source is not "1".

                        // Print
                        for (int i=1; i<=V; i++)
                        {
                            std::cout << std::endl;
                            dg.PrintPath(source);
                        }
                        std::cout << std::endl << std::endl;
                        dg.PrintVerteces();
                    }
                    else
                    {
                        std::cout << std::endl << "Node entered does not exist." << std::endl;
                        exit(1);
                    }
                }
                else
                {
                    std::cout << std::endl << "Invalid input. Node selection must be a number from 1 to V." << std::endl;
                    exit(1);
                }
            }
            else
            {
                std::cout << "Input file not yet read.";
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
