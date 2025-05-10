#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>

// HashTable class definition
class HashTable {
private:
    std::vector<int> table;      // Vector to store hash table values
    int hash(int key);           

public:
    HashTable();                 // Constructor to initialize the table
    void insert(int key);       // Insert key into the table
    void display();             // Display the table
    bool search(int key);       // Search for a key
};

#endif
