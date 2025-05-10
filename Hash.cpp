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
    int originalIndex = index;
    int probes = 0;

    while (table[index] != -1) {
        cout << "Collision at index " << index << " for key " << key << endl;
        index = (index + 1) % TABLE_SIZE;
        probes++;

        if (index == originalIndex) {
            cout << "Hash table is full. Cannot insert key " << key << ".\n";
            return;
        }
    }

    table[index] = key;

    if (probes == 0) {
        cout << "Inserted key " << key << " at index " << index << endl;
    } else {
    cout << "Inserted key " << key << " at index " << index << " after " << probes << " probe" << (probes > 1 ? "s" : "") << endl;
    }
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
