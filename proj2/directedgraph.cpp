#include "directedgraph.hpp"

#include <queue>
#include <climits> // INT_MAX

void DirectedGraph::AddVertex()
{
    _verteces.push_back(Vertex()); // vertex might need to be identifiable.
}

void DirectedGraph::AddEdge(int vi, int vj, int wij)
{
    // vi-1 vj-1 wij because of indexing and project requirement.

    // Update vi with vj
    Vertex* p_vj = &(_verteces.at(vj-1)); // pointer to vertex
    VertexCostPair to_vj {p_vj, wij}; // pointer to vertex cost pair
    _verteces.at(vi-1).adjacentVerteces.push_back(to_vj);

    // Update vj with vi
    Vertex* p_vi = &(_verteces.at(vi-1)); // pointer to vertex
    VertexCostPair to_vi {p_vi, wij}; // pointer to vertex cost pair
    _verteces.at(vj-1).adjacentVerteces.push_back(to_vi);
}

int DirectedGraph::GetVerteces()
{
    return _verteces.size();
}

int DirectedGraph::GetEdges()
{
    return _edges;
}
/*
void Graph::printPath( Vertex v )
{
    if( v.path != NOT_A_VERTEX )
    {
        printPath( v.path );
        cout << " to ";
    }
cout << v; }
*/
void DirectedGraph::PrintPath(Vertex v)
{
}

/*
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

void DirectedGraph::ShortestPath(Vertex s)
{
    for (Vertex v : _verteces)
    {
        v.dist = INT_MAX;
        v.known = false;
    }

    s.dist = 0;

    for (Vertex v : _verteces)
    {

    }

}
