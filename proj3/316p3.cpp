#include <iostream>
#include <iomanip>
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
        collisions += 1; // collisions count for each linear probe too?
        int start = hash;
        while (willCollide(hash))
        {
            // move collisions here... collisions += 1;
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

    /* Output table formatting */
    const int firstColWidth = 14;
    const int numColWidth = 8;
    std::cout << std::left << std::setw(firstColWidth) << "Size: ";
    for (int input_size = 1000; input_size <= 10000; input_size += 1000)
    {
        std::cout << std::left << std::setw(numColWidth) << input_size;
    }
    std::cout << std::endl;
    std::cout << std::left << std::setw(firstColWidth) << "Linear: ";

    /* Linear Probing */
    for (int input_size = 1000; input_size <= 9000; input_size += 1000)
    {
        LinearHashTable table = LinearHashTable(10000);

        for (int i = 0; i < input_size; i++)
        {
            if (!table.hash(rand() % INT_MAX))
            {
                std::cout << "Table full!" << std::endl;
                break;
            }
        }

/**/    std::cout << std::left << std::setw(numColWidth) << table.getCollisions();
    }

    std::cout << std::endl;

    /* Quadratic Hashing */
    std::cout << std::left << std::setw(firstColWidth) << "Quadratic: ";

    std::cout << std::endl;

    /* Double Hashing */
    std::cout << std::left << std::setw(firstColWidth) << "Double: ";

    std::cout << std::endl;

    //std::cout << "Hashes Used: " << table.getHashesUsed() << std::endl;
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
