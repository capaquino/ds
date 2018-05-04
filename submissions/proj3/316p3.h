#include <vector>

class LinearHashTable
{
private:
    int tableSize;
    int collisions;
    std::vector<int> hashList;

public:
    LinearHashTable(int s);
    bool hash(int key);
    bool willCollide(int hash);
    int getCollisions() { return collisions; }
    int getHashesUsed() { return hashList.size(); } // debug
};

class QuadraticHashTable
{
private:
    int tableSize;
    int collisions;
    int failures;
    std::vector<int> hashList;

public:
    QuadraticHashTable(int s);
    bool hash(int key);
    bool willCollide(int hash);
    int getCollisions() { return collisions; }
    int getFailures() { return failures; }
    int getHashesUsed() { return hashList.size(); } // debug
};

class DoubleHashTable
{
private:
    int tableSize;
    int collisions;
    int failures;
    std::vector<int> hashList;

public:
    DoubleHashTable(int s);
    bool hash(int key);
    bool willCollide(int hash);
    int getCollisions() { return collisions; }
    int getFailures() { return failures; }
    int getHashesUsed() { return hashList.size(); } // debug
};
