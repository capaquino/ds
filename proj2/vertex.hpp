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
};
