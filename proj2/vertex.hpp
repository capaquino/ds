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
