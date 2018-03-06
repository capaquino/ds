#pragma once

#include <utility>

#include "vertex.hpp"

class Edge
{
public:
    const std::pair<Vertex, Vertex> _verteces;
    const unsigned weight;
    Edge(Vertex v1, Vertex v2, unsigned w);
};
