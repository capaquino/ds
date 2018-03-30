#include <iostream>
//#include <fstream>
#include <climits>

#include "316p3.h"

LinearHashTable::LinearHashTable(int s) : tableSize(s), collisions(0) {}

bool LinearHashTable::hash(int key)
{
    int hash = key % tableSize;
    if (!willCollide(hash))
    {
        hashList.push_back(hash);
    }
    else
    {
        int start = hash;
        while (willCollide(hash))
        {
            collisions += 1; // collisions count for each linear probe too
            hash += 1;
            if (hash > tableSize) // loop to beginning
            {
                hash = 0;
            }
            if (hash == start) // gone through entire hash table
            {
                return false; // table full, could not hash
            }
        }
        hashList.push_back(hash);
    }
    return true;
}

bool LinearHashTable::willCollide(int hash)
{
    for (int h : hashList)
    {
        if (h == hash)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    LinearHashTable table = LinearHashTable(10000);

    for (int i = 0; i < 1000; i++)
    {
        if (!table.hash(rand() % INT_MAX))
        {
            std::cout << "Table full!" << std::endl;
            break;
        }
    }

    std::cout << "Collisions: " << table.getCollisions() << std::endl;
    std::cout << "Hashes Used: " << table.getHashesUsed() << std::endl;

    //input.close();
    return 0;
}

/* input file stuff
int key;
while (input >> key)
{
    table.hash(key);
}
*/
