#include <iostream>
#include <iomanip>
#include <climits>

#include "316p3.h"

/* LinearHashTable methods */
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
            collisions += 1; // collisions count for each linear probe too?
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

/* QuadraticHashTable methods */
QuadraticHashTable::QuadraticHashTable(int s) : tableSize(s), collisions(0) {}

bool QuadraticHashTable::hash(int key)
{
    int hash = key % tableSize;
    if (!willCollide(hash))
    {
        hashList.push_back(hash);
    }
    else
    {
        int start = hash;
        int base = 2;
        int power = 0;
        while (willCollide(hash))
        {
            collisions += 1; // collisions count for each linear probe too?
            hash = start;
            hash += base ^ power;
            power += 1;
            // should be if or while... depends on failure condition
            while (hash > tableSize) // going over table size...
            {
                hash -= tableSize;
            }
            /*
            if (hash == start) // quadratic now is greater than start...
            {
                return false; // whats the failure condition for quadratic???
            }
            */
        }
        hashList.push_back(hash);
    }
    return true;
}

bool QuadraticHashTable::willCollide(int hash)
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

/* Program */
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    // might need to generate ints and put to a file to be used by all hashing
    // functions so the results are comparable...

    /* Output table formatting */
    const int firstColWidth = 14;
    const int numColWidth = 8;
    std::cout << std::left << std::setw(firstColWidth) << "Size: ";
    for (int input_size = 1000; input_size <= 10000; input_size += 1000)
    {
        std::cout << std::left << std::setw(numColWidth) << input_size;
    }
    std::cout << std::endl;

    /* Linear Probing */
    std::cout << std::left << std::setw(firstColWidth) << "Linear: ";

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
        std::cout << std::left << std::setw(numColWidth) << table.getCollisions();
    }
    std::cout << std::endl;

    /* Quadratic Hashing */
    std::cout << std::left << std::setw(firstColWidth) << "Quadratic: ";

    for (int input_size = 1000; input_size <= 9000; input_size += 1000)
    {
        QuadraticHashTable table = QuadraticHashTable(10000);

        for (int i = 0; i < input_size; i++)
        {
            if (!table.hash(rand() % INT_MAX))
            {
                std::cout << "Table full!" << std::endl;
                break;
            }
        }
        std::cout << std::left << std::setw(numColWidth) << table.getCollisions();
    }
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
