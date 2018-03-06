#pragma once

class Vertex
{
private:
    bool _visited;
public:
    const unsigned Id;
    void SetVisited(); // you should not be able to change it back once set.
    void GetVisited();
    Vertex(unsigned identifier);
};
