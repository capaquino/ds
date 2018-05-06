/*******************************************************************************
 *
 * Nathan Dornback
 * nad46@zips.uakron.edu
 * 2823648
 *
 *  Code found in WeightedGraph::Prims(int source), and InitPrims()
 *  references an article written by Shubham Agrawal found at
 *  https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/
 *
 *  Code found in WeightedGraph::DFT(int source) references the pseudocode
 *  found at https://en.wikipedia.org/wiki/Depth-first_search#Pseudocode
 *
 ******************************************************************************/

#ifndef HEADER_H
#define HEADER_H

#include <vector>
#include <queue>
#include <list>
#include <climits>
#include <stack>

typedef std::pair<int,int> WeightVertexPair;

class WeightedGraph
{
public:
    WeightedGraph(int v) : numVerteces(v)
    {
        // allocates memory for adjacency list
        adjacencyList = new std::list<WeightVertexPair>[v];
        // Initialize members for both algorithms
        InitPrims();
        InitDFT();
    }

    void AddEdge(int vi, int vj, int wij)
    {
        // Graphs in the book have verteces starting at 1.
        // Adjust to 0 for vector indexing.
        vi--;
        vj--;

        // Graph is undirected so edges have to be in both adjacency lists.
        adjacencyList[vi].push_back(WeightVertexPair(wij, vj));
        adjacencyList[vj].push_back(WeightVertexPair(wij, vi));
    }

    void Prims(int source)
    {
        // Graphs in the book have verteces start at 1.
        // Adjust to 0 for vector indexing.
        source--;

        // Other Requirements:
        // 1. Use a linked adjacency list to represent the graph.
        // --> 2. Use a priority queue
        std::priority_queue
        <
            WeightVertexPair,
            std::vector<WeightVertexPair>,
            std::greater<WeightVertexPair>
        > queue;

        // Start the queue with the source vertex.
        queue.push(WeightVertexPair(0, source));

        // Cost from the source to itself is 0, reflect that in weight vector.
        weightOf[source] = 0;

        // Keep going until the priority queue is empty.
        while (!queue.empty())
        {
            // Remember vertex is the second of the WeightVertexPair pair.
            int currentVertex = queue.top().second;
            queue.pop();

            // Include the dequeued vertex in the MST.
            known[currentVertex] = true;

            // Couldn't really figure out a way to do this without iterators.
            // Also tried a range-based for loop, but also ran into problems.
            // Maybe could've done this with a vector? Project requirements
            // want a std::list for the adjacency list though.
            for (auto i = adjacencyList[currentVertex].begin(); i != adjacencyList[currentVertex].end(); i++)
            {
                // int w = adjacencyList[currentVertex].get<???>().first;
                // int v = adjacencyList[currentVertex].get<???>().second;
                int w = (*i).first;
                int v = (*i).second;

                // Update the MST if this path to v is better.
                if (!known[v] && weightOf[v] > w)
                {
                    weightOf[v] = w;
                    queue.push(WeightVertexPair(weightOf[v], v));
                    parentVertexOf[v] = currentVertex;
                }
            }
        }

        // This prints out the MST. Notice we start at 1 otherwise it will attempt
        // to print the parent node of the source, which does not exist and would
        // return INT_MAX.
        for (int i = 1; i < numVerteces; i++)
        {
            std::cout << parentVertexOf[i]+1 << " to " << i+1 << " costs " << weightOf[i]
            << std::endl;
        }
    }

    // Something is still a bit wrong here.
    void DFT(int source)
    {
        // Graphs in the book have verteces starting at 1.
        // Adjust to 0 for vector indexing.
        source--;

        std::stack<int> stack;
        stack.push(source);

        // Keep going until the stack is empty
        while (!stack.empty())
        {
            // Pop and print the top of the stack.
            int v = stack.top();
            stack.pop();
            std::cout << v+1 << " to ";

            // If we haven't already been there, go into that vertex's adjacency
            // list and push all of those verteces onto the stack.
            if (!visited[v])
            {
                visited[v] = true;

                // Again, iterators.
                for (auto i = adjacencyList[v].begin(); i != adjacencyList[v].end(); i++)
                {
                    stack.push((*i).second);
                }
            }
        }
    }

private:
    // Other Requirements:
    // --> 1. Use a linked adjacency list to represent the graph.
    // 2. Use a priority queue
    std::list<WeightVertexPair> *adjacencyList;

    int numVerteces;

    // Members needed for Prim's
    std::vector<bool> known;
    std::vector<int> weightOf;
    std::vector<int> parentVertexOf;

    // Members needed for DFT
    bool *visited;

    // Initialization functions. Get rid of these? Kind've microcontroller-esque
    void InitPrims()
    {
        weightOf = std::vector<int>(numVerteces, INT_MAX);
        parentVertexOf = std::vector<int>(numVerteces, INT_MAX);
        known = std::vector<bool>(numVerteces, false);
    }

    void InitDFT()
    {
        visited = new bool[numVerteces];
        for (int i=0; i < numVerteces; i++)
        {
            visited[i] = false;
        }
    }
};

#endif
