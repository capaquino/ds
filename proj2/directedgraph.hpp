#pragma once

#include <vector>

#include "vertex.hpp"

class DirectedGraph
{
private:
    std::vector<Vertex> _verteces;
    unsigned _edges;
public:
    void PrintVerteces();
    void AddVertex();
    void AddEdge(int vi, int vj, int weight);
    int GetVerteces();
    int GetEdges();
    int GetVertexIndex(Vertex v);
    void PrintPath(int vertexIndex);
    void ShortestPath(int sourceIndex);
};
