#include "Hash.h"
#include <iostream>
#include <iomanip>
using namespace std;

const int TABLE_SIZE = 11;            // Size of the hash table
const float A = 0.6180339887;         // Constant A for multiplication hash method

//  initialize the table with empty slots
HashTable::HashTable() {
    table.resize(TABLE_SIZE, -1);
}

// Hash function using multiplication method
int HashTable::hash(int key) {
    float fractional = (key * A) - int(key * A);   // Extract fractional part
    return int(TABLE_SIZE * fractional);           // Multiply and truncate to get index
}

// Insert a key into the hash table
void HashTable::insert(int key) {
    int index = hash(key);               // Calculate initial index
    int originalIndex = index;           // Keep original to detect full cycle
    int probes = 0;                      // Count linear probes 

    // Linear probing if collision occurs
    while (table[index] != -1) {
        cout << "Collision at index " << index << " for key " << key << endl;
        index = (index + 1) % TABLE_SIZE;
        probes++;

        // If we circle back, the table is full
        if (index == originalIndex) {
            cout << "Hash table is full. Cannot insert key " << key << ".\n";
            return;
        }
    }

    table[index] = key;  // Insert the key

    // Output message with collision info
    if (probes == 0) {
        cout << "Inserted key " << key << " at index " << index << endl;
    } else {
    cout << "Inserted key " << key << " at index " << index << " after " << probes << " probe" << (probes > 1 ? "s" : "") << endl;
    }
}

// Display the hash table
void HashTable::display() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout <<"Index "<< setw(2) << i << ": ";
        if (table[i] == -1) {
            cout << "[ ]";  
        }      
        else cout << "[" << table[i] << "]";  
        cout << "\n";
    }
    cout << endl;
}

// Search for a key using linear probing
bool HashTable::search(int key) {
    int index = hash(key);
    int FIndex = index;

    // Keep probing until slot is empty or we loop back
    while (table[index] != -1) {
        if (table[index] == key) {
        return true;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == FIndex) 
        break;
    }

    return false; 
}
