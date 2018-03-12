#pragma once

#include <vector>
#include <utility>

class Vertex;

typedef std::pair<Vertex*, int> VertexCostPair;

class Vertex
{
public:
    std::vector<VertexCostPair> adjacentVerteces;
    bool known;
    int dist;
    Vertex* path;
    bool operator==(Vertex v)
    {
        if (adjacentVerteces != v.adjacentVerteces ||
            known != v.known ||
            dist != v.dist ||
            path != v.path)
            return false;
        else
            return true;
    }
};

class DirectedGraph
{
private:
    std::vector<Vertex> _verteces;
    unsigned _edges;
public:
    void AddVertex();
    void AddEdge(int vi, int vj, int weight);
    void PrintVerteces();
    int GetVertexIndex(Vertex v);
    void PrintPath(int vertexIndex);
    void ShortestPath(int sourceIndex);
};
