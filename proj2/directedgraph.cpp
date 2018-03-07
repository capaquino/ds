#include "directedgraph.hpp"

#include <queue>
#include <climits> // INT_MAX
#include <iostream>
#include <algorithm>

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
    for ( Vertex v : _verteces)
    {
        //for ( VertexCostPair vcp : v.adjacentVerteces)
        //{
        //
        //}
        std::cout << v.known << " " << v.dist << std::endl;
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
