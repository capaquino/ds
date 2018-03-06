#include "directedgraph.hpp"

#include <queue>

void DirectedGraph::AddVertex(unsigned vid)
{
    verteces.push_back(Vertex(vid));
}

void DirectedGraph::AddEdge(unsigned vi, unsigned vj, unsigned wij)
{
    edges.push_back(Edge(vi, vj, wij));
}

int DirectedGraph::GetVerteces()
{
    return verteces.size();
}

int DirectedGraph::GetEdges()
{
    return edges.size();
}

void DirectedGraph::ShortestPath(Vertex source)
{
    


    #if 0
    std::vector<unsigned> dist {verteces.size()}; // watch out here

    std::priority_queue<DistVertexPair, std::vector<DistVertexPair>,
        std::greater<DistVertexPair>> priorityQueue;

    dist[source] = 0;
    priorityQueue.push(DistVertexPair {0, source});

    while (!priorityQueue.empty())
    {
        unsigned u = priorityQueue.top().second;
        priorityQueue.pop();


    }
    #endif

}


/*
void Graph::unweighted( Vertex s )
{
    Queue<Vertex> q;
    for each Vertex v
        v.dist = INFINITY;
    s.dist = 0;
    q.enqueue( s );
    while( !q.isEmpty( ) )
    {
        Vertex v = q.dequeue( );
        for each Vertex w adjacent to v
            if( w.dist == INFINITY )
            {
} }
}
*/
