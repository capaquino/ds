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
    int getHashesUsed() { return hashList.size(); }
};
