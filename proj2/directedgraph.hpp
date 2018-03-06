#pragma once

#include <vector>
#include <utility>

#include "vertex.hpp"
#include "edge.hpp"

typedef std::pair<unsigned, Vertex> DistVertexPair;

class DirectedGraph
{
private:
    std::vector<Vertex> verteces;
    std::vector<Edge> edges;
public:
    void AddVertex(unsigned v);
    void AddEdge(unsigned vi, unsigned vj, unsigned weight);
    int GetVerteces();
    int GetEdges();


    void ShortestPath(Vertex source);
};
