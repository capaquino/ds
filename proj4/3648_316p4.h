#ifndef HEADER_H
#define HEADER_H

#include <vector>
#include <queue>
#include <list>
#include <climits>
#include <stack>

typedef std::pair<int,int> Edge;
typedef std::pair<int,int> WeightVertexPair;
typedef std::pair<int,int> VertexWeightPair;

class WeightedGraph
{
public:
    WeightedGraph(int v) : V(v)
    {
        // allocates memory for adjacency list
        adj = new std::list<Edge>[v];
        InitPrims();
        InitDFT();
    }

    void AddEdge(int vi, int vj, int wij)
    {
        // Graphs in the book have verteces start at 1.
        // Adjust to 0 for vector indexing.
        vi--;
        vj--;
        // Graph is undirected so edges have to be in both adjacency lists.
        adj[vi].push_back(Edge(vj,wij));
        adj[vj].push_back(Edge(vi,wij));
    }

    void Prims(int src)
    {
        // Graphs in the book have verteces start at 1.
        // Adjust to 0 for vector indexing.
        src--;

        // Other Requirements:
        // 1. Use a linked adjacency list to represent the graph.
        // --> 2. Use a priority queue
        std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;

        // Start the queue with the source vertex.
        pq.push(Edge(0, src));
        key[src] = 0;

        // Run until queue is empty.
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            // Include vertex in MST
            inMST[u] = true;

            // 'i' is used to get all adjacent vertices of a vertex
            std::list< std::pair<int, int> >::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                // Get vertex label and weight of current adjacent
                // of u.
                int v = (*i).first;
                int weight = (*i).second;

                //  If v is not in MST and weight of (u,v) is smaller
                // than current key of v
                if (inMST[v] == false && key[v] > weight)
                {
                    // Updating key of v
                    key[v] = weight;
                    pq.push(std::make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }

        // Print edges of MST using parent array
        for (int i = 1; i < V; ++i)
        {
            //printf("%d to %d costs %d\n", parent[i]+1, i+1, key[i]);
            std::cout << parent[i]+1 << " to " << i+1 << " costs " << key[i]
            << std::endl;
        }
    }

    void DFT(int src)
    {
        visited[src] = true;
        std::cout << src+1 << " ";

        for (int i=0; i<V; i++)
        {
            if (!visited[i])
            {
                DFT(i);
            }
        }
    }

private:
    int V;
    std::vector<int> key;
    std::vector<int> parent;
    std::vector<bool> inMST;

    bool *visited;

    void InitPrims()
    {
        // key is the weight of the corresponding edge in <parent?>?
        key = std::vector<int>(V, INT_MAX);
        parent = std::vector<int>(V, -1);
        inMST = std::vector<bool>(V, false);
    }

    void InitDFT()
    {
        visited = new bool[V];
        for (int i=0; i < V; i++)
        {
            visited[i] = false;
        }

    }
    // Other Requirements:
    // --> 1. Use a linked adjacency list to represent the graph.
    // 2. Use a priority queue
    std::list<Edge> *adj;
};

#endif
