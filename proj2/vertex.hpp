#pragma once

#include <vector>

class Vertex
{
private:
    bool _visited;
public:
    const unsigned Id;
    Vertex(unsigned identifier);
    std::vector<unsigned> adjacent; // dunno about this
};
