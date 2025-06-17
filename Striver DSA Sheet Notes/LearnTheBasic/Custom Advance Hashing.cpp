#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---------- STRING HASHING: POLYNOMIAL ROLLING HASH ----------
unsigned long long stringHash(string s, int base = 31, int mod = 1e9 + 9) {
    unsigned long long hash = 0, pow = 1;
    for (char c : s) {
        hash = (hash + (c - 'a' + 1) * pow) % mod;
        pow = (pow * base) % mod;
    }
    return hash;
}

// ---------- GENERIC HASH TABLE USING OPEN ADDRESSING (LINEAR PROBING) ----------
template<typename K, typename V>
class OpenAddressingHashTable {
private:
    struct Entry {
        K key;
        V value;
        bool occupied;
        bool deleted;
        Entry() : occupied(false), deleted(false) {}
    };

    vector<Entry> table;
    int capacity, size;
    const double loadFactor = 0.6;

    int hash(K key) {
        return static_cast<int>(key) % capacity;
    }

    void rehash() {
        int oldCap = capacity;
        capacity *= 2;
        vector<Entry> oldTable = table;
        table = vector<Entry>(capacity);
        size = 0;

        for (auto& entry : oldTable) {
            if (entry.occupied && !entry.deleted) {
                insert(entry.key, entry.value);
            }
        }
    }

public:
    OpenAddressingHashTable(int cap = 8) : capacity(cap), size(0) {
        table = vector<Entry>(capacity);
    }

    void insert(K key, V value) {
        if ((double)size / capacity > loadFactor) {
            rehash();
        }
        int idx = hash(key);
        while (table[idx].occupied && !table[idx].deleted && table[idx].key != key) {
            idx = (idx + 1) % capacity;
        }
        if (!table[idx].occupied || table[idx].deleted) size++;
        table[idx].key = key;
        table[idx].value = value;
        table[idx].occupied = true;
        table[idx].deleted = false;
    }

    bool search(K key, V& result) {
        int idx = hash(key);
        int start = idx;
        while (table[idx].occupied) {
            if (!table[idx].deleted && table[idx].key == key) {
                result = table[idx].value;
                return true;
            }
            idx = (idx + 1) % capacity;
            if (idx == start) break;
        }
        return false;
    }

    void remove(K key) {
        int idx = hash(key);
        int start = idx;
        while (table[idx].occupied) {
            if (!table[idx].deleted && table[idx].key == key) {
                table[idx].deleted = true;
                size--;
                return;
            }
            idx = (idx + 1) % capacity;
            if (idx == start) break;
        }
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            if (table[i].occupied && !table[i].deleted) {
                cout << i << ": (" << table[i].key << ", " << table[i].value << ")\n";
            } else {
                cout << i << ": Empty\n";
            }
        }
    }
};

// ---------- DEMO USAGE ----------
int main() {
    // Integer keys
    OpenAddressingHashTable<int, string> hashTable;
    hashTable.insert(1, "One");
    hashTable.insert(9, "Nine");
    hashTable.insert(17, "Seventeen");
    hashTable.insert(25, "Twenty Five");

    cout << "Integer Key Hash Table:\n";
    hashTable.display();

    string result;
    if (hashTable.search(9, result))
        cout << "Key 9 found with value: " << result << "\n";
    else
        cout << "Key 9 not found\n";

    hashTable.remove(9);
    cout << "After removing key 9:\n";
    hashTable.display();

    // String hash demo
    cout << "\nPolynomial Rolling Hash of 'hello': " << stringHash("hello") << "\n";

    return 0;
}
