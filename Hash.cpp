#include "Hash.h"
#include <iostream>
#include <iomanip>
using namespace std;

const int TABLE_SIZE = 11;
const float A = 0.6180339887;

HashTable::HashTable() {
    table.resize(TABLE_SIZE, -1);
}

int HashTable::hash(int key) {
    float fractional = (key * A) - int(key * A);
    return int(TABLE_SIZE * fractional);
}

void HashTable::insert(int key) {
    int index = hash(key);
    int startIndex = index;
    int steps = 0;

    while (table[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        steps++;

        if (index == startIndex) {
            cout << "Hash table is full. Cannot insert key " << key << ".\n";
            return;
        }
    }

    table[index] = key;
    cout << "Inserted key " << key << " at index " << index;
    if (steps > 0) cout << " (after " << steps << " probe" << (steps > 1 ? "s" : "") << ")";
    cout << endl;
}

void HashTable::display() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << setw(2) << i << ": ";
        if (table[i] == -1) cout << "[ ]";
        else cout << "[" << table[i] << "]";
        cout << "\n";
    }
    cout << endl;
}

bool HashTable::search(int key) {
    int index = hash(key);
    int startIndex = index;

    while (table[index] != -1) {
        if (table[index] == key) return true;
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) break;
    }

    return false;
}
