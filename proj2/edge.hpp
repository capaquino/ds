#pragma once

#include "vertex.hpp"

class Edge
{
public:
    const Vertex source;
    const Vertex destination;
    const unsigned weight;
    Edge(Vertex v1, Vertex v2, unsigned w);
};
