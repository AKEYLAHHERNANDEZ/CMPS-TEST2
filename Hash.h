#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>

class HashTable {
private:
    std::vector<int> table;
    int hash(int key);

public:
    HashTable();
    void insert(int key);
    void display();
    bool search(int key);
};
#endif
