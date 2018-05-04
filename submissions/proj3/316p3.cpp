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
            collisions++; // collisions count for each secondary collision too
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
QuadraticHashTable::QuadraticHashTable(int s) : tableSize(s), collisions(0), failures(0) {}

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
            collisions++;
            hash = start;
            hash += base ^ power;
            power += 1;

            if (hash > tableSize) // go back to beginning
            {
                hash -= tableSize;
            }

            if (hash >= start) // have looped past where we started at
            {
                failures++;
                return false;
            }
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

/* DoubleHashTable methods */
DoubleHashTable::DoubleHashTable(int s) : tableSize(s), collisions(0), failures(0) {}

bool DoubleHashTable::hash(int key)
{
    int hash = key % tableSize;
    if (!willCollide(hash))
    {
        hashList.push_back(hash);
    }
    else
    {
        collisions++;
        int doubleHash = hash % 11; // the second hashing function
        if (!willCollide(doubleHash))
        {
            hashList.push_back(doubleHash);
        }
        else
        {
            failures++;
            return false; // failure to hash, this is tallied in main()
        }
    }
    return true;
}

bool DoubleHashTable::willCollide(int hash)
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

////////////////////////////////////////////////////////////////////////////////


/* Program */
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    // might need to generate ints and put to a file to be used by all hashing
    // functions so the results are comparable...

    /* Output table formatting */
    // Some of these weren't needed
    const int firstColWidth = 14;
    const int sizeWidth = 14;
    const int linearWidth = 14;
    const int quadDoubleWidth = 7;
    const int failureWidth = 7;

    std::cout << "A few notes..." << std::endl;
    std::cout << "Linear collisions also include secondary collisions from probing." << std::endl;
    std::cout << "The \" # ( # )\" notation for Quadratic and Double indicates hashing failures. " << std::endl;
    std::cout << "This is instead of having two separate rows at the bottom as in the assignment sheet." << std::endl;
    std::cout << "This was done to avoid a large last-minute rework of code in main()." << std::endl << std::endl;

    std::cout << std::left << std::setw(firstColWidth) << "Size: ";
    for (int input_size = 1000; input_size <= 10000; input_size += 1000)
    {
        std::cout << std::left << std::setw(sizeWidth) << input_size;
    }
    std::cout << std::endl;

    /* Linear Probing */
    std::cout << std::left << std::setw(firstColWidth) << "Linear: ";

    for (int input_size = 1000; input_size <= 10000; input_size += 1000)
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
        std::cout << std::left << std::setw(linearWidth) << table.getCollisions();
    }
    std::cout << std::endl;

    /* Quadratic Hashing */
    int QuadraticFailures = 0;

    std::cout << std::left << std::setw(firstColWidth) << "Quadratic: ";

    for (int input_size = 1000; input_size <= 10000; input_size += 1000)
    {
        QuadraticHashTable table = QuadraticHashTable(10000);

        for (int i = 0; i < input_size; i++)
        {
            table.hash(rand() % INT_MAX);
        }
        std::cout
        << std::left << std::setw(5) << table.getCollisions()
        << std::left << std::setw(1) << "("
        << std::left << std::setw(4) << table.getFailures()
        << std::left << std::setw(4) << ")";
    }
    std::cout << std::endl;

    /* Double Hashing */
    int DoubleFailures = 0;

    std::cout << std::left << std::setw(firstColWidth) << "Double: ";

    for (int input_size = 1000; input_size <= 10000; input_size += 1000)
    {
        DoubleHashTable table = DoubleHashTable(10000);

        for (int i = 0; i < input_size; i++)
        {
            table.hash(rand() % INT_MAX);
        }
        std::cout
        << std::left << std::setw(5) << table.getCollisions()
        << std::left << std::setw(1) << "("
        << std::left << std::setw(4) << table.getFailures()
        << std::left << std::setw(4) << ")";
    }
    std::cout << std::endl;

    return 0;
}
