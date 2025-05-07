#include <iostream>
#include <vector>
#include "Hash.h"
using namespace std;

int main() {
    HashTable ht;
    vector<int> keys = {27, 18, 29, 28, 39, 13, 16};

    cout << "Inserting keys: ";
    for (int k : keys) cout << k << " ";
    cout << "\n\n";

    for (int key : keys) {
        ht.insert(key);
    }

    ht.display();

    int searchKey;
    cout << "Enter a key to search: ";
    cin >> searchKey;

    if (ht.search(searchKey))
        cout << "Key " << searchKey << " found in the table.\n";
    else
        cout << "Key " << searchKey << " not found in the table.\n";

    return 0;
}
