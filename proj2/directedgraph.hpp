#pragma once

#include <vector>

#include "vertex.hpp"

class DirectedGraph
{
private:
    std::vector<Vertex> _verteces;
    unsigned _edges;
public:
    void AddVertex();
    void AddEdge(int vi, int vj, int weight);
    int GetVerteces();
    int GetEdges();

    void PrintPath(Vertex v);
    void ShortestPath(Vertex s);
};
