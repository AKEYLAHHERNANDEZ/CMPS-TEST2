#include <iostream>
#include <vector>
#include "Hash.h"
using namespace std;

int main() {
    HashTable ht;

    // Keys to insert into the hash table
    vector<int> keys = {21, 18, 29, 47, 39, 13, 87};

    cout << "Inserting keys: ";
    for (int k : keys) cout << k << " ";
    cout << "\n\n";

    // Insert each key into the table
    for (int key : keys) {
        ht.insert(key);
    }

    // Display final hash table 
    ht.display();

    // Search for a key entered by the user
    int searchKey;
    cout << "Enter a key to search: ";
    cin >> searchKey;

    if (ht.search(searchKey))
        cout << "Key " << searchKey << " found in the table.\n";
    else
        cout << "Key " << searchKey << " not found in the table.\n";

    return 0;
}
